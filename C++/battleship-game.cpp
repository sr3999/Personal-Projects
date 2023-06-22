#include <iostream>
#include <string>
using namespace std;

const int BOARD_WIDTH = 15;
const int BOARD_HEIGHT = 10;
const int SHIP_TYPES = 5;

const char isWATER = 247;
const char isHIT = 'X';
const char isSHIP = 'S';
const char isMISS = '0';

struct POINT {
	
	int X;
	int Y;
};

struct SHIP {
	
	string name;
	
	int length;
	
	POINT onGrid[5]; 
	
	bool hitFlag[5];
}ship[SHIP_TYPES];

struct PLAYER {
	char grid[BOARD_WIDTH][BOARD_HEIGHT];
}player[3]; 

enum DIRECTION {HORIZONTAL,VERTICAL};
struct PLACESHIPS {
	DIRECTION direction;
	SHIP shipType;
};

bool gameRunning = false;


void LoadShips();
void ResetBoard();
void DrawBoard(int);
PLACESHIPS UserInputShipPlacement();
bool UserInputAttack(int&,int&,int);
bool GameOverCheck(int);

int main()
{
	LoadShips();
	ResetBoard();

	 
	for (int aplyr=1; aplyr<3; ++aplyr)
	{
		
		for (int thisShip=0; thisShip<SHIP_TYPES; ++thisShip)
		{
			
			system("cls");
			DrawBoard(aplyr);
			
			cout << "\n";
			cout << "INSTRUCTIONS (Player " << aplyr << ")\n\n";
			cout << "You are about to place your ships.  Format should be:\n";
			cout << "Facing (0:Horizontal, 1:Vertical), X (Top Coordinates), Y (Side Coordinates)\n";
			cout << "Example: 0 3 5 , would place a horizontal ship at X:3 Y:5\n\n";
			cout << "Now placing the " << ship[thisShip].name << ", length: " << ship[thisShip].length  << "\n";
			cout << "Where would you like it to be placed? ";
			
			
			PLACESHIPS aShip;
			aShip.shipType.onGrid[0].X = -1;
			while (aShip.shipType.onGrid[0].X == -1)
			{
				aShip = UserInputShipPlacement();
			}

			
			aShip.shipType.length = ship[thisShip].length;
			aShip.shipType.name = ship[thisShip].name;

			
			player[aplyr].grid[aShip.shipType.onGrid[0].X][aShip.shipType.onGrid[0].Y] = isSHIP;

			
			for (int i=1; i<aShip.shipType.length; ++i)
			{
				if (aShip.direction == HORIZONTAL){
					aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i-1].X+1;
					aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i-1].Y; }
				if (aShip.direction == VERTICAL){
					aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i-1].Y+1;
					aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i-1].X; }

				
				player[aplyr].grid[aShip.shipType.onGrid[i].X][aShip.shipType.onGrid[i].Y] = isSHIP;
			}
			
		}
		
	}

	
	gameRunning = true;
	int thisPlayer = 1;
	do {
		
		int enemyPlayer;
		if (thisPlayer == 1) enemyPlayer = 2;
		if (thisPlayer == 2) enemyPlayer = 1;
		system("cls");
		DrawBoard(enemyPlayer);

		
		bool goodInput = false;
		int x,y;
		while (goodInput == false) {
			goodInput = UserInputAttack(x,y,thisPlayer);
		}

		
		if (player[enemyPlayer].grid[x][y] == isSHIP) player[enemyPlayer].grid[x][y] = isHIT;
		if (player[enemyPlayer].grid[x][y] == isWATER) player[enemyPlayer].grid[x][y] = isMISS;

		
		int aWin = GameOverCheck(enemyPlayer);
		if (aWin != 0) {
			gameRunning = false;
			break;
		}
	
		thisPlayer = (thisPlayer == 1) ? 2 : 1;
	} while (gameRunning);

	system("cls");
	cout << "\n\nCONGRATULATIONS  PLAYER " << thisPlayer << ", YOU HAVE WON THE GAME!\n\n\n\n";

	system("pause");
	return 0;
}


bool GameOverCheck(int enemyPLAYER)
{
	bool winner = true;
	
	for (int w=0; w<BOARD_WIDTH; ++w){
			for (int h=0; h<BOARD_HEIGHT; ++h){
				
				if (player[enemyPLAYER].grid[w][h] = isSHIP)
					{
						winner = false;
						return winner;
					}
		}}
	
	return winner;
}


bool UserInputAttack(int& x, int& y, int theplayer)
{
	cout << "\nPLAYER " << theplayer << ", ENTER COORDINATES TO ATTACK: ";
	bool goodInput = false;
	cin >> x >> y;
	if (x<0 || x>=BOARD_WIDTH) return goodInput;
	if (y<0 || y>=BOARD_HEIGHT) return goodInput;
	goodInput = true; 
	return goodInput;
}

PLACESHIPS UserInputShipPlacement()
{
	int d, x, y;
	PLACESHIPS tmp;
	
	tmp.shipType.onGrid[0].X = -1;

	cin >> d >> x >> y;
	if (d!=0 && d!=1) return tmp;
	if (x<0 || x>=BOARD_WIDTH) return tmp;
	if (y<0 || y>=BOARD_HEIGHT) return tmp;
	
	tmp.direction = (DIRECTION)d;
	tmp.shipType.onGrid[0].X = x;
	tmp.shipType.onGrid[0].Y = y;
	return tmp;
}

void LoadShips()
{
	
	
	
	ship[0].name = "Destroyer"; ship[0].length = 2;
	ship[1].name = "Cruiser"; ship[1].length = 3;
	ship[2].name = "Submarine"; ship[2].length = 3;
	ship[3].name = "Battleship"; ship[3].length = 4;
	ship[4].name = "Carrier"; ship[4].length = 5;
}
void ResetBoard()
{
	
	for (int plyr=1; plyr<3; ++plyr)
	{
		
		for (int w=0; w<BOARD_WIDTH; ++w){
			for (int h=0; h<BOARD_HEIGHT; ++h){
				player[plyr].grid[w][h] = isWATER;
		}}
		
	}
}

void DrawBoard(int thisPlayer)
{
	
	cout << "PLAYER " << thisPlayer << "'s GAME BOARD\n";
	cout << "----------------------\n";

	
	cout << "   ";
	for (int w=0; w<BOARD_WIDTH; ++w) {
		if (w < 10)
			
			cout << w << "  ";
		else if (w >= 10)
		
			cout << w << " ";
	}
	cout << "\n";

	
	for (int h=0; h<BOARD_HEIGHT; ++h){
		for (int w=0; w<BOARD_WIDTH; ++w){
			
			
			if (w==0) cout << h << " ";
			
			if (w<10 && w==0) cout << " ";
			
			if (gameRunning == false) cout << player[thisPlayer].grid[w][h] << "  ";
			
			if (gameRunning == true && player[thisPlayer].grid[w][h] != isSHIP) 
			{cout << player[thisPlayer].grid[w][h] << "  ";}
			
			else if (gameRunning == true && player[thisPlayer].grid[w][h] == isSHIP)
			{cout << isWATER << "  ";}	
		
			if (w == BOARD_WIDTH-1) cout << "\n";
		}
	}
}
