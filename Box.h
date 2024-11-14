#pragma once
#include "Figure.h"

class Box : public Figure
{
public:
	explicit Box(float size, float offsetX, float offsetY);

	void draw() override;
	bool isInnerPoint(float x, float y) override;
};

