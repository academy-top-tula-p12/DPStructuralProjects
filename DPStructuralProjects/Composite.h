#pragma once
#include <iostream>
#include <vector>
#include <string>

class Unit
{
protected:
	std::string name;
	int attack;
	int defence;
public:
	std::string& Name() { return name; }
	Unit(std::string name)
		: name{ name }, attack{}, defence{} {}

	virtual std::string ToString()
	{
		return "Unit " + name
			+ ", attack = " + std::to_string(attack)
			+ ", defence = " + std::to_string(defence);
	}

	virtual int Attack() { return attack; }
	virtual int Defence() { return defence; }

	virtual ~Unit() {}
};

class UnitFactory
{
public:
	virtual Unit* Create() = 0;
	virtual ~UnitFactory() {}
};

class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry") 
	{ 
		attack = 3;
		defence = 4;
	}
};

class InfantryFactory : public UnitFactory
{
public:
	Unit* Create() override
	{
		return new InfantryUnit();
	}
};

class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer")
	{
		attack = 5;
		defence = 2;
	}
};

class ArcherFactory : public UnitFactory
{
public:
	Unit* Create() override
	{
		return new ArcherUnit();
	}
};

class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry")
	{
		attack = 7;
		defence = 4;
	}
};

class CavalryFactory : public UnitFactory
{
public:
	Unit* Create() override
	{
		return new CavalryUnit();
	}
};

class GroupUnit : public Unit
{
	std::vector<Unit*> group;
public:
	GroupUnit(std::string name) : Unit(name) {}

	int Attack() override
	{
		int attackFull{};
		for (Unit* unit : group)
			attackFull += unit->Attack();
		return attackFull; 
	}
	
	int Defence() override
	{
		int defenceFull{};
		for (Unit* unit : group)
			defenceFull += unit->Defence();
		return defenceFull;
	}

	std::string ToString() override
	{
		std::string str = Unit::ToString() + "\n";
		for (Unit* unit : group)
			str += "\t" + unit->ToString() + "\n";
		str += "Full Attack: " + std::to_string(Attack()) + "\n";
		str += "Full Defence: " + std::to_string(Defence()) + "\n";
		
		return str;
	}

	void Add(Unit* unit)
	{
		group.push_back(unit);
	}
};

