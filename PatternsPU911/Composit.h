#pragma once
#include<string>
#include<iostream>
#include<list>


using namespace std;

namespace Composit {

	class Component
	{
	protected:
		static int t;
		string name;
	public:
		Component(string n) :name(n) {}
		virtual void add(Component* comp) {}
		virtual void print() 
		{
			for (size_t i = 0; i < t; i++)
			{
				cout << "    ";
			}
			cout << name << endl; 
		}
	};

	int Component::t = 0;

	class Directory : public Component
	{
		list<Component*> components;
	public:
		Directory(string n) :Component(n) {}
		void add(Component* comp)
		{
			components.push_back(comp);
		}
		void print()
		{
			
			for (size_t i = 0; i < t; i++)
			{
				cout << "    ";
			}
			t++;
			cout << "Directory: " << name << endl;
			//cout << "Content:" << endl;
			
			for (auto x : components)
			{
				x->print();
			}
			t--;
		}
	};

	class File : public Component
	{
	public:
		File(string n) :Component(n) {}
	};
}

//Composit::Component* filesystem = new Composit::Directory("Файловая система");
//Composit::Component* discC = new Composit::Directory("Диск С");
//Composit::Component* folder1 = new Composit::Directory("Папка 1");
//Composit::Component* folder2 = new Composit::Directory("Папка 2");
//Composit::Component* folder3 = new Composit::Directory("Папка 3");
//Composit::Component* file1 = new Composit::File("Файл 1");
//Composit::Component* file2 = new Composit::File("Файл 2");
//Composit::Component* file3 = new Composit::File("Файл 3");
//
//filesystem->add(discC);
//discC->add(folder1);
//discC->add(folder2);
//discC->add(file1);
//folder1->add(folder3);
//folder3->add(file2);
//folder3->add(file3);
//
//filesystem->print();