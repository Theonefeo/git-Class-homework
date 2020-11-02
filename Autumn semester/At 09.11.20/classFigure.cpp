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
	Figure(int c, int x, int y) {this->c = c; this->x = x; this->y = y;}
	~Figure();
	void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
	void setBorderColor(int c); //установить цвет фигуры – только видимой
	int getBorderColor() const; // получить цвет
	void setVisible(bool isVisible = true);    // показать/спрятать фигуру
	bool isVisible() const; // признак видимости
	virtual void calcParams(float& perimeter, float& area) const = 0;
	//  вычислить периметр и площадь фигуры
};
class Cross:: public Figure //(цвет линий, х и у центра, радиус1, радиус2, высота)
{
	public:
	int lineColor;
	int radius1;
	int radius2;
	int height;

	void setSizes(int lineColor, int x,y, int radius1, int radius2, int height);
}
class FilledCross:: public Cross
{
    public:

    FilledCross(int c);
    void setFillColor(int c);

}
Добавить к параметрам конструктора нового дочернего класса цвет заполнения.

    Определить дополнительный метод у нового дочернего класса для изменения цвета заполнения:

             void setFillColor(int c);


    Переопределить у нового дочернего класса метод изменения цвета границы:

            void setBorderColor(int c);

           (если новый цвет границы совпадает с текущим цветом заполнения, то цвет границы не изменять)


void Cross::setSizes(int lineColor, int x,y, int radius1, int radius2, int height)
{
	this->lineColor = lineColor;
	this->x,y = x,y;
	this->radius1 = radius1;
	this->radius2 = radius2;
	this->height = height;
}
void Figure::move(int dx, int dy)
{
	x = x + dx;
	y = y + dy;
	if (visible)
		draw();
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
/*Figure::draw()
Figure::calcParams()*/


int main()
{
	Figure figure(1010, 0, 0);
	figure.move(5, 5);
	figure.setBorderColor(0010);
	figure.getBordercolor();
	figure.isVisible();
	figure.setVisible();

	Cross cross();
	cross.setSizes(0110, 1,1, 6, 6, 8);


	return 0;
}
