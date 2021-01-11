//
// Created by erhoof on 11.01.2021.
//

#include "../../include/Core/Window.h"
#include "../../include/Core/Debug.h"
#include <GLFW/glfw3.h>
#include <glad.h>

namespace eGLE
{
    Window *Window::window() {
        if (!m_instance)
            m_instance = new Window();

        return m_instance;
    }

    void Window::init(int width, int height, const char *title)
    {
        m_width = width;
        m_height = height;
        m_title = title;

        // Prepare GLFW
        if (glfwInit()) {
            Debug::msg("GLFW - OK!");
        } else {
            Debug::halt("GLFW - Failed to Initialize");
            glfwTerminate();
        }

        // Setup GLFW (Set OpenGL 4.3)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create GLFW Window
        m_glfwWindow = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

        if (m_glfwWindow) {
            Debug::msg("GLFW Window - Created");
        } else {
            Debug::halt("GLFW Window - Failed to Create");
            glfwTerminate();
        }

        // Setup OpenGL
        glfwMakeContextCurrent(m_glfwWindow);
        glfwSetWindowSizeCallback(m_glfwWindow, resize);
        glfwSetWindowUserPointer(m_glfwWindow, this); // Set GLFW Pointer to this obj

        // Setup GLAD
        if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            // TODO: Get OGL Version to App Context

            Debug::msg("GLAD - OK!");
            Debug::msg("GLAD: got GPU with GL_VER: ", glGetString(GL_VERSION));
        } else {
            Debug::halt("GLAD  Failed to Initialize");
            glfwTerminate();
        }
    }

    bool Window::shouldClose()
    {
        return glfwWindowShouldClose(m_glfwWindow);
    }

    void Window::clear()
    {
        glClearColor(0.0f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::destroy()
    {
        glfwDestroyWindow(m_glfwWindow);
        glfwTerminate();
    }

    int Window::width() const
    {
        return m_width;
    }

    int Window::height() const
    {
        return m_height;
    }

    GLFWwindow *Window::glfwWindow()
    {
        return m_glfwWindow;
    }


    // Callbacks
    void resize(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}