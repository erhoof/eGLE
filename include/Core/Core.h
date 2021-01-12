//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_CORE_H
#define EGLE_CORE_H

namespace eGLE
{
    class ApplicationContext;
    class RenderSystem;
    class Window;

    class Core {
    public:
        Core(ApplicationContext *ac, RenderSystem *rs, double frameRate);
        ~Core() = default;

        void run();

        // Getters / Setters
        static int frameRate();

    private:
        // Core Parts
        ApplicationContext *m_applicationContext;
        RenderSystem *m_renderSystem;
        Window *m_window;

        // Add-in properties
        bool m_isRunning;
        double m_frameTime;
        static int m_frameRate;

        // RUI
        void render(RenderSystem *rs);
        void update(float timeDelta);
        void input(float timeDelta);
    };
}

#endif //EGLE_CORE_H
