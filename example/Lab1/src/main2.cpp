#include <GLFW/glfw3.h>

#include <eGLE/eGLE.h>

using namespace eGLE;

class TestGame : public eGLE::ApplicationContext {
public:
    TestGame() = default;

    void prepare()
    {
        BasicShader *shader = BasicShader::instance();

        auto cameraComponent = new CameraComponent(glm::radians(45.0f),
                                                   (float)Window::instance()->width() / (float)Window::instance()->height(),
                                                   0.1f,
                                                   1000.0f);

        cameraNode = new Node();
        cameraNode->addComponent(cameraComponent);
        cameraNode->transform().setPosition(glm::vec3(0.0f, 0.0f, 5.0f));





        Model *cubeModel1 = new Model(new Mesh(vertices, indices), new Material(new Texture("data/Textures/jojo.jpg")));
        Model *cubeModel2 = new Model(new Mesh(vertices, indices), new Material(new Texture("data/Textures/dio.jpg")));
        Model *cubeModel3 = new Model(new Mesh(vertices, indices), new Material(new Texture("data/Textures/speed.jpg")));

        cubeNode1 = new Node();
        cubeNode1->addComponent(new RenderComponent(cubeModel1, shader));
        cubeNode1->transform().setPosition(glm::vec3(0.0f, 0.0f, 1.0f));

        addToScene(cameraNode);
        addToScene(cubeNode1);
    }

    void update(float timeDelta)
    {
        ApplicationContext::input(timeDelta);

        cubeNode1->transform().rotate(glm::vec3(0, 1, 0), timeDelta);
        cubeNode2->transform().rotate(glm::vec3(1, 0, 0), timeDelta);

        static bool mode = true;
        if (mode) {
            cubeNode3->transform().scale().x += timeDelta;

            if (cubeNode3->transform().scale().x >= 2.5f)
                mode = false;
        } else {
            cubeNode3->transform().scale().x -= timeDelta;

            if (cubeNode3->transform().scale().x <= 0.5f)
                mode = true;
        }
        //cubeNode->transform().position().x += timeDelta;
    }

    void input(float timeDelta)
    {
        ApplicationContext::input(timeDelta);

        auto is = InputSystem::instance();
        std::vector<int> &keysPressed = InputSystem::instance()->keysOnHold();

        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_SPACE) != keysPressed.end()) {
            cameraNode->transform().position().y += timeDelta * 5;
        }

        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_LEFT_SHIFT) != keysPressed.end()) {
            cameraNode->transform().position().y -= timeDelta * 5;
        }
    }

    void render() {

    }

private:
    Node *cameraNode;
    Node *cubeNode1;
    Node *cubeNode2;
    Node *cubeNode3;
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
