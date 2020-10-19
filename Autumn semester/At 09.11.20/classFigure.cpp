#include <iostream>

using namespace std;

class Figure
{
	int c; // ����
	bool visible;
protected:
	int x, y; // ������� �����
	virtual void draw() const;
public:
	Figure(int c, int x, int y) {this->c = c; this->x = x; this->y = y;}
	~Figure();
	void move(int dx, int dy); // �������� ������ �� (dx,dy) � ������ �������
	void setBorderColor(int c); // ���������� ���� ������ � ������ �������
	int getBorderColor() const; // �������� ����
	void setVisible(bool isVisible = true);    // ��������/�������� ������
	bool isVisible() const; // ������� ���������
	virtual void calcParams(float& perimeter, float& area) const;
	// ��������� �������� � ������� ������
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
