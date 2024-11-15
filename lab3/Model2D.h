#pragma once
#include <vector>
#include "glm.hpp"
#include "mat3x3.hpp"

class Model2D
{
public:
    Model2D() = default;
    Model2D(const std::vector<glm::vec2>& vertices, const std::vector<int> indices);

    void draw();

    void translation(float x, float y);
    void rotate(float degree);
    void scale(float scale);

private:
    std::vector<glm::vec2> m_vertices;
    std::vector<int> m_indices;

    glm::mat3 m_modelMatrix;
};
