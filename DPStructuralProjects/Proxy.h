#pragma once

#include <iostream>
#include <thread>

class IMath
{
public:
    virtual double add(double, double) = 0;
    virtual double sub(double, double) = 0;
    virtual double mul(double, double) = 0;
    virtual double div(double, double) = 0;
    virtual ~IMath() = default;
};

/**
 * "Real Subject"
 */
class Math : public IMath
{
public:
    Math()
    {
        using namespace std::chrono_literals;

        std::cout << "connect at real subject...\n";
        std::this_thread::sleep_for(2000ms);
    }

    virtual double add(double x, double y)
    {
        return x + y;
    }

    virtual double sub(double x, double y)
    {
        return x - y;
    }

    virtual double mul(double x, double y)
    {
        return x * y;
    }

    virtual double div(double x, double y)
    {
        return x / y;
    }

    virtual ~Math()
    {

    }
};

/**
 * "Proxy Object"
 */
class MathProxy : public IMath
{

public:
    MathProxy()
    {
        
    }

    

    virtual double add(double x, double y)
    {
        Math math;
        return math.add(x, y);
    }

    virtual double sub(double x, double y)
    {
        Math math;
        return math.sub(x, y);
    }

    virtual double mul(double x, double y)
    {
        return x * y;
    }

    virtual double div(double x, double y)
    {
        return x / y;
    }
};



