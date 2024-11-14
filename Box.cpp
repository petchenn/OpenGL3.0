#include "Box.h"

Box::Box(float size, float offsetX, float offsetY) :
    Figure(size, offsetX, offsetY)
{

}

void Box::draw()
{
    glBegin(GL_QUADS);
    glVertex2f(m_offsetX - m_size / 2, m_offsetY - m_size / 2);
    glVertex2f(m_offsetX + m_size / 2, m_offsetY - m_size / 2);
    glVertex2f(m_offsetX + m_size / 2, m_offsetY + m_size / 2);
    glVertex2f(m_offsetX - m_size / 2, m_offsetY + m_size / 2);
    glEnd();
}

bool Box::isInnerPoint(float x, float y)
{
    if (x > (m_offsetX - (m_size / 2)) && x < (m_offsetX + (m_size / 2)) &&
        y >(m_offsetY - (m_size / 2)) && y < (m_offsetY + (m_size / 2))) {
        std::cout << "in ";
        return true;
    }

	return false;
}
