//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_POINTLIGHTCOMPONENT_H
#define EGLE_POINTLIGHTCOMPONENT_H

#include "Component.h"

namespace eGLE
{
    class RenderSystem;

    class PointLightComponent : public Component {
    public:
        PointLightComponent();

        // RUI
        void render(RenderSystem *rs);
    };
}

#endif //EGLE_POINTLIGHTCOMPONENT_H
