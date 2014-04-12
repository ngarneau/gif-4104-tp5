#include "Game.h" 

Game::Game(){
	dim = 8;
	totalDiskNum = dim * dim;

	board.resize(dim);
	//vector< vector<Square*> > board(dim, vector<Square*>(dim));
	for (int i = 0; i < dim; i++) {
		board[i].resize(dim);
    }

	for (int i = 0; i < dim; i++) {
		board[i].resize(dim);
        for (int j = 0; j < dim; j++) {
                board[i][j] = new Square();
        }
    }
    cout << board.size();

	currentDisksNum = 4;
    darkDisksNum = 2;
    lightDisksNum = 2;

    // on configure les 4 premiers disks
	Square* first = board[(dim/2)-1][(dim/2)-1];
	first->setColor(Square::COLOR::LIGHT);
	Square* second = board[(dim/2)-1][dim/2];
	second->setColor(Square::COLOR::DARK);
	Square* third = board[dim/2][(dim/2)-1];
	third->setColor(Square::COLOR::DARK);
	Square* fourth = board[dim/2][dim/2];
	fourth->setColor(Square::COLOR::LIGHT);

	currentPlayer = new Player(Square::COLOR::DARK);
}

void Game::output()
{
	for (int i=0; i<dim; i++)
    {
    	for (int j=0;j<dim; j++)
        {
        	Square* s = board[i][j];
        	Square::COLOR color = s->getColor();
        	switch(color){
        		case Square::COLOR::NONE :
        			cout << ".";
        		break;
        		case Square::COLOR::DARK :
        			cout << "X";
        		break;
        		case Square::COLOR::LIGHT :
        			cout << "O";
        		break;
        	}
        	cout<<" ";
        }
    	cout<<endl;
    }
}

void Game::play(){
	// TODO
}

/*void Game::applyMove(Move move, bool draw){

}*/

bool Game::endCondition(){
	return false;
}

/*vector<Move> Game::getLegalMoves(COLOR color){

}*/

//Square[][] getBoard();

int Game::getBoardDim(){
	return dim;
}

/*Player Game::getCurrentPlayer(){

}*/

int Game::getTotalDisksNum(){
	return totalDiskNum;
}

int Game::getCurrentDisksNum(){
	return currentDisksNum;

}

int Game::getDarkDisksNum(){
	return darkDisksNum;
}

int Game::getLightDisksNum(){
	return lightDisksNum;
}