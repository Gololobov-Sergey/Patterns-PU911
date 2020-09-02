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
				cout << "\t";
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
			t++;
			for (size_t i = 0; i < t; i++)
			{
				cout << "\t";
			}
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

