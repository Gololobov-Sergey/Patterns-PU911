#pragma once
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class MCComponent
{
public:
	virtual string toString() = 0;
};


class Radio : public MCComponent
{
public:
	string toString() override
	{
		return "Radio";
	}
};

class CD : public MCComponent
{
public:
	string toString() override
	{
		return "CD";
	}
};

class BlueRay : public MCComponent
{
public:
	string toString() override
	{
		return "Blue Ray";
	}
};

class Subwoofer : public MCComponent
{
public:
	string toString() override
	{
		return "Subwoofer";
	}
};

class MusicCenter
{
public:
	vector<MCComponent*> parts;
	void print() const
	{
		cout << "Music Center parts:" << endl;
		for (size_t i = 0; i < parts.size(); i++)
		{
			cout << parts[i]->toString() << endl;
		}
	}
};


class ManualMC
{
	string text = "MANUAL for MUSIC CENTER\n";
public:
	void addText(string text)
	{
		this->text += text;
	}
	string getText()
	{
		return text;
	}
};

class Builder
{
public:
	virtual ~Builder() {}
	virtual void createRadio() const = 0;
	virtual void createCD() const = 0;
	virtual void createBR() const = 0;
	virtual void createSW() const = 0;
};


class MusicCenterBuilder : public Builder
{
	MusicCenter* mc;
public:
	MusicCenterBuilder()
	{
		this->reset();
	}
	~MusicCenterBuilder() { delete mc; }
	void reset()
	{
		this->mc = new MusicCenter();
	}
	void createRadio() const override
	{
		this->mc->parts.push_back(new Radio);
	}
	void createCD()const override
	{
		this->mc->parts.push_back(new CD);
	}
	void createBR()const override
	{
		this->mc->parts.push_back(new BlueRay);
	}
	void createSW()const override
	{
		this->mc->parts.push_back(new Subwoofer);
	}
	MusicCenter* getResalt()
	{
		MusicCenter* result = this->mc;
		this->reset();
		return result;
	}
};

class ManualMCBuilder : public Builder
{
	ManualMC* manual;
public:
	ManualMCBuilder()
	{
		this->reset();
	}
	~ManualMCBuilder()
	{
		delete manual;
	}
	void reset()
	{
		this->manual = new ManualMC;
	}
	void createRadio() const override
	{
		this->manual->addText("Для пользования радиом нажмите кнопку 1\n");
	}
	void createCD() const override
	{
		this->manual->addText("Для пользования CD нажмите кнопку 2, затем 4\n");
	}
	void createBR() const override
	{
		this->manual->addText("Для пользования BR нажмите кнопку 5, затем 3\n");
	}
	void createSW() const override
	{
		this->manual->addText("Для пользования сабвуфером нажмите кнопку 6\n");
	}
	ManualMC* getResult()
	{
		ManualMC* result = this->manual;
		this->reset();
		return result;
	}
};


class Director
{
	Builder* builder;
public:
	void setBuilder(Builder* builder)
	{
		this->builder = builder;
	}
	void buildMiniMC()
	{
		this->builder->createRadio();
		this->builder->createCD();
	}
	void buildMaxiMC()
	{
		this->builder->createRadio();
		this->builder->createBR();
		this->builder->createCD();
		this->builder->createSW();
	}
};


//Director* director = new Director;
//MusicCenterBuilder* builderMC = new MusicCenterBuilder;
//director->setBuilder(builderMC);
//director->buildMaxiMC();
//
//MusicCenter* mc = builderMC->getResalt();
//mc->print();
//
//ManualMCBuilder* builderManual = new ManualMCBuilder;
//director->setBuilder(builderManual);
//director->buildMaxiMC();
//ManualMC* manual = builderManual->getResult();
//cout << manual->getText() << endl;