#pragma once
#include <iostream>
#include "Bridge.h"

class SgPlayer : public IPlayer
{
	std::string name;
public:
	std::string& Name() { return name; }
};

class StrategyGame : public IGame
{
	std::vector<IPlayer*> players;
public:
	StrategyGame(IImplementation* impl) : IGame(impl) 
	{
		players.resize(2);
	}

	void Setup() override
	{
		impl->SetupImpl(players);
	}

	void Step() override
	{
		impl->StepImpl(players);
	}

	void Process()
	{
		do
		{
			Step();
			View();
		} while (Validate());
	}

	bool Validate() override
	{
		return impl->ValidateImpl();
	}

	void View() override
	{
		impl->ViewImpl(players);
	}
};


class KeyboradImplementation : public IImplementation
{
public:
	void SetupImpl(std::vector<IPlayer*>& players) override
	{
		std::cout << "console input:\n";
		for (int i = 0; i < players.size(); i++)
		{
			players[i] = new SgPlayer();
			std::cout << "input " << i + 1 << " player's name: ";
			std::cin >> ((SgPlayer*)players[i])->Name();
		}
	}

	void StepImpl(std::vector<IPlayer*> players) override
	{
		std::cout << "console step:\n";
		for (auto p : players)
			std::cout << "player " << ((SgPlayer*)p)->Name() << " step\n";
	}

	void ViewImpl(std::vector<IPlayer*> players) override
	{
		std::cout << "console view:\n";
		for (auto p : players)
			std::cout << "********* player " << ((SgPlayer*)p)->Name() << " view\n";
	}
	bool ValidateImpl() override
	{
		char ch;
		std::cout << "continue? <y/n>: ";
		std::cin >> ch;
		return ch != 'n';
	}
};

