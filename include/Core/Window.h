//
// Created by erhoof on 11.01.2021.
//

#ifndef EGLE_WINDOW_H
#define EGLE_WINDOW_H

class GLFWwindow;

namespace eGLE
{
    class Window {
    public:
        static Window *instance();

        void init(int width, int height, const char *title);
        bool shouldClose(); // get if window should close

        // Rendering
        void render();
        void clear();
        void destroy();

        // Getters
        int width() const;
        int height() const;
        GLFWwindow *glfwWindow();

    private:
        Window() = default;
        Window(const Window &);
        Window &operator=(Window &) = delete;
        ~Window() = default;

        static Window *m_instance;

        int m_width;
        int m_height;
        const char *m_title;
        GLFWwindow *m_glfwWindow;
    };

    // Callbacks
    void resize(GLFWwindow *window, int width, int height);
}

#endif //EGLE_WINDOW_H
