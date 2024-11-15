#include "Render2D.h"

Render2D::~Render2D()
{

}

void Render2D::draw()
{
    m_objects[0]->draw();
}

void Render2D::addObject(Model2D* model)
{
    m_objects.push_back(model);
}

void Render2D::nextObject()
{
    Model2D* m = *m_objects.begin();
    m_objects.erase(m_objects.begin());
    m_objects.push_back(m);
}

Model2D* Render2D::getCurrentModel() {
    return m_objects[0];
}
