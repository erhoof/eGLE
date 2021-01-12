//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Core/Core.h"
#include "../../include/Core/Debug.h"
#include "../../include/Core/RenderSystem.h"
#include "../../include/Core/InputSystem.h"
#include "../../include/Core/ApplicationContext.h"
#include "../../include/Core/Window.h"

#include <GLFW/glfw3.h>
#include <thread>

namespace eGLE
{
    int Core::m_frameRate = 0;

    Core::Core(ApplicationContext *ac, RenderSystem *rs, double frameRate) :
        m_applicationContext(ac),
        m_renderSystem(rs),
        m_window(Window::instance()),
        m_frameTime(1.0f / frameRate),
        m_isRunning(false)
    {
        Debug::msg("[Core] Instance created.");

        // Get InputSystem Ready
        InputSystem::instance();

        // Prepare RenderSystem
        m_renderSystem->prepare();
    }


    void Core::run()
    {
        // return if core is already started
        if (m_isRunning)
            return;

        m_isRunning = true;

        // ApplicationContext
        m_applicationContext->prepare();

        // Prepare frame counters
        double previousTime = glfwGetTime();
        double unprocessedTime = 0;
        double frameCount = 0;
        int framesRendered = 0;

        Debug::msg("[Core] Entering main loop...");

        // Main Loop
        while(m_isRunning) {
            bool render = false;

            // Count elapsed time to render
            double startTime = glfwGetTime();
            double elapsedTime = startTime - previousTime;
            previousTime = startTime;

            unprocessedTime += elapsedTime;
            frameCount += elapsedTime;

            // FPS Counter
            if (frameCount >= 1.0) {
                m_frameRate = framesRendered;
                framesRendered = 0;
                frameCount = 0;

                Debug::msg("FPS: ", m_frameRate);
                // TODO: out FPS count
            }

            // event handling
            while (unprocessedTime > m_frameTime) {
                render = true;

                // Check if window should close
                if (m_window->shouldClose())
                    m_isRunning = false;

                this->input((float)m_frameTime);
                this->update((float)m_frameTime);

                unprocessedTime -= m_frameTime;
            }

            // render remaining time
            if (render) {
                this->render(m_renderSystem);

                framesRendered++;
            } else {
                // wait for Sync with eventSystem
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }

        m_window->destroy();
    }

    int Core::frameRate()
    {
        return m_frameRate;
    }

    void Core::render(RenderSystem *rs)
    {
        m_applicationContext->render(m_renderSystem);

        // Flip Buffers
        m_window->render();
    }

    void Core::update(float timeDelta)
    {
        InputSystem::pollEvents();

        m_applicationContext->update(timeDelta);
    }

    void Core::input(float timeDelta)
    {
        m_applicationContext->input(timeDelta);
    }
}