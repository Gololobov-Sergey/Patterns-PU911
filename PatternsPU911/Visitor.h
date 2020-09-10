#pragma once
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class Visitor;

class Figure
{
public:
	virtual void print() {}
	virtual void accept(Visitor* v) = 0;
};

class Point: public Figure
{
public:
	int x, y;

	Point(int x, int y) :x(x), y(y) {}
	void print()
	{
		cout << "Point: x = " << x << ", y = " << y << endl;
	}
	void accept(Visitor* v) override;
};

class Circle : public Figure
{
public:
	int x, y, r;

	Circle(int x, int y, int r) :x(x), y(y), r(r) {}
	void print()
	{
		cout << "Circle: x = " << x << ", y = " << y << ", R = " << r << endl;
	}
	void accept(Visitor* v) override;

};

class Rectangle : public Figure
{
public:
	int x1, y1, x2, y2;

	Rectangle(int x1, int y1, int x2, int y2) :x1(x1), y1(y1), x2(x2), y2(y2) {}
	void print()
	{
		cout << "Rectangle: P1(" << x1 << ", " << y1 << "), P2(" << x2 << ", " << y2 << ")" << endl;
	}
	void accept(Visitor* v) override;

};

class Visitor
{
public:
	virtual void visit(Point* p) = 0;
	virtual void visit(Circle* c) = 0;
	virtual void visit(Rectangle* r) = 0;
};

class HTMLExportVisitor : public Visitor
{
	string fname;
public:
	HTMLExportVisitor(string n) :fname(n) {}
	void visit(Point* p) override
	{
		string result = "";
		result += "<table border=\"1\"><tr><td>Point</td><td>X = ";
		char buff[10];
		_itoa(p->x, buff, 10);
		result += buff;
		result += "\</td>\<td>Y = ";
		_itoa(p->y, buff, 10);
		result += buff;
		result +="\</td>\</tr>\</table>";
		fstream out(fname, ios::app);
		out << result << endl;
		out.close();
	}

	void visit(Circle* c) override
	{
		string result = "";
		result += "<table border=\"1\"><tr><td>Circle</td><td>X = ";
		char buff[10];
		_itoa(c->x, buff, 10);
		result += buff;
		result += "</td><td>Y = ";
		_itoa(c->y, buff, 10);
		result += buff;
		result += "</td><td>R = ";
		_itoa(c->r, buff, 10);
		result += buff;
		result += "</td></tr></table>";
		fstream out(fname, ios::app);
		out << result << endl;
		out.close();
	}

	void visit(Rectangle* r) override
	{
		string result = "";
		result += "<table border=\"1\"><tr><td>Rectangle</td><td>P1(";
		char buff[10];
		_itoa(r->x1, buff, 10);
		result += buff;
		result += ", ";
		_itoa(r->y1, buff, 10);
		result += buff;
		result += ")</td><td>P2(";
		_itoa(r->x2, buff, 10);
		result += buff;
		result += ", ";
		_itoa(r->y2, buff, 10);
		result += buff;
		result += ")</td></tr></table>";
		fstream out(fname, ios::app);
		out << result << endl;
		out.close();
	}
};

class TXTExportVisitor : public Visitor
{
	string fname;
public:
	TXTExportVisitor(string n) :fname(n) {}
	void visit(Point* p) override
	{
		string result = "";
		result += "Point X = ";
		char buff[10];
		_itoa(p->x, buff, 10);
		result += buff;
		result += " Y = ";
		_itoa(p->y, buff, 10);
		result += buff;
		fstream out(fname, ios::app);
		out << result << endl;
		out.close();
	}

	void visit(Circle* c) override
	{
		string result = "";
		result += "Circle X = ";
		char buff[10];
		_itoa(c->x, buff, 10);
		result += buff;
		result += " Y = ";
		_itoa(c->y, buff, 10);
		result += buff;
		result += " R = ";
		_itoa(c->r, buff, 10);
		result += buff;
	
		fstream out(fname, ios::app);
		out << result << endl;
		out.close();
	}

	void visit(Rectangle* r) override
	{
		string result = "";
		result += "Rectangle P1(";
		char buff[10];
		_itoa(r->x1, buff, 10);
		result += buff;
		result += ", ";
		_itoa(r->y1, buff, 10);
		result += buff;
		result += "), P2(";
		_itoa(r->x2, buff, 10);
		result += buff;
		result += ", ";
		_itoa(r->y2, buff, 10);
		result += buff;
		result += ")";
		fstream out(fname, ios::app);
		out << result << endl;
		out.close();
	}
};

void Point::accept(Visitor* v)
{
	v->visit(this);
}

void Circle::accept(Visitor* v)
{
	v->visit(this);
}

void Rectangle::accept(Visitor* v)
{
	v->visit(this);
}


//Figure* arr[] = { new Point(2,5), new Circle(3,6,7), new Rectangle(1,8,7,4), new Circle(3,6,7) };
//for (auto f : arr)
//f->print();
//Visitor* visitor = new TXTExportVisitor("toTXT.txt");
//for (auto f : arr)
//f->accept(visitor);