#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "Evaluator.h"
#include "AlphaBeta.h"
#include "Square.h"
#include "Game.h"
#include "Player.h"
#include "Move.h"

using namespace std;

void testGame()
{
	cout << "Test Game" << endl;
	Game* g = new Game();
	cout << "Board dim " << g->getBoardDim() << endl;
	g->output();
	std::vector<Move*> moves = g->getLegalMoves(Square::COLOR::DARK);
	cout << "Legal moves size " << moves.size() << endl;
	cout << endl;
}

void testSquare()
{
	cout << "Test Square" << endl;
	Square s = new Square;
	cout << "Square color " << s.getColor() << endl;
	cout << endl;
}

void testPlayer()
{
	cout << "Test Player" << endl;

	Player p(Square::COLOR::DARK);
	cout << "Player color " << p.getColor() << endl;

	cout << endl;
}

void testMove()
{
	cout << "Test Move" << endl;

	Move m(4, 5);
	cout << "Move i " << m.getMoveI() << endl;
	cout << "Move j " << m.getMoveJ() << endl;

	cout << endl;
}

int main(int argc, char *argv[])
{
	testGame();
	testSquare();
	testPlayer();
	testMove();
	std::cout << "Hello" << std::endl;
	return 0;
}