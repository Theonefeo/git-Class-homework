#include <iostream>

using namespace std;

class Figure
{
	int c; // цвет
	bool visible;
protected:
	int x, y; // базовая точка
	virtual void draw() const;
public:
	Figure(int c, int x, int y) {this->c = c; this->x = x; this->y = y;}
	~Figure();
	void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
	void setBorderColor(int c); // установить цвет фигуры – только видимой
	int getBorderColor() const; // получить цвет
	void setVisible(bool isVisible = true);    // показать/спрятать фигуру
	bool isVisible() const; // признак видимости
	virtual void calcParams(float& perimeter, float& area) const;
	// вычислить периметр и площадь фигуры
};
void Figure::move(int dx, int dy)
{
	x = x + dx;
	y = y + dy;
	//if (visible)
		//draw();
}
void Figure::setBorderColor(int c)
{
	if (visible)
	{
		this->c = c;
		//draw();
	}
}
void Figure::setVisible(bool isVisible = true)
{
	bool old_visible = visible;
	visible = isVisible;
	if (visible && !old_visible)
	{
		//draw();
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

	return 0;
}
