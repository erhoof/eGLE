#include <GLFW/glfw3.h>

#include <eGLE/eGLE.h>
#include "../include/CarObj.h"

using namespace eGLE;

class TestGame : public ApplicationContext {
public:
    TestGame() = default;

    void prepare()
    {
        // -- Camera --
        m_cameraNode = new Node();
        m_cameraNode->transform().setPosition(glm::vec3(-1.0f, 0.0f, 5.0f));

        // Camera :: CameraComponent
        m_cameraComponent = new CameraComponent();
        m_cameraNode->addComponent(m_cameraComponent);

        addToScene(m_cameraNode);

        // -- Car --
        m_carObj = new eGame::CarObj(&ApplicationContext::rootNode());
        m_carObj->m_car_Node->moveWithDelta(glm::vec3(-12.0f, -0.5f, 0.0f));

        // -- Cube1 -- >> Light
        cubeNode1 = new Node();
        cubeNode1->transform().setPosition(glm::vec3(1.5f, 1.2f, -7.5f));
        cubeNode1->transform().setScale(glm::vec3(0.2f, 0.2f, 0.2f));
        auto cubeMesh = new Cube();
        auto cubeMesh1 = cubeMesh->mesh3D();
        cubeMesh1->generate();
        auto cubeModel1 = new Model(cubeMesh1, new Material(new Texture("stone.jpg"), new Texture("stone.jpg")));
        ColorShader *colorShader = ColorShader::instance();
        cubeNode1->addComponent(new PointLightComponent());
        cubeNode1->addComponent(new RenderComponent(cubeModel1, colorShader));
        addToScene(cubeNode1);

        // -- Cube1 -- >> Dif / Spec
        cubeNode2 = new Node();
        cubeNode2->transform().setPosition(glm::vec3(2.75f, 0.5f, -7.5f));
        cubeMesh1 = cubeMesh->mesh3D();
        cubeMesh1->generate();
        auto cubeModel2 = new Model(cubeMesh1, new Material(new Texture("container_diffuse.png"), new Texture("container_specular.png")));
        LightShader *lightShader = LightShader::instance();
        cubeNode2->addComponent(new RenderComponent(cubeModel2, lightShader));
        addToScene(cubeNode2);

        // -- Cube -- >> Road
        roadNode = new Node();
        roadNode->transform().setPosition(glm::vec3(2.0f, -1.0f, 1.0f));
        roadNode->transform().setScale(glm::vec3(30.0f, 0.2f, 3.0f));
        //roadNode->transform().rotate(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(90.0f));
        auto roadModel = new Model(cubeMesh1, new Material(new Texture("road.png"), new Texture("road.png")));
        roadNode->addComponent(new RenderComponent(roadModel, lightShader));
        addToScene(roadNode);

        // -- Cube -- >> Road2
        roadNode2 = new Node();
        roadNode2->transform().setPosition(glm::vec3(2.0f, -1.0f, 4.0f));
        roadNode2->transform().setScale(glm::vec3(30.0f, 0.2f, 3.0f));
        roadNode2->addComponent(new RenderComponent(roadModel, lightShader));
        addToScene(roadNode2);

        // -- Cube -- >> SideRoad
        sideRoadNode = new Node();
        sideRoadNode->transform().setPosition(glm::vec3(2.0f, -0.8f, 6.0f));
        sideRoadNode->transform().setScale(glm::vec3(30.0f, 0.2f, 2.0f));
        auto sideRoadModel = new Model(cubeMesh1, new Material(new Texture("side_road.jpg"), new Texture("side_road.jpg")));
        sideRoadNode->addComponent(new RenderComponent(sideRoadModel, lightShader));
        addToScene(sideRoadNode);

        // -- Cube -- >> SideRoad2
        sideRoadNode2 = new Node();
        sideRoadNode2->transform().setPosition(glm::vec3(2.0f, -0.8f, -1.0f));
        sideRoadNode2->transform().setScale(glm::vec3(30.0f, 0.2f, 2.0f));
        sideRoadNode2->addComponent(new RenderComponent(sideRoadModel, lightShader));
        addToScene(sideRoadNode2);

        // -- Cube -- >> LeftWall
        leftWallNode = new Node();
        leftWallNode->transform().setPosition(glm::vec3(-5.3f, 0.43f, -2.25f));
        leftWallNode->transform().setScale(glm::vec3(10.0f, 2.5f, 0.5f));
        auto leftWallModel = new Model(cubeMesh1, new Material(new Texture("voenmeh_bottom.jpg"), new Texture("road.png")));
        leftWallNode->addComponent(new RenderComponent(leftWallModel, lightShader));
        addToScene(leftWallNode);

        // -- Cube -- >> RightWall
        rightWallNode = new Node();
        rightWallNode->transform().setPosition(glm::vec3(7.5f, 0.43f, -2.25f));
        rightWallNode->transform().setScale(glm::vec3(10.0f, 2.5f, 0.5f));
        rightWallNode->addComponent(new RenderComponent(leftWallModel, lightShader));
        addToScene(rightWallNode);

        // -- Cube -- >> UpWall
        upWallNode = new Node();
        upWallNode->transform().setPosition(glm::vec3(1.2f, 5.15f, -2.25f));
        upWallNode->transform().setScale(glm::vec3(20.0f, 7.0f, 0.5f));
        auto upWallModel = new Model(cubeMesh1, new Material(new Texture("voenmeh_top.jpg"), new Texture("road.png")));
        upWallNode->addComponent(new RenderComponent(upWallModel, lightShader));
        addToScene(upWallNode);

        // -- Cube -- >> downIntNode
        downIntNode = new Node();
        downIntNode->transform().setPosition(glm::vec3(1.36f, -0.8f, -6.0f));
        downIntNode->transform().setScale(glm::vec3(8.0f, 0.2f, 8.0f));
        auto downIntModel = new Model(cubeMesh1, new Material(new Texture("intWall.jpg"), new Texture("road.png")));
        downIntNode->addComponent(new RenderComponent(downIntModel, lightShader));
        addToScene(downIntNode);

        // -- Cube -- >> upIntNode
        upIntNode = new Node();
        upIntNode->transform().setPosition(glm::vec3(1.36f, 2.0f, -6.2f));
        upIntNode->transform().setScale(glm::vec3(8.0f, 0.2f, 8.0f));
        upIntNode->addComponent(new RenderComponent(downIntModel, lightShader));
        addToScene(upIntNode);

        // -- Cube -- >> leftIntNode
        leftIntNode = new Node();
        leftIntNode->transform().setPosition(glm::vec3(-2.55f, 0.66f, -6.5f));
        leftIntNode->transform().setScale(glm::vec3(0.2f, 3.8f, 8.0f));
        leftIntNode->addComponent(new RenderComponent(downIntModel, lightShader));
        addToScene(leftIntNode);

        // -- Cube -- >> rightIntNode
        rightIntNode = new Node();
        rightIntNode->transform().setPosition(glm::vec3(5.36f, 0.66f, -6.5f));
        rightIntNode->transform().setScale(glm::vec3(0.2f, 3.8f, 8.0f));
        rightIntNode->addComponent(new RenderComponent(downIntModel, lightShader));
        addToScene(rightIntNode);

        // -- Cube -- >> frontIntNode
        frontIntNode = new Node();
        frontIntNode->transform().setPosition(glm::vec3(1.52f, 0.66f, -9.9f));
        frontIntNode->transform().setScale(glm::vec3(8.0f, 3.8f, 0.2f));
        frontIntNode->addComponent(new RenderComponent(downIntModel, lightShader));
        addToScene(frontIntNode);

        // -- Cube -- >> voenmehNode
        voenmehNode = new Node();
        voenmehNode->transform().setPosition(glm::vec3(0.1f, 0.5f, -7.5f));
        auto voenmehModel = new Model(cubeMesh1, new Material(new Texture("voenmeh.jpg"), new Texture("road.png")));
        voenmehNode->addComponent(new RenderComponent(voenmehModel, lightShader));
        addToScene(voenmehNode);

        // -- Cube -- >> leftDoorNode
        leftDoorNode = new Node();
        leftDoorNode->transform().setPosition(glm::vec3(0.1f, 0.5f, -2.16f));
        leftDoorNode->transform().setScale(glm::vec3(2.0f, 3.0f, 0.2f));
        auto leftDoorModel = new Model(cubeMesh1, new Material(new Texture("door.jpg"), new Texture("road.png")));
        leftDoorNode->addComponent(new RenderComponent(leftDoorModel, lightShader));
        addToScene(leftDoorNode);

        // -- Cube -- >> rightDoorNode
        rightDoorNode = new Node();
        rightDoorNode->transform().setPosition(glm::vec3(2.0f, 0.5f, -2.16f));
        rightDoorNode->transform().setScale(glm::vec3(2.0f, 3.0f, 0.2f));
        rightDoorNode->addComponent(new RenderComponent(leftDoorModel, lightShader));
        addToScene(rightDoorNode);

        /*// -- Square -- >> planeNode
        planeNode = new Node();
        planeNode->transform().setPosition(glm::vec3(0.0f, 2.0f, 0.0f));
        auto planeMesh = new Polygon2D(3, 1.0f, true);
        planeMesh1 = planeMesh->mesh2D();
        m_planeColor = glm::vec3(0.0f, 0.0f, 0.0f);
        m_planeMode = true;
        m_planeFill = true;
        planeMesh1->setColor(m_planeColor);
        planeMesh1->setMode(GL_TRIANGLES);
        planeMesh1->generate();
        auto planeModel1 = new Model(planeMesh1, new Material(new Texture("stone.jpg"), new Texture("stone.jpg")));
        planeNode->addComponent(new RenderComponent(planeModel1, colorShader));
        //addToScene(planeNode);*/

        // -- Model -- >> Model
        modelNode = new Node();
        modelNode->transform().setPosition(glm::vec3(-8.5f, 0.0f, 4.0f));
        modelNode->transform().setScale(glm::vec3(0.09f, 0.09f, 0.09f));
        modelNode->transform().rotate(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(180.0f));
        modelNode->transform().rotate(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.0f));
        auto modelModel = new Model("data/Models/car/Hummer.obj");
        modelModel->generate();
        modelNode->addComponent(new RenderComponent(modelModel, lightShader));

        addToScene(modelNode);
    }

    void update(float timeDelta) override
    {
        ApplicationContext::input(timeDelta);

        voenmehNode->transform().rotate(glm::vec3(0,0,1), timeDelta);
        cubeNode2->transform().rotate(glm::vec3(0,1,0), timeDelta);

        // plane
        /*if (m_planeMode) {
            m_planeColor.x += timeDelta;

            if (m_planeColor.x >= 1.0)
                m_planeMode = false;
        } else {
            m_planeColor.x -= timeDelta;

            if (m_planeColor.x <= 0.0)
                m_planeMode = true;
        }
        planeMesh1->setColor(m_planeColor);
        planeMesh1->generate();*/

        if (m_carDirection) {
            if (m_carObj->m_car_Node->transform().position().x >= 10.0f) {
                m_carDirection = false;
            }

            //m_carObj->m_car_Node->moveWithDelta(glm::vec3(3.5f * timeDelta, 0.0f, 0.0f));
            modelNode->moveWithDelta(glm::vec3(3.5f * timeDelta, 0.0f, 0.0f));
        } else {
            if (m_carObj->m_car_Node->transform().position().x <= -12.0f) {
                m_carDirection = true;
            }

            //m_carObj->m_car_Node->moveWithDelta(glm::vec3(-3.5f * timeDelta, 0.0f, 0.0f));
            modelNode->moveWithDelta(glm::vec3(-3.5f * timeDelta, 0.0f, 0.0f));
        }

        if (m_doorToggle) {
            if (m_doorAction) { // Door was closed

                if (leftDoorNode->transform().position().x >= -1.4f)
                    leftDoorNode->moveWithDelta(glm::vec3(-3.5f * timeDelta, 0.0f, 0.0f));
                else
                    m_doorToggle = false;

                if (rightDoorNode->transform().position().x < 3.5f)
                    rightDoorNode->moveWithDelta(glm::vec3(3.5f * timeDelta, 0.0f, 0.0f));

            } else { // Door was opened

                if (leftDoorNode->transform().position().x < 0.1f)
                    leftDoorNode->moveWithDelta(glm::vec3(3.5f * timeDelta, 0.0f, 0.0f));
                else
                    m_doorToggle = false;

                if (rightDoorNode->transform().position().x > 2.0f)
                    rightDoorNode->moveWithDelta(glm::vec3(-3.5f * timeDelta, 0.0f, 0.0f));
            }

            if (!m_doorToggle) {
                m_doorAction = !m_doorAction;

                if (m_doorAction) { // doors now closed
                    rightDoorNode->transform().position().x = 2.0f;
                    leftDoorNode->transform().position().x = 0.1f;
                }
            }
        }
    }

    void input(float timeDelta) override
    {
        ApplicationContext::input(timeDelta);

        // Flying
        auto is = InputSystem::instance();
        std::vector<int> &keysPressed = InputSystem::instance()->keysOnHold();

        Node *node = cubeNode2;
        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_UP) != keysPressed.end()) {
            node->transform().position().x += timeDelta * 5;
        }

        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_DOWN) != keysPressed.end()) {
            node->transform().position().x -= timeDelta * 5;
        }

        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_LEFT) != keysPressed.end()) {
            node->transform().position().z -= timeDelta * 5;
        }

        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_RIGHT) != keysPressed.end()) {
            node->transform().position().z += timeDelta * 5;
        }

        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_PAGE_UP) != keysPressed.end()) {
            node->transform().position().y += timeDelta * 5;
        }

        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_PAGE_DOWN) != keysPressed.end()) {
            node->transform().position().y -= timeDelta * 5;
        }

        /*if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_F) != keysPressed.end()) {
            m_planeFill = !m_planeFill;

            if (m_planeFill)
                planeMesh1->setMode(GL_TRIANGLES);
            else
                planeMesh1->setMode(GL_LINE_LOOP);

            planeMesh1->generate();
        }*/

        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_E) != keysPressed.end()) {
            auto front = m_cameraComponent->front();
            auto pos = m_cameraNode->transform().position();

            /*Debug::msg("x:", m_cameraNode->transform().position().x,
                       "y:", m_cameraNode->transform().position().y,
                       "z:", m_cameraNode->transform().position().z);

            Debug::msg("front x:", m_cameraComponent->front().x,
                       "front y:", m_cameraComponent->front().y,
                       "front z:", m_cameraComponent->front().z);*/

            if (front.x >= -0.6f && front.x <= 0.6f && front.z >= -1.0f && front.z <= -0.6f &&
            pos.x >= 0.5 && pos.x <= 2.5 && pos.z >= -1 && pos.z <= 3 && pos.y <= 2 && pos.y >= -1) {
                m_doorToggle = true;
                Debug::msg("Toggle!");
            }
        }

        /*if (!keysPressed.empty()) {
            Debug::msg("x:", node->transform().position().x,
                       "y:", node->transform().position().y,
                       "z:", node->transform().position().z);
        }*/
    }

private:
    // Core
    Node *m_cameraNode;
    CameraComponent *m_cameraComponent;

    // Car
    eGame::CarObj *m_carObj;
    bool m_carDirection = true;

    // Light
    Node *cubeNode1; // Point Light

    // Obj with Spec / Dif maps
    Node *cubeNode2;

    // Road
    Node *roadNode;
    Node *roadNode2;
    Node *sideRoadNode;
    Node *sideRoadNode2;

    // Building
    Node *leftWallNode;
    Node *rightWallNode;
    Node *upWallNode;

    // Interior
    Node *leftIntNode;
    Node *rightIntNode;
    Node *upIntNode;
    Node *downIntNode;
    Node *frontIntNode;
    Node *voenmehNode;

    // Doors
    Node *leftDoorNode;
    Node *rightDoorNode;
    bool m_doorToggle = false;
    bool m_doorAction = true; // True - Closed, False - Opened

    // 2D for Colors
    /*Node *planeNode;
    Mesh2D *planeMesh1;
    glm::vec3 m_planeColor;
    bool m_planeMode;
    bool m_planeFill;*/

    // Model Loader
    Node *modelNode;
};

int main()
{
    // 1. Create App Context
    auto appContext = new TestGame();

    // 2. Create Rendering System
    auto rs = new RenderSystem();

    // 3. Setup MainWindow
    Window::instance()->prepare(1366, 768, "Test Game");

    // 4. Create CORE and combine it all
    auto core = new Core(appContext, rs, 60);

    // 5. Run It!
    core->run();

    return 0;
}
