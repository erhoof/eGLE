//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Components/Component.h"
#include "../../include/Bites/Node.h"

namespace eGLE
{
    Node *Component::parent()
    {
        return m_parent;
    }

    void Component::setParent(Node *parent)
    {
        m_parent = parent;
    }

    Transform &Component::getTransform()
    {
        return m_parent->transform();
    }
}