//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Components/PointLightComponent.h"
#include "../../include/Core/Window.h"
#include "../../include/Managers/RenderSystem.h"
#include "../../include/Managers/InputSystem.h"
#include "../../include/Bites/Node.h"

//#include <glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace eGLE
{
    PointLightComponent::PointLightComponent()
    {}

    void PointLightComponent::render(RenderSystem *rs)
    {
        rs->pointLights().push_back(m_parent);
    }
}