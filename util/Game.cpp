#include "Game.h" 

Game::Game(){
	dim = 8;
	totalDiskNum = dim * dim;

	board.resize(dim);
	for (int i = 0; i < dim; i++) {
		board[i].resize(dim);
    }

	for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
                board[i][j] = new Square();
        }
    }

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

Game::Game(Game* game) {
    dim = game->getBoardDim();
    totalDiskNum = game->getTotalDisksNum();
	board.resize(dim);
	for (int i = 0; i < dim; i++) {
		board[i].resize(dim);
    }

    for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                    board[i][j] = new Square(game->getBoard()[i][j]);
            }
    }
    currentDisksNum = game->getCurrentDisksNum();
    darkDisksNum = game->getDarkDisksNum();
    lightDisksNum = game->getLightDisksNum();
    currentPlayer = new Player(game->getCurrentPlayer());
}

Game::~Game(){
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
                delete board[i][j];
        }
    }
    delete currentPlayer;
}

vector< vector<Square*> > Game::getBoard() {
    return board;
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

void Game::applyMove(Move* move, bool draw){
    int i = move->getMoveI();
    int j = move->getMoveJ();
    Square::COLOR color = currentPlayer->getColor();
    (board[i][j])->setColor(color);
    currentDisksNum++;
    increment(color);
    
    if (testSingleDirection(i, j, -1, -1, color)) {
            switchSingleDirection(i, j, -1, -1, draw);
    }
    if (testSingleDirection(i, j, -1, 0, color)) {
            switchSingleDirection(i, j, -1, 0, draw);
    }
    if (testSingleDirection(i, j, -1, +1, color)) {
            switchSingleDirection(i, j, -1, +1, draw);
    }
    if (testSingleDirection(i, j, 0, -1, color)) {
            switchSingleDirection(i, j, 0, -1, draw);
    }
    if (testSingleDirection(i, j, 0, +1, color)) {
            switchSingleDirection(i, j, 0, +1, draw);
    }
    if (testSingleDirection(i, j, +1, -1, color)) {
            switchSingleDirection(i, j, +1, -1, draw);
    }
    if (testSingleDirection(i, j, +1, 0, color)) {
            switchSingleDirection(i, j, +1, 0, draw);
    }
    if (testSingleDirection(i, j, +1, +1, color)) {
            switchSingleDirection(i, j, +1, +1, draw);
    }
}

void Game::switchSingleDirection(int i, int j, int h, int v, bool draw) {
    while ( (board[i+v][j+h])->getColor() == currentPlayer->getAdversaryColor()) {
        switchDisk(i+v, j+h, draw);
        i = i + v;
        j = j + h;
    }
}

void Game::switchDisk(int i, int j, bool draw) {
    decrement( (board[i][j])->getColor());
    (board[i][j])->switchColor();
    increment( (board[i][j])->getColor());
}

bool Game::endCondition(){
  	if ( ( currentDisksNum >= totalDiskNum ) ||
         ( getLegalMoves(Square::COLOR::DARK).size() == 0 && getLegalMoves(Square::COLOR::LIGHT).size() == 0) ) {
            return true;
    }
    return false;
}

vector<Move*> Game::getLegalMoves(Square::COLOR color){
	vector<Move*> legalMoves;
	int i,j;
	for (i = 0; i < dim; i++) 
	{
		for (j = 0; j < dim; j++) 
		{
			if (testLegal(i, j, color)) 
			{
				Move* m = new Move(i, j); 
				legalMoves.push_back(m);
			}
		}
	}
	return legalMoves;
}

bool Game::testLegal(int i, int j, Square::COLOR color) {
    // valid coordinates
    if (i < 0 || i >= dim || j < 0 || j >= dim) {
            return false;
    }
    // square is free
    if ( (board[i][j])->getColor() != Square::COLOR::NONE) {
            return false;
    }
    // it produce at least a switch
    if (testSingleDirection(i, j, -1, -1, color)) {
            return true;
    }
    if (testSingleDirection(i, j, -1, 0, color)) {
            return true;
    }
    if (testSingleDirection(i, j, -1, +1, color)) {
            return true;
    }
    if (testSingleDirection(i, j, 0, -1, color)) {
            return true;
    }
    if (testSingleDirection(i, j, 0, +1, color)) {
            return true;
    }
    if (testSingleDirection(i, j, +1, -1, color)) {
            return true;
    }
    if (testSingleDirection(i, j, +1, 0, color)) {
            return true;
    }
    if (testSingleDirection(i, j, +1, +1, color)) {
            return true;
    }
    return false;
}

bool Game::testSingleDirection(int i, int j, int h, int v, Square::COLOR color) {
                
    Square::COLOR adversaryColor;
    if (color == Square::COLOR::DARK){
        adversaryColor = Square::COLOR::LIGHT;
    }
    else{
        adversaryColor = Square::COLOR::DARK;
    }
    
    bool atLeastOne = false;
    while (i+v < dim && j+h < dim &&
               i+v >= 0 && j+h >= 0 &&
               (board[i+v][j+h])->getColor() == adversaryColor) {
            
            i = i + v;
            j = j + h;
            atLeastOne = true;
    }
    if (i+v < dim && j+h < dim &&
            i+v >= 0 && j+h >= 0 &&
            atLeastOne &&
            (board[i+v][j+h])->getColor() == color) {
            
            return true;
    }
    return false;
}

void Game::increment(Square::COLOR color) {
    if (color == Square::COLOR::DARK) {
       	darkDisksNum++;
    }
    else {
       	lightDisksNum++;
    }
}

void Game::decrement(Square::COLOR color) {
    if (color == Square::COLOR::DARK) {
        darkDisksNum--;
    }
    else {
        lightDisksNum--;
    }
}

int Game::getBoardDim(){
	return dim;
}

Player Game::getCurrentPlayer(){
	return currentPlayer;
}

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