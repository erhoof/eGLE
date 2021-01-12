//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Core/ApplicationContext.h"
#include "../../include/Core/RenderSystem.h"

namespace eGLE
{
    ApplicationContext::ApplicationContext()
    {
        m_rootNode = new Node();
    }

    void ApplicationContext::render(RenderSystem *rs)
    {
        rs->render(rs);
    }

    void ApplicationContext::update(float timeDelta)
    {
        m_rootNode->update(timeDelta);
    }

    void ApplicationContext::input(float timeDelta)
    {
        m_rootNode->input(timeDelta);
    }

    Node &ApplicationContext::rootNode()
    {
        return m_rootNode;
    }

    void ApplicationContext::addToScene(Node *child)
    {
        m_rootNode->addChild(child);
    }
}