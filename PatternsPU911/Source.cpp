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

	Composit::Component* filesystem = new Composit::Directory("Файловая система");
	Composit::Component* discC = new Composit::Directory("Диск С");
	Composit::Component* folder1 = new Composit::Directory("Папка 1");
	Composit::Component* folder2 = new Composit::Directory("Папка 2");
	Composit::Component* folder3 = new Composit::Directory("Папка 3");
	Composit::Component* file1 = new Composit::File("Файл 1");
	Composit::Component* file2 = new Composit::File("Файл 2");
	Composit::Component* file3 = new Composit::File("Файл 3");

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