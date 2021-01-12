//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_APPLICATIONCONTEXT_H
#define EGLE_APPLICATIONCONTEXT_H

#include "../Bites/Node.h"

namespace eGLE
{
    class RenderSystem;

    class ApplicationContext {
    public:
        ApplicationContext();
        virtual ~ApplicationContext() = default;

        virtual void prepare() {}

        // RUI
        virtual void render(RenderSystem *rs);
        virtual void update(float timeDelta);
        virtual void input(float timeDelta);

        // Getters / Setters
        Node &rootNode();

    protected:
        void addToScene(Node *child);

    private:
        Node *m_rootNode;
    };
}

#endif //EGLE_APPLICATIONCONTEXT_H
