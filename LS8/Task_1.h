#pragma once

template<typename T>
T Div(T a, T b)
{

    if (b == 0)
    {
        throw "Error: Can't be divided by zero!";
    }

    return a / b;
}
