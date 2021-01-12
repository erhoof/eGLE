//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_INPUTSYSTEM_H
#define EGLE_INPUTSYSTEM_H

#include "glm/glm.hpp"
#include <vector>

class GLFWwindow;

namespace eGLE
{
    class InputSystem {
    public:
        static InputSystem *instance();

        // Core
        static void prepare(GLFWwindow *glfwWindow);
        static void pollEvents();

        // -- Getters / Setters --
        glm::vec2 cursorPosition();
        void setCursorPosition(glm::vec2 position);
        float scrollOffset() const;
        void setScrollOffset(float offset);

        // - cursor lock status
        bool isCursorLocked() const;
        void setLocked(bool value);
        void setLockedPosition(glm::vec2 position);
        glm::vec2 lockedPosition();

        // - keys
        std::vector<int> &keysPressed();
        std::vector<int> &keysReleased();
        std::vector<int> &keysOnHold();

        // - buttons
        std::vector<int> &buttonsPressed();
        std::vector<int> &buttonsReleased();
        std::vector<int> &buttonsOnHold();

    private:
        InputSystem();
        InputSystem(const InputSystem &) = default;
        InputSystem &operator=(InputSystem &) = default;

        static InputSystem *m_instance;

        // glfw
        GLFWwindow *m_glfwWindow;

        // - keys
        std::vector<int> m_keysPressed{};
        std::vector<int> m_keysReleased{};
        std::vector<int> m_keysOnHold{};

        // - buttons
        std::vector<int> m_buttonsPressed{};
        std::vector<int> m_buttonsReleased{};
        std::vector<int> m_buttonsOnHold{};

        // - mouse
        glm::vec2 m_cursorPosition;
        glm::vec2 m_lockedPosition;
        float m_scrollOffset;
        bool m_isCursorLocked;

        // Add-in
        void clear();

        // -- Callbacks --
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mod);

        // - mouse
        static void mouseCallback(GLFWwindow* window, int button, int action, int mod);
        static void cursorCallback(GLFWwindow* window, double x, double y);
        static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
    };
}


#endif //EGLE_INPUTSYSTEM_H
