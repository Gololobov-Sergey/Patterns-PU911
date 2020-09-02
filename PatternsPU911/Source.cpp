#include<iostream>
#include"FactoryMethod.h"
#include"AbstractFactory.h"
#include"Builder.h"
#include"Singleton.h"
#include"Prototype.h"
#include"Decorator.h"
#include"Adapter.h"
#include"Bridge.h"
#include"Composit.h"

using namespace std;



int main()
{
	setlocale(0, "");

	Composit::Component* filesystem = new Composit::Directory("�������� �������");
	Composit::Component* discC = new Composit::Directory("���� �");
	Composit::Component* folder1 = new Composit::Directory("����� 1");
	Composit::Component* folder2 = new Composit::Directory("����� 2");
	Composit::Component* folder3 = new Composit::Directory("����� 3");
	Composit::Component* file1 = new Composit::File("���� 1");
	Composit::Component* file2 = new Composit::File("���� 2");
	Composit::Component* file3 = new Composit::File("���� 3");

	filesystem->add(discC);
	discC->add(folder1);
	discC->add(folder2);
	discC->add(file1);
	folder1->add(folder3);
	folder3->add(file2);
	folder3->add(file3);

	filesystem->print();

	system("pause");
}