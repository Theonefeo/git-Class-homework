#include <iostream>
#include "classFigureCross.h"
#include <cmath>

void Cross::draw() const
{
    cout<<"x, y: "<<x<<","<<y<<endl;
    cout<<"Color: "<<getBorderColor()<<endl;
}
void Cross::calcParams(float& perimeter, float& area) const
{
    perimeter = ((lengthLines/2. - thicknessLines/2.)*8) + thicknessLines * 4;
    area = pow((thicknessLines*(lengthLines/2. - thicknessLines/2.)),4);
}
void Cross::setSizes(float lengthLines, float thicknessLines)
{
	if(isVisible())
    {
	this->lengthLines = lengthLines;
	this->thicknessLines = thicknessLines;
	}
	else
    {
    this->lengthLines = lengthLines;
    this->thicknessLines = thicknessLines;
    draw();
    }
}
void Figure::move(int dx, int dy)
{
	if (visible)
    {
        x = x + dx;
        y = y + dy;
        draw();
    }
}
void Figure::setBorderColor(int c)
{
	if (visible)
	{
		this->c = c;
		draw();
	}
}
void Figure::setVisible(bool isVisible)
{
	bool old_visible = visible; //memorizing the visibility status of the figure
	visible = isVisible;
	if (visible && !old_visible) //If the figure was not visible
	{
		draw();
	}
}
int Figure::getBorderColor() const
{
	return c;
}
bool Figure::isVisible() const
{
	return visible;
}
