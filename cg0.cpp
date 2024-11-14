#include <iostream>
#include "Box.h"

using namespace std;

Box circle(1, 0, 0);
float x = 0;
float y = 0;
float s =1 ;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
void renderPrimitives();

int main()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Не удалось инициализировать GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Test OpenGL", nullptr, nullptr);
    if (!window) {
        std::cerr << "Не удалось создать окно GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Callbacks
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        //glBegin(GL_QUADS);
        //glVertex2f(x - s / 2, y - s / 2);
        //glVertex2f(x + s / 2, y - s / 2);
        //glVertex2f(x + s / 2, y + s / 2);
        //glVertex2f(x - s / 2, y + s / 2);
        //glEnd();


        // Drawing the primitive
        renderPrimitives();

        // Window update
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Destroying a window and freeing resources
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void renderPrimitives() {
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    circle.draw();
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    double mouseX, mouseY, x, y;
    glfwGetCursorPos(window, &x, &y);
    mouseX = (2.0f * x) / 800.0f - 1.0f;
    mouseY = 1.0f - (2.0f * y) / 800.0f;

    if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        if (action == GLFW_PRESS) {
            // Проверка, нажата ли мышь на квадрате
            if (circle.isInnerPoint(mouseX, mouseY)) {
                circle.startDragging(mouseX, mouseY);
            }
            else {
                // Если мышь кликается по свободной области, переместим центр квадрата
                circle.move(mouseX, mouseY);
            }
        }
        else if (action == GLFW_RELEASE) {
            circle.stopDragging(mouseX, mouseY);  // Окончание перетаскивания
        }
    }
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    double mouseX, mouseY, x, y;
    glfwGetCursorPos(window, &x, &y);
    mouseX = (2.0f * x) / 800.0f - 1.0f;
    mouseY = 1.0f - (2.0f * y) / 800.0f;

        circle.drag(mouseX, mouseY);
    //}
}
