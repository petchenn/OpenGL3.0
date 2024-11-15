#include "Model2D.h"
#include "AffineTransform.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "mat3x3.hpp"

Model2D::Model2D(const std::vector<glm::vec2>& vertices, const std::vector<int> indices)
    : m_vertices(vertices), m_indices(indices)
{
    m_modelMatrix = glm::mat3(1.0f);
}

void Model2D::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.663, 0.663, 0.663, 1);

    glBegin(GL_LINE_LOOP);

    glColor3f(0, 0, 0);

    for (int i = 0; i < m_indices.size(); i++) {
        glm::vec3 v(m_vertices[m_indices[i]], 1.0f);
        v = m_modelMatrix * v;
        glVertex2f(v.x, v.y);
    }

    glEnd();
}

void Model2D::translation(float x, float y)
{
    m_modelMatrix = Translation(x, y) * m_modelMatrix;
}

void Model2D::rotate(float degree)
{
    m_modelMatrix = Rotation(degree) * m_modelMatrix;
}

void Model2D::scale(float scale)
{
    m_modelMatrix = Scale(scale, scale) * m_modelMatrix;
}
