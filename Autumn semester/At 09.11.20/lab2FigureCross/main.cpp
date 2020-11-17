#include <iostream>
#include <cmath>
#include "classFigureCross.h"

using namespace std;

int main()
{
    float perimeter;
    float area;
    cout<<"Test #1"<<endl;
	Cross *cross = new Cross(1010, 0, 0, 1, 3);
	cout<<"is Visible? "<<cross->isVisible()<<endl;
	cross->setVisible(1);
	cout<<"is Visible? "<<cross->isVisible()<<endl;
	cross->move(5, 5);
	cout<<"//////////////"<<endl;
	cross->setBorderColor(0010);
	cout<<endl<<"BorderColor "<<cross->getBorderColor()<<endl;
	cout<<"is Visible? "<<cross->isVisible()<<endl;
	cross->setVisible();
	cross->calcParams(perimeter, area);
	cout<<"Perimeter: "<<perimeter<<" Area: "<<area<<endl;
	cout<<"//////////////"<<endl;
	cross->setSizes(8, 6);
	cross->calcParams(perimeter, area);
	cout<<"Perimeter: "<<perimeter<<" Area: "<<area<<endl;
	cout<<"//////////////"<<endl;

    cout<<"Test #2"<<endl;
	FilledCross *filledCross = new FilledCross(1010, 0, 0, 8, 6, 1110);
	filledCross->setVisible();
	cout<<"//////////////"<<endl;
	filledCross->setFillColor(1111);
	cout<<"//////////////"<<endl;
	filledCross->setBorderColor(0110);

	cout<<"Test #3"<<endl;
	Figure *f;
	f = cross;
    f->move(4,4);
	delete f;

	cout<<"Test #4"<<endl;
	f = filledCross;
	f->move(8,8);
	delete f;

	return 0;
}
