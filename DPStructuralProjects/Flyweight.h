#pragma once
#include <iostream>
#include <map>

class House
{
protected:
	int stages;
	std::string image;
public:
	virtual void Build(double x, double y) = 0;
};

class PanelHause : public House
{
public:
	PanelHause() { stages = 9; image = "texture_panel.jpg"; }

	void Build(double x, double y) override
	{
		std::cout << "Panel house is build:\n"
			<< "Stages: " << stages << "\n"
			<< "Texture: " << image << "\n"
			<< "x = " << x << ", y = " << y << "\n\n";
	}
};

class BrickHause : public House
{
public:
	BrickHause() { stages = 5; image = "texture_brick.jpg"; }

	void Build(double x, double y) override
	{
		std::cout << "Brick house is build:\n"
			<< "Stages: " << stages << "\n"
			<< "Texture: " << image << "\n"
			<< "x = " << x << ", y = " << y << "\n\n";
	}
};

class HauseFactory
{
	std::map<std::string, House*> houses;
public:
	HauseFactory()
	{
		houses.insert(std::make_pair("Panel", new PanelHause()));
		houses.insert(std::make_pair("Brick", new BrickHause()));
	}

	House* GetHouse(std::string key)
	{
		if (houses.find(key) != houses.end())
			return houses[key];
		else
			return nullptr;
	}
};

