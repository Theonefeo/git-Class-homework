#include <iostream>
#include "classFigureCross.h"
#include <cmath>

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
void Cross::draw() const
{
    cout<<"Figure - Cross"<<endl;
    cout<<"x, y:  "<<x<<","<<y<<endl;
    cout<<"BorderColor:  "<<getBorderColor()<<endl;
    cout<<"lengthLines  "<<lengthLines<<endl;
    cout<<"thicknessLines  "<<thicknessLines<<endl;
}
void Cross::calcParams(float& perimeter, float& area) const
{
    perimeter = ((lengthLines/2. - thicknessLines/2.)*8) + thicknessLines * 4;
    area = pow((thicknessLines*(lengthLines/2. - thicknessLines/2.)),4);
}
void Cross::setSizes(float lengthLines, float thicknessLines)
{
    this->lengthLines = lengthLines;
	this->thicknessLines = thicknessLines;

	if(isVisible())
    {
    draw();
	}
}
void FilledCross::draw() const
{
    cout<<"Figure - FilledCross"<<endl;
    cout<<"x, y:  "<<x<<","<<y<<endl;
    cout<<"BorderColor:  "<<getBorderColor()<<endl;
    cout<<"lengthLines  "<<lengthLines<<endl;
    cout<<"thicknessLines  "<<thicknessLines<<endl;
    cout<<"fillColor  "<<fillColor<<endl;
}
void FilledCross::setFillColor(int c)
{
	fillColor = c;
	if(isVisible())
    {
    draw();
	}

}
void FilledCross::setBorderColor(int c)
{
	if(fillColor != c)
	{
	   Figure::setBorderColor(c);
	}
}
