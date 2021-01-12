//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Managers/InputSystem.h"
#include "../../include/Core/Window.h"
#include <GLFW/glfw3.h>

namespace eGLE
{
    InputSystem *InputSystem::m_instance = nullptr;

    InputSystem::InputSystem() :
        m_cursorPosition(glm::vec2(0.0f, 0.0f)),
        m_lockedPosition(glm::vec2(0.0f, 0.0f)),
        m_isCursorLocked(false),
        m_scrollOffset(0.0f),
        m_glfwWindow(Window::instance()->glfwWindow())
    {
        // Setup callbacks
        glfwSetKeyCallback(m_glfwWindow, keyCallback);
        glfwSetMouseButtonCallback(m_glfwWindow, mouseCallback);
        glfwSetCursorPosCallback(m_glfwWindow, cursorCallback);
        glfwSetScrollCallback(m_glfwWindow, scrollCallback);
    }

    InputSystem *InputSystem::instance()
    {
        if(!m_instance)
            m_instance = new InputSystem();

        return m_instance;
    }


    void InputSystem::pollEvents()
    {
        glfwPollEvents();
    }

    glm::vec2 InputSystem::cursorPosition()
    {
        return m_cursorPosition;
    }

    void InputSystem::setCursorPosition(glm::vec2 position)
    {
        m_cursorPosition = position;
        glfwSetCursorPos(m_glfwWindow, position.x, position.y);
    }

    float InputSystem::scrollOffset() const
    {
        return m_scrollOffset;
    }

    void InputSystem::setScrollOffset(float offset)
    {
        m_scrollOffset = offset;
    }

    bool InputSystem::isCursorLocked() const
    {
        return m_isCursorLocked;
    }

    void InputSystem::setLocked(bool value)
    {
        m_isCursorLocked = value;
    }

    void InputSystem::setLockedPosition(glm::vec2 position)
    {
        m_lockedPosition = position;
    }

    glm::vec2 InputSystem::lockedPosition()
    {
        return m_lockedPosition;
    }

    std::vector<int> &InputSystem::keysPressed()
    {
        return m_keysPressed;
    }

    std::vector<int> &InputSystem::keysReleased()
    {
        return m_keysReleased;
    }

    std::vector<int> &InputSystem::keysOnHold()
    {
        return m_keysOnHold;
    }

    std::vector<int> &InputSystem::buttonsPressed()
    {
        return m_buttonsPressed;
    }

    std::vector<int> &InputSystem::buttonsReleased()
    {
        return m_buttonsReleased;
    }

    std::vector<int> &InputSystem::buttonsOnHold()
    {
        return m_buttonsOnHold;
    }

    void InputSystem::clear()
    {
        // Clear button / keys status

        m_keysPressed.clear();
        m_keysReleased.clear();
        m_keysOnHold.clear();

        m_buttonsPressed.clear();
        m_buttonsReleased.clear();
        m_buttonsOnHold.clear();
    }

    void InputSystem::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mod)
    {
        auto instance = InputSystem::instance();

        // vectors
        auto pressed = instance->buttonsPressed();
        auto onHold = instance->buttonsOnHold();
        auto released = instance->buttonsReleased();

        if (action == GLFW_PRESS) {
            // if key is not in array
            if (std::find(pressed.begin(), pressed.end(), key) == pressed.end()) {
                pressed.push_back(key);
                onHold.push_back(key);
            }

        } else if (action == GLFW_RELEASE) {
            // find released key in vector
            for (auto iter = onHold.begin(); iter != onHold.end(); ++iter) {
                if (*iter == key) {
                    onHold.erase(iter);
                    break;
                }
            }

            // add this key as a released one
            released.push_back(key);
        }

    }

    void InputSystem::mouseCallback(GLFWwindow* window, int button, int action, int mod)
    {
        auto instance = InputSystem::instance();

        // LMB
        if (button == 1) {
            if (action == GLFW_PRESS) {
                // add mouse to App
                // TODO: see GLFW_CURSOR_DISABLED
                instance->setLocked(true);

                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
                instance->setLockedPosition(instance->cursorPosition());
            } else if (action == GLFW_RELEASE) {
                instance->setLocked(false);

                instance->setCursorPosition(instance->lockedPosition());

                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
        }

        // vectors
        auto pressed = instance->buttonsPressed();
        auto onHold = instance->buttonsOnHold();
        auto released = instance->buttonsReleased();

        if (action == GLFW_PRESS) {
            // if key is not in array
            if (std::find(pressed.begin(), pressed.end(), button) == pressed.end()) {
                pressed.push_back(button);
                onHold.push_back(button);
            }
        } else if (action == GLFW_RELEASE) {
            // find released key in vector
            for (auto iter = onHold.begin(); iter != onHold.end(); ++iter) {
                if (*iter == button) {
                    onHold.erase(iter);
                    break;
                }
            }

            // add this key as a released one
            released.push_back(button);
        }
    }

    void InputSystem::cursorCallback(GLFWwindow* window, double x, double y)
    {
        InputSystem::instance()->setCursorPosition(glm::vec2(float(x), float(y)));

        glfwSetCursorPos(window, x, y);
    }

    void InputSystem::scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
    {
        // TODO: see offsets
        InputSystem::instance()->setScrollOffset(InputSystem::instance()->scrollOffset() + (float)yOffset);
    }
}