#pragma once
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Buyer;

class Product
{
public:
	
	virtual void addBuyer(Buyer* buyer) = 0;
	virtual	void removeBuyer(Buyer* buyer) = 0;
	virtual void notify() = 0;
	virtual string getName() = 0;
	virtual float getPrice() = 0;
};

class Mercedes : public Product
{
	string name;
	float price;
	vector<Buyer*> buyers;
public:
	Mercedes(string n, float p) :name(n), price(p) {}
	void addBuyer(Buyer* buyer) override
	{
		buyers.push_back(buyer);
	}
	void removeBuyer(Buyer* buyer) override
	{
		auto del = find(buyers.begin(), buyers.end(), buyer);
		if(del != buyers.end())
			buyers.erase(del);
	}
	string getName() { return name; }
	float getPrice() { return price; }
	void setPrice(float price)
	{
		if (this->price != price)
		{
			this->price = price;
			notify();
		}
	}
	void notify() override;

};

class Buyer
{
public:
	virtual void update(Product* p) = 0;
};

class UkranianBuyer : public Buyer
{
	Product* product;
	string name;
public:
	UkranianBuyer(string n): name(n){}
	void setProduct(Product* p)
	{
		product = p;
	}
	void update(Product* p)
	{
		cout << "Сообщение для " << name << " по продукту " << p->getName() << " новая цена " << p->getPrice() << endl;
	}
};

void Mercedes::notify()
{
	for (auto b : buyers)
		b->update(this);
}


//Mercedes* mercedes = new Mercedes("Mercedes GLK 500", 100000);
//
//UkranianBuyer* b1 = new UkranianBuyer("Ivan");
//UkranianBuyer* b2 = new UkranianBuyer("Sergey");
//UkranianBuyer* b3 = new UkranianBuyer("Stefan");
//
//mercedes->addBuyer(b1);
//mercedes->addBuyer(b2);
//mercedes->addBuyer(b3);
//
//mercedes->setPrice(90000);
//cout << endl;
//mercedes->setPrice(80000);
//cout << endl;
//mercedes->removeBuyer(b3);
//mercedes->setPrice(70000);