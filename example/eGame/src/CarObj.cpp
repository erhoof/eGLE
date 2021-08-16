//
// Created by erhoof on 17.01.2021.
//

#include "../include/CarObj.h"

#include <eGLE/Shaders/LightShader.h>
#include <eGLE/Bites/Node.h>
#include <eGLE/Components/RenderComponent.h>

#include <eGLE/Objects/MeshObjects/Cube.h>
#include <eGLE/Objects/MeshObjects/Polygon2D.h>
#include <eGLE/Objects/Mesh3D.h>
#include <eGLE/Objects/Texture.h>
#include <eGLE/Objects/Material.h>

using namespace eGLE;

namespace eGame
{
    CarObj::CarObj(Node *parent)
    {
        // Core
        m_car_Node = new Node();

        LightShader *shader = LightShader::instance();
        // Init this \/
        /*
         *      Node *m_carBottom_Node;
                Node *m_carTop_Node;
                Node *m_carGlass_Node;
                Node *m_carFront_Node;
                Node *m_carBack_Node;

                // Wheels
                Node *m_wheel_FL;
                Node *m_wheel_FR;
                Node *m_wheel_BL;
                Node *m_wheel_BR;
         * */

        // Car Bottom
        m_carBottom_Node = new Node();
        m_carBottom_Node->transform().setPosition(glm::vec3(3.0f, 0.0f, 1.0f));
        m_carBottom_Node->transform().setScale(glm::vec3(2.0f, 0.5f, 1.0f));
        auto cube = new Cube();
        auto carBottom_Mesh = cube->mesh3D();
        carBottom_Mesh->generate();
        auto carBottom_Model = new Model(carBottom_Mesh, new Material(new Texture("car_bottom.jpg"), new Texture("car_bottom.jpg")));
        m_carBottom_Node->addComponent(new RenderComponent(carBottom_Model, shader));
        m_car_Node->addChild(m_carBottom_Node);

        // Car Top
        m_carTop_Node = new Node();
        m_carTop_Node->transform().setPosition(glm::vec3(3.0f, 0.5f, 1.0f));
        m_carTop_Node->transform().setScale(glm::vec3(1.5f, 0.5f, 1.0f));
        auto carTop_Model = new Model(carBottom_Mesh, new Material(new Texture("car_top.jpg"), new Texture("car_top.jpg")));
        m_carTop_Node->addComponent(new RenderComponent(carTop_Model, shader));
        m_car_Node->addChild(m_carTop_Node);

        // Car Roof
        m_carRoof_Node = new Node();
        m_carRoof_Node->transform().setPosition(glm::vec3(3.0f, 0.75f, 1.0f));
        m_carRoof_Node->transform().setScale(glm::vec3(1.54f, 0.01f, 1.0f));
        auto carRoof_Model = new Model(carBottom_Mesh, new Material(new Texture("car_roof.jpg"), new Texture("car_roof.jpg")));
        m_carRoof_Node->addComponent(new RenderComponent(carRoof_Model, shader));
        m_car_Node->addChild(m_carRoof_Node);

        // Car Front
        m_carFront_Node = new Node();
        m_carFront_Node->transform().setPosition(glm::vec3(4.0f, 0.0f, 1.0f));
        m_carFront_Node->transform().setScale(glm::vec3(0.01f, 0.5f, 1.0f));
        auto carFront_Model = new Model(carBottom_Mesh, new Material(new Texture("car_front.jpg"), new Texture("car_front.jpg")));
        m_carFront_Node->addComponent(new RenderComponent(carFront_Model, shader));
        m_car_Node->addChild(m_carFront_Node);

        // Car Glass
        m_carGlass_Node = new Node();
        m_carGlass_Node->transform().setPosition(glm::vec3(3.765f, 0.49f, 1.0f));
        m_carGlass_Node->transform().setScale(glm::vec3(0.1f, 0.5f, 0.99f));
        m_carGlass_Node->transform().rotate(glm::vec3(0.0f, 0.0f, 1.0f), glm::radians(10.0f));
        auto carGlass_Model = new Model(carBottom_Mesh, new Material(new Texture("car_glass.jpg"), new Texture("car_glass.jpg")));
        m_carGlass_Node->addComponent(new RenderComponent(carGlass_Model, shader));
        m_car_Node->addChild(m_carGlass_Node);

        // Car Back
        m_carBack_Node = new Node();
        m_carBack_Node->transform().setPosition(glm::vec3(2.0f, 0.0f, 1.0f));
        m_carBack_Node->transform().setScale(glm::vec3(0.01f, 0.5f, 1.0f));
        m_carBack_Node->addComponent(new RenderComponent(carFront_Model, shader));
        m_car_Node->addChild(m_carBack_Node);

        // Car Wheel BR
        m_wheel_BR = new Node();
        m_wheel_BR->transform().setPosition(glm::vec3(2.2f, -0.12f, 1.43f));
        m_wheel_BR->transform().setScale(glm::vec3(0.25f, 0.25f, 0.25f));
        auto wheel = new Polygon2D(30, 1, true);
        auto wheelMesh = wheel->mesh3D();
        wheelMesh->generate();
        auto carWheel_Model = new Model(wheelMesh, new Material(new Texture("wheel.jpg"), new Texture("wheel.jpg")));
        m_wheel_BR->addComponent(new RenderComponent(carWheel_Model, shader));
        m_car_Node->addChild(m_wheel_BR);

        // Car Wheel BL
        m_wheel_BL = new Node();
        m_wheel_BL->transform().setPosition(glm::vec3(2.2f, -0.12f, 0.33f));
        m_wheel_BL->transform().setScale(glm::vec3(0.25f, 0.25f, 0.25f));
        m_wheel_BL->addComponent(new RenderComponent(carWheel_Model, shader));
        m_car_Node->addChild(m_wheel_BL);

        // Car Wheel FR
        m_wheel_FR = new Node();
        m_wheel_FR->transform().setPosition(glm::vec3(3.65f, -0.12f, 1.43f));
        m_wheel_FR->transform().setScale(glm::vec3(0.25f, 0.25f, 0.25f));
        m_wheel_FR->addComponent(new RenderComponent(carWheel_Model, shader));
        m_car_Node->addChild(m_wheel_FR);

        // Car Wheel FL
        m_wheel_BL = new Node();
        m_wheel_BL->transform().setPosition(glm::vec3(3.65f, -0.12f, 0.33f));
        m_wheel_BL->transform().setScale(glm::vec3(0.25f, 0.25f, 0.25f));
        m_wheel_BL->addComponent(new RenderComponent(carWheel_Model, shader));
        m_car_Node->addChild(m_wheel_BL);

        // Add Core to Parent
        parent->addChild(m_car_Node);
    }

    CarObj::~CarObj()
    {
        delete m_carBottom_Node;
        delete m_carTop_Node;
        delete m_carGlass_Node;
        delete m_carFront_Node;
        delete m_carBack_Node;
        delete m_carRoof_Node;

        delete m_wheel_FL;
        delete m_wheel_FR;
        delete m_wheel_BL;
        delete m_wheel_BR;
    }

    void CarObj::update()
    {

    }

    void CarObj::input()
    {

    }
}