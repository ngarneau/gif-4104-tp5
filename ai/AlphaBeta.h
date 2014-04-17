#ifndef ALPHABETA_H
#define ALPHABETA_H
 
using namespace std;
 
class Evaluator;
class Move;
class Game;

class AlphaBeta
{
private:
	int maxDepth;
	int nbCores;
	Evaluator* evaluator;
public:
	AlphaBeta();
  	Move* getDecision(Game*);
  	int maxDecision(Game*, int, int&, int&);
  	int minDecision(Game*, int, int&, int&);
  	void setMaxDepth(int);
    void setCores(int);
 
};
 
#endif