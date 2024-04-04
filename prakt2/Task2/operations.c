#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include "operations.h"

float sum(float a, float b)
{
    return a+b;
}

float subtract(float a, float b)
{
    return a-b;
}

float mul(float a, float b)
{
    return a*b;
}

float div(float a, float b)
{
    return a/b;
}

float deg(float a, float b)
{
    return pow(a, b);
}

float root(float a, float b)
{
    return pow(a, 1/b);
}