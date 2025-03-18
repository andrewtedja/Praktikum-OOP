#include "NegativeExpression.hpp"
#include <iostream>
using namespace std;

NegativeExpression::NegativeExpression(Expression *x) : UnaryExpression(x) {};

NegativeExpression::~NegativeExpression() {};

int NegativeExpression::solve()
{
    return -x->solve();
}