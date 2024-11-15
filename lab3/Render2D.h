#pragma once
#include "Model2D.h"

class Render2D
{
public:
    Render2D() = default;
    ~Render2D();

    void draw();
    void addObject(Model2D* model);
    void nextObject();

    Model2D* getCurrentModel();

private:
    std::vector<Model2D*> m_objects;
};
