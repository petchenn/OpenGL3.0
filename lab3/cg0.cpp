#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Model2D.h"
#include "Render2D.h"
#include "Loader.h"

using namespace std;

// Place Render here

void keyboardButtonCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void loadModel(string path);

Render2D render;

int main()
{

    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Cannot initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(1000, 1000, "Test OpenGL", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Cannot create a GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Callbacks
    glfwSetKeyCallback(window, keyboardButtonCallback);

    loadModel("model1.txt");
    loadModel("model2.txt");
    loadModel("model3.txt");

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        render.draw();

        // Window update
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Destroying a window and freeing resources
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void keyboardButtonCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_RIGHT:
            render.getCurrentModel()->translation(0.1f, 0);
            break;
        case GLFW_KEY_LEFT:
            render.getCurrentModel()->translation(-0.1f, 0);
            break;
        case GLFW_KEY_UP:
            render.getCurrentModel()->translation(0, 0.1f);
            break;
        case GLFW_KEY_DOWN:
            render.getCurrentModel()->translation(0, -0.1f);
            break;
        case GLFW_KEY_EQUAL:
            render.getCurrentModel()->scale(1.1f);
            break;
        case GLFW_KEY_MINUS:
            render.getCurrentModel()->scale(0.9f);
            break;
        case GLFW_KEY_E:
            render.getCurrentModel()->rotate(90);
            break;
        case GLFW_KEY_D:
            render.getCurrentModel()->rotate(45);
            break;
        case GLFW_KEY_A:
            render.getCurrentModel()->rotate(-45);
            break;
        case GLFW_KEY_Q:
            render.getCurrentModel()->rotate(-90);
            break;
        case GLFW_KEY_C:
            render.nextObject();
            break;
        }
    }
}

void loadModel(string path) {
    Loader loader(path);
    render.addObject(new Model2D(loader.vertices(), loader.indices()));
}
