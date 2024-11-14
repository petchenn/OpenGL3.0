#pragma once
#include "pch.h"

class Figure
{
public:
	explicit Figure(int size, int offsetX, int offsetY);
	~Figure() = default;

	virtual void draw() = 0;
	virtual bool isInnerPoint(float x, float y) = 0;

	void moveTo(float x, float y);
	void move(float x, float y);

	void startDragging(float x, float y);
	void drag(float x, float y);
	bool isDragging() const;
	void stopDragging(int x, int y);

private:
	bool m_isDragging;
	float m_previousX;
	float m_previousY;

protected:
	float m_size;
	float m_offsetX;
	float m_offsetY;
};
