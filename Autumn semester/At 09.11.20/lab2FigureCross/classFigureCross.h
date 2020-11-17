#pragma once
#include <iostream>

using namespace std;

class Figure
{
	int c; //Color
	bool visible;
protected:
	int x, y; //base point
	virtual void draw() const = 0;
public:
	Figure(int c, int x, int y) {this->c = c; this->x = x; this->y = y; visible = false;}
	virtual ~Figure() {cout<<endl<<"delete object Figure"<<endl;}
	void move(int dx, int dy); // Move the shape to (dx, dy) - only the visible
	void setBorderColor(int c); //to set the color of the shape - only visible
	int getBorderColor() const; // getting color
	void setVisible(bool isVisible = true);    // show/hide shape
	bool isVisible() const; // visibility flag
	virtual void calcParams(float& perimeter, float& area) const = 0;
	//  calculate the perimeter and area of the shape
};
class Cross: public Figure //(color line, x and y center, length, thickness)
{
	public:
	float lengthLines;
	float thicknessLines;

    Cross(int c, int x, int y, float lengthLines, float thicknessLines) : Figure(c, x, y)
    {
       setSizes(lengthLines, thicknessLines);
    }
    ~Cross() {cout<<endl<<"delete object Cross"<<endl;}
	void setSizes(float lengthLines, float thicknessLines);
	void draw() const;
	void calcParams(float& perimeter, float& area) const;
};
class FilledCross: public Cross
{
    public:
    int fillColor;

    FilledCross(int c, int x, int y, int lengthLines, int thicknessLines, int fillColor) : Cross(c, x, y, lengthLines, thicknessLines)
	{
		this->fillColor = fillColor;
	}
    ~FilledCross() {cout<<endl<<"delete object FilledCross"<<endl;}
    void setFillColor(int c);
    void setBorderColor(int c);
    void draw() const;

};
