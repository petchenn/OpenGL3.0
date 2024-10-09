
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


// Global variables to handle circle properties
//float radius = 0.5f; // Initial radius
//float angleStep = 0.05f; // Step for drawing circle
struct Line {
    double startX, startY;
    double endX, endY;
};
vector<Line> lines;
float fillColor[3] = { 1.0f, 0.0f, 0.0f }; // Initial fill color
Line cur;


// Drawing the circle
void renderCircle();
void processInput(GLFWwindow* window);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void keyboardButtonCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Не удалось инициализировать GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 800, "Lines", nullptr, nullptr);
    if (!window) {
        std::cerr << "Не удалось создать окно GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Button mouse callback
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    //Keyboard callback
    glfwSetKeyCallback(window, keyboardButtonCallback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Input processing
        processInput(window);

        // Drawing the circle
        renderCircle();

        // Window update
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Destroying a window and freeing resources
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void renderCircle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glColor3f(fillColor[0], fillColor[1], fillColor[2]);

    //glBegin(GL_LINES);
    //glVertex2f(0.0, 0.0);
    //glVertex2f(0.5, 1.0);
    //glEnd();

    for (int i = 0; i < lines.size(); i++) {
        glBegin(GL_LINES);
        glVertex2f(lines[i].startX, lines[i].startY);
        glVertex2f(lines[i].endX, lines[i].endY);
        glEnd();
    }
}

void processInput(GLFWwindow* window)
{
    // Additional input logic can be added here if needed
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        double x = 0;
        double y = 0;
        glfwGetCursorPos(window, &x, &y);
        cur.startX = (2.0f * x) / 800.0f - 1.0f;
        cur.startY = 1.0f - (2.0f * y) / 800.0f;
        cout << "First Point: " << cur.startX <<" " << cur.startY << endl;

    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double x = 0;
        double y = 0;
        glfwGetCursorPos(window, &(x), &y);
        cur.endX = (2.0f * x) / 800.0f - 1.0f;
        cur.endY = 1.0f - (2.0f * y) / 800.0f;
        cout << "Second Point: " << cur.endX << " " << cur.endY << endl;
        cout << "Point" << "(" << cur.startX << " " << cur.startY << ")(" << cur.endX << " " << cur.endY << endl;
        lines.push_back(cur);
    }
}

void keyboardButtonCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_C && action == GLFW_PRESS) {
        // Randomly change fill color
        fillColor[0] = static_cast<float>(rand()) / RAND_MAX;
        fillColor[1] = static_cast<float>(rand()) / RAND_MAX;
        fillColor[2] = static_cast<float>(rand()) / RAND_MAX;
        cout << "Цвет изменен: (" << fillColor[0] << ", " << fillColor[1] << ", " << fillColor[2] << ")" << endl;
    }
}