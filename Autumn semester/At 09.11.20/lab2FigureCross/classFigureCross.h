#pragma once
#include <iostream>

using namespace std;

class Figure
{
	int c; //����
	bool visible;
protected:
	int x, y; // ������� �����
	virtual void draw() const = 0;
public:
	Figure(int c, int x, int y) {this->c = c; this->x = x; this->y = y; visible = false;}
	~Figure() {}
	void move(int dx, int dy); // �������� ������ �� (dx,dy) � ������ �������
	void setBorderColor(int c); //���������� ���� ������ � ������ �������
	int getBorderColor() const; // �������� ����
	void setVisible(bool isVisible = true);    // ��������/�������� ������
	bool isVisible() const; // ������� ���������
	virtual void calcParams(float& perimeter, float& area) const = 0;
	//  ��������� �������� � ������� ������
};
class Cross: public Figure //(���� �����, � � � ������, �����, ������� �������)
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
