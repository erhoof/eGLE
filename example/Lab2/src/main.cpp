#include <GLFW/glfw3.h>

#include <eGLE/eGLE.h>

#include <cstdlib>

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

        // -- Часть 1
        /* 1. Построить правильный N-угольник - Закрашенный примитив */
        std::cout << "Выберите ЛР";
        int lr;
        std::cin >> lr;

        switch (lr) {
            case 1:
                lab2_1_1();
                break;
            case 2:
                lab2_1_2();
                break;
            case 3:
                lab2_1_3();
                break;
            case 4:
                lab2_1_4();
                break;
            case 5:
                lab2_2_1();
                break;
            case 6:
                lab2_2_2();
                break;
            case 7:
                lab2_2_3();
                break;
            case 8:
                lab2_3();
                break;
            default:
                Debug::halt("Некорректный вывод! (1..8");
        }

        /* 1. Построить правильный N-угольник - Набор треугольников */
        //lab2_1_2();

        /* 1. Построить правильный N-угольник - Набор линий */
        //lab2_1_3();

        /* 1. Построить правильный N-угольник - Набор точек */
        //lab2_1_4();

        // -- Часть 2
        /* 2. Построить - Прямоугольный (Равнобедренный) треугольник */
        //lab2_2_1();

        /* 2. Построить - Произвольный невыпуклый многоугольник */
        //lab2_2_2();

        /* 2. Построить - Прямоугольник (Квадрат) */
        //lab2_2_3();

        // -- Часть 3
        /* 3. Построить - N точек, окрашенных случайно и распределенных случайно */
        //lab2_3();

        addToScene(cameraNode);
    }

    void update(float timeDelta) override
    {
        ApplicationContext::update(timeDelta);

        for (auto const &dot : m_dots) {
            int mov = rand() % 4;

            switch (mov) {
                case 0:
                    dot->transform().position().x += timeDelta;
                    break;
                case 1:
                    dot->transform().position().x -= timeDelta;
                    break;
                case 2:
                    dot->transform().position().y += timeDelta;
                    break;
                case 3:
                    dot->transform().position().y -= timeDelta;
                    break;
            }
        }
    }

    void input(float timeDelta) override
    {
        ApplicationContext::input(timeDelta);
    }

    // -- 1
    void lab2_1_1()
    {
        auto triangleNode = new Node();
        triangleNode->transform().setPosition(glm::vec3(0.0f, 0.0f, 0.5f));

        // Triangle :: RenderComponent
        int count = 0;
        std::cout << "Enter vertex count: ";
        std::cin >> count;
        auto triangleMesh = Polygon2D::mesh3D(count, 1.0f);
        triangleMesh->setColor(glm::vec3(0.2f, 1.0f, 0.1f));
        triangleMesh->generate();

        auto triangleModel = new Model(triangleMesh);
        ColorShader *shader = ColorShader::instance();
        triangleNode->addComponent(new RenderComponent(triangleModel, shader));

        addToScene(triangleNode);
    }

    void lab2_1_2()
    {
        auto triangleNode = new Node();
        triangleNode->transform().setPosition(glm::vec3(0.0f, 0.0f, 0.5f));

        // Triangle :: RenderComponent
        int count = 0;
        std::cout << "Enter vertex count: ";
        std::cin >> count;
        auto triangleMesh = Polygon2D::mesh2D(count, 1.0f, false); // without border
        triangleMesh->setColor(glm::vec3(1.0f, 1.0f, 0.1f));
        triangleMesh->setMode(GL_LINE_LOOP); // GL_LINE_LOOP / GL_POINTS
        triangleMesh->generate();

        auto triangleModel = new Model(triangleMesh);
        ColorShader *shader = ColorShader::instance();
        triangleNode->addComponent(new RenderComponent(triangleModel, shader));

        addToScene(triangleNode);
    }

    void lab2_1_3()
    {
        auto triangleNode = new Node();
        triangleNode->transform().setPosition(glm::vec3(0.0f, 0.0f, 0.5f));

        // Triangle :: RenderComponent
        int count = 0;
        std::cout << "Enter vertex count: ";
        std::cin >> count;
        auto triangleMesh = Polygon2D::mesh2D(count, 1.0f, true); // without border
        triangleMesh->setColor(glm::vec3(1.0f, 1.0f, 0.1f));
        triangleMesh->setMode(GL_LINE_LOOP); // GL_LINE_LOOP / GL_POINTS
        triangleMesh->generate();

        auto triangleModel = new Model(triangleMesh);
        ColorShader *shader = ColorShader::instance();
        triangleNode->addComponent(new RenderComponent(triangleModel, shader));

        addToScene(triangleNode);
    }

    void lab2_1_4()
    {
        auto triangleNode = new Node();
        triangleNode->transform().setPosition(glm::vec3(0.0f, 0.0f, 0.5f));

        // Triangle :: RenderComponent
        int count = 0;
        std::cout << "Enter vertex count: ";
        std::cin >> count;
        auto triangleMesh = Polygon2D::mesh2D(count, 1.0f, true); // without border
        triangleMesh->setColor(glm::vec3(1.0f, 1.0f, 0.1f));
        triangleMesh->setMode(GL_POINTS); // GL_LINE_LOOP / GL_POINTS
        triangleMesh->generate();

        auto triangleModel = new Model(triangleMesh);
        ColorShader *shader = ColorShader::instance();
        triangleNode->addComponent(new RenderComponent(triangleModel, shader));

        addToScene(triangleNode);
    }

    void lab2_2_1()
    {
        auto triangleNode = new Node();
        triangleNode->transform().setPosition(glm::vec3(0.0f, 0.0f, 2.7f));
        srand(time(nullptr));
        triangleNode->transform().rotate(glm::vec3(0, 0, 1), rand() % 90);

        // Triangle :: RenderComponent
        auto triangleMesh = Triangle2D::mesh3D();
        triangleMesh->setColor(glm::vec3(0.2f, 1.0f, 0.1f));
        triangleMesh->generate();

        auto triangleModel = new Model(triangleMesh, new Material(new Texture("stone.jpg")));
        BasicShader *shader = BasicShader::instance();
        triangleNode->addComponent(new RenderComponent(triangleModel, shader));

        addToScene(triangleNode);
    }

    void lab2_2_2()
    {
        auto triangleNode = new Node();
        triangleNode->transform().setPosition(glm::vec3(0.0f, 0.0f, 0.5f));
        srand(time(nullptr));
        triangleNode->transform().rotate(glm::vec3(0, 0, 1), rand() % 90);

        // Triangle :: RenderComponent
        auto triangleMesh = NonConvexPolygon2D::mesh3D();
        triangleMesh->setColor(glm::vec3(1.0f, 1.0f, 0.1f));
        triangleMesh->generate();

        auto triangleModel = new Model(triangleMesh);
        ColorShader *shader = ColorShader::instance();
        triangleNode->addComponent(new RenderComponent(triangleModel, shader));

        addToScene(triangleNode);
    }

    void lab2_2_3()
    {
        auto triangleNode = new Node();
        triangleNode->transform().setPosition(glm::vec3(0.0f, 0.0f, 0.5f));
        srand(time(nullptr));
        triangleNode->transform().rotate(glm::vec3(0, 0, 1), rand() % 90);

        // Triangle :: RenderComponent
        auto triangleMesh = Polygon2D::mesh3D(4, 1.0f);
        triangleMesh->setColor(glm::vec3(0.2f, 1.0f, 0.1f));
        triangleMesh->generate();

        auto triangleModel = new Model(triangleMesh);
        ColorShader *shader = ColorShader::instance();
        triangleNode->addComponent(new RenderComponent(triangleModel, shader));

        addToScene(triangleNode);
    }

    void lab2_3()
    {
        srand(time(nullptr));
        int rc = 20; // random const

        int count = 0;
        std::cout << "Enter dot count: ";
        std::cin >> count;

        // Prepare shader
        ColorShader *shader = ColorShader::instance();

        // Create dots
        for (int i = 0; i < count; ++i) {
            // create node
            auto node = new Node();
            float x = (rand() % rc) / 10.0f;
            float y = (rand() % rc) / 10.0f;
            node->transform().setPosition(glm::vec3(x, y, 0.5f));

            // create mesh
            auto mesh = Dot2D::mesh2D();
            float r = (rand() % 10) / 10.0f;
            float g = (rand() % 10) / 10.0f;
            float b = (rand() % 10) / 10.0f;
            mesh->setColor(glm::vec3(r, g, b));
            mesh->setMode(GL_POINTS);
            mesh->generate();

            // create model
            auto model = new Model(mesh);
            node->addComponent(new RenderComponent(model, shader));

            addToScene(node);
            m_dots.push_back(node);
        }
    }

private:
    Node *cameraNode;
    std::vector<Node *> m_dots;
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
