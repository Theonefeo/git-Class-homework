#pragma once
#include <iostream>

using namespace std;

class Figure
{
	int c; //цвет
	bool visible;
protected:
	int x, y; // базова€ точка
	virtual void draw() const = 0;
public:
	Figure(int c, int x, int y) {this->c = c; this->x = x; this->y = y; visible = false;}
	~Figure() {}
	void move(int dx, int dy); // сместить фигуру на (dx,dy) Ц только видимую
	void setBorderColor(int c); //установить цвет фигуры Ц только видимой
	int getBorderColor() const; // получить цвет
	void setVisible(bool isVisible = true);    // показать/спр€тать фигуру
	bool isVisible() const; // признак видимости
	virtual void calcParams(float& perimeter, float& area) const = 0;
	//  вычислить периметр и площадь фигуры
};
class Cross: public Figure //(цвет линий, х и у центра, длина, толщина полосок)
{
	public:
	float lengthLines;
	float thicknessLines;

    Cross(int c, int x, int y, float lengthLines, float thicknessLines) : Figure(c, x, y)
    {
       setSizes(lengthLines, thicknessLines);
    }
    ~Cross() {}
	void setSizes(float lengthLines, float thicknessLines);
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

};*/
