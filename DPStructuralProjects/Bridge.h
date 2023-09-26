#pragma once
#include <vector>

class IPlayer
{
};

class IImplementation
{
public:
	virtual void SetupImpl(std::vector<IPlayer*>&) = 0;
	virtual void StepImpl(std::vector<IPlayer*>) = 0;
	virtual void ViewImpl(std::vector<IPlayer*>) = 0;
	virtual bool ValidateImpl() = 0;
};

class IGame
{
protected:
	IImplementation* impl;
public:
	IGame(IImplementation* impl) : impl{ impl } {}
	virtual IImplementation*& Implementation() { return impl; }

	virtual void Setup() = 0;
	virtual void Step() = 0;
	virtual void Process() = 0;
	virtual bool Validate() = 0;
	virtual void View() = 0;

	virtual ~IGame() {}
};

