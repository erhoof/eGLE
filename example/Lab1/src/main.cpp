#include <GLFW/glfw3.h>

#include <eGLE/eGLE.h>

using namespace eGLE;

class TestGame : public ApplicationContext {
public:
    TestGame() = default;

    void prepare()
    {
        // -- Camera --
        cameraNode = new Node();
        cameraNode->transform().setPosition(glm::vec3(0.0f, 0.0f, 5.0f));

        // Camera :: CameraComponent
        auto cameraComponent = new CameraComponent();
        cameraNode->addComponent(cameraComponent);

        addToScene(cameraNode);
    }

    void update(float timeDelta) override
    {
        ApplicationContext::input(timeDelta);

    }

    void input(float timeDelta) override
    {
        ApplicationContext::input(timeDelta);

        // Flying
        auto is = InputSystem::instance();
        std::vector<int> &keysPressed = InputSystem::instance()->keysOnHold();

        if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_Q) != keysPressed.end()) {
            if (std::find(keysPressed.begin(), keysPressed.end(), GLFW_KEY_LEFT_CONTROL) != keysPressed.end()) {
                exit(-1);
            }
        }
    }

private:
    Node *cameraNode;
    Node *cubeNode1;
};

int main()
{
    // 1. Create App Context
    auto appContext = new TestGame();

    // 2. Create Rendering System
    auto rs = new RenderSystem();

    // 3. Setup MainWindow
    Window::instance()->prepare(640, 480, "Lab1");

    // 4. Create CORE and combine it all
    auto core = new Core(appContext, rs, 60);

    // 5. Run It!
    core->run();

    return 0;
}
