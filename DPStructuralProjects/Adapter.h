#pragma once
#include <iostream>

class ISensorAdapter
{
public:
	virtual double GetSensorData() = 0;
	virtual ~ISensorAdapter() {}
};

class SencorCelsium : public ISensorAdapter
{
public:
	double GetSensorData() override
	{
		return 36.6;
	}
	//
};

class SensorFahrenheit
{
public:
	float TemperatureValue()
	{
		return 25.5;
	}
};

class SensorFahrenheitAdapter : public ISensorAdapter
{
	SensorFahrenheit* sensor;
public:
	SensorFahrenheitAdapter(SensorFahrenheit* sensor)
		: sensor{ sensor } {}
	double GetSensorData() override
	{
		return (sensor->TemperatureValue() - 32) * 5.0 / 9.0;
	}
};

class Client
{
public:
	void ClientMethod()
	{
		ISensorAdapter* sensor = new SencorCelsium();
		std::cout << sensor->GetSensorData() << "\n";
		delete sensor;
		
		sensor = new SensorFahrenheitAdapter(new SensorFahrenheit());
		std::cout << sensor->GetSensorData() << "\n";
		delete sensor;
	}
};

