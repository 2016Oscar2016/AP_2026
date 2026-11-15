// dod.cpp – реалізація функції
#include "dod.h"
#include "var.h"

using namespace nsVar;

void nsDod::dod()
{
    a *= x * x / n;         // a(n) = a(n-1) * x^2 / n  – коефіцієнт рекурентності
}