#pragma once
#ifndef AFFINE_TRANSFORM_H
#define AFFINE_TRANSFORM_H
#include <glm.hpp>


glm::mat3 Identity()
{
    glm::mat3 identity = glm::mat3(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f);
    return identity;
}
glm::mat3 Translation(float x, float y)
{
    glm::mat3 translation = glm::mat3(1.0f);
    translation[2][0] = x;
    translation[2][1] = y;
    return translation;
}

glm::mat3 Scale(float scaleX, float scaleY)
{
    glm::mat3 scale = glm::mat3(1.0f);
    scale[0][0] = scaleX;
    scale[1][1] = scaleY;
    return scale;
}

glm::mat3 Rotation(float degree)
{
    float radian = glm::radians(degree);
    glm::mat3 rotation = glm::mat3(
        glm::cos(radian), -glm::sin(radian), 0.0f,
        glm::sin(radian), glm::cos(radian), 0.0f,
        0.0f, 0.0f, 1.0f
    );
    return rotation;
}



#endif // AFFINE_TRANSFORM_H
