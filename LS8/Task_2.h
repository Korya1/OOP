#pragma once
class Ex
{
public:
    Ex(double x) : x(x) {}
    double x;
};

class Bar
{
public:
    Bar(double y = 0.0) : y(y) {};

    void set(double a)
    {
        if ((y + a) > num)
        {
            throw Ex(a * y);
        }
        else
        {
            y = a;
        }
    }

private:
    double y;
    int num{ 100 };
};