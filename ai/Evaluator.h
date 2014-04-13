#ifndef EVALUATOR_H
#define EVALUATOR_H
 
#include <iostream>
#include "Game.h"

using namespace std;
 
class Evaluator
{
public:
	Evaluator();
  int evaluate(Game*);
  bool stableDirection(Game*, int, int, int, int);
 
};
 
#endif