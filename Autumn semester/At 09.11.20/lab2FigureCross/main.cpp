#include <iostream>

using namespace std;

class Figure
{
	int c; //цвет
	bool visible;
protected:
	int x, y; // базовая точка
	virtual void draw() const = 0;
public:
	Figure(int c, int x, int y) {this->c = c; this->x = x; this->y = y; visible = false;}
	~Figure();
	void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
	void setBorderColor(int c); //установить цвет фигуры – только видимой
	int getBorderColor() const; // получить цвет
	void setVisible(bool isVisible = true);    // показать/спрятать фигуру
	bool isVisible() const; // признак видимости
	virtual void calcParams(float& perimeter, float& area) const = 0;
	//  вычислить периметр и площадь фигуры
};
class Cross: public Figure //(цвет линий, х и у центра, длина, толщина полосок)
{
	public:
	int lengthLines;
	int thicknessLines;

    Cross(int c, int x, int y, int lengthLines, int thicknessLines) : Figure(c, x, y)
    {
       setSizes(lengthLines, thicknessLines);
    }
    ~Cross();
	void setSizes(int lengthLines, int thicknessLines);
	void draw() const;
	void calcParams(float& perimeter, float& area) const;
};
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
void draw() const
{
    cout<<;
}
void Cross::setSizes(int lengthLines, int thicknessLines)
{
	if(visible)
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
void Figure::setVisible(bool isVisible = true)
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

int main()
{
	Figure figure(1010, 0, 0);
	figure.move(5, 5);
	figure.setBorderColor(0010);
	figure.getBordercolor();
	figure.isVisible();
	figure.setVisible();

	Cross cross();
	cross.Cross(1011, 2, 3, 4, 5)
	cross.setSizes(6, 8);

	FilledCross filledCross();
	filledCross.setFillColor(1111);
	filledCross.setBorderColor(0110);


	return 0;
}
