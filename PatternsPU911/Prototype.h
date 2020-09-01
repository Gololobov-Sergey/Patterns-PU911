#pragma once

#include<string>
#include<iostream>


using namespace std;

class IFigure
{
public:
	virtual IFigure* clone() = 0;
	virtual void print() = 0;
};

class Rectangle : public IFigure
{
	int w, h;
public:
	Rectangle(int w, int h) :w(w), h(h) {}
	IFigure* clone() override
	{
		return new Rectangle(w, h);
	}
	void print() override
	{
		cout << "W: " << w << endl;
		cout << "H: " << h << endl;
	}
};

class Circle : public IFigure
{
	int r;
public:
	Circle(int r) :r(r) {}
	IFigure* clone() override
	{
		return new Circle(r);
	}
	void print() override
	{
		cout << "R: " << r << endl;
	}
};

//void method(IFigure* fig)
//{
//	IFigure* fig2 = fig->clone();
//	fig->print();
//	fig2->print();
//}
//
//IFigure* rec = new Circle(15);
//method(rec);