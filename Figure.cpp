#include "Figure.h"

Figure::Figure(int size, int offsetX, int offsetY) :
    m_size(size),
    m_offsetX(offsetX),
    m_offsetY(offsetY),
    m_isDragging(false),
    m_previousX(0),
    m_previousY(0)
{
}

void Figure::moveTo(float x, float y)
{

}

void Figure::move(float x, float y)
{
    m_offsetX = x;
    m_offsetY = y;
    std::cout << "move ";
}

void Figure::startDragging(float x, float y)
{
    m_isDragging = true;
    std::cout << "startd ";
    //drag(x, y);
}

void Figure::drag(float x, float y)
{
    if (isDragging()) {
        move(x, y);
    }
}

bool Figure::isDragging() const
{
    return m_isDragging;
}

void Figure::stopDragging(int x, int y)
{
    m_isDragging = false;
    std::cout << "stopd ";

}
