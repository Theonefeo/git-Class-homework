#include <iostream>
#include <cmath>
#include "classFigureCross.h"

using namespace std;



/*class FilledCross: public Cross
{
    public:
    int fillColor;



    FilledCross(int c, int x, int y, int lengthLines, int thicknessLines, int fillColor) : Cross(int c, int x, int y, int lengthLines, int thicknessLines, int fillColor)
	{
		this->fillColor = fillColor;
	}
    ~FilledCross();
    void setFillColor(int c);

};

void FilledCross::setFillColor(int c)
{
	fillColor = c; //????
}
void FilledCross::setBorderColor(int c)
{
	if(fillColor == c)
	{
	   this->c = c;
	}
	else
	{
		c = fillColor;
	}
}*/


int main()
{
	/*Figure figure(1010, 0, 0);
	figure.move(5, 5);
	figure.setBorderColor(0010);
	figure.getBordercolor();
	figure.isVisible();
	figure.setVisible();*/

    float perimeter;
    float area;
	Cross cross(1010, 0, 0, 1, 3);
	cross.move(5, 5);
	cross.setBorderColor(0010);
	cout<<endl<<cross.getBorderColor()<<endl;
	cout<<cross.isVisible()<<endl;
	cross.setVisible();
	cross.calcParams(perimeter, area);
	cout<<"Perimeter: "<<perimeter<<" Area: "<<area<<endl;
	cross.setSizes(8, 6);
	cross.calcParams(perimeter, area);
	cout<<"Perimeter: "<<perimeter<<" Area: "<<area<<endl;

	/*FilledCross filledCross();
	filledCross.setFillColor(1111);
	filledCross.setBorderColor(0110);*/


	return 0;
}
