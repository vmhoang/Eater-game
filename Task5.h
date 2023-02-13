/*********** Declaration******* I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. 
 *  No part of the code has been written/produced for me by another person or copied from any other source. 
 * I hold a copy of this assignment that I can produce if the original is lost or damaged. **************************/ 
#ifndef assigment1
#define assigment1

class Board{
    private:
        int **table;
        int noOfMoves = 0;
        int size;
        int player = 1;
        int done  = 0;
        int choice = 0;
        int holder_row = 0;
        int holder_col = 1;
        int player_eater_passer;
        int bot_eater_passer;
        char player_symbol = 'P';
        int P_win_counter = 0;
    public:
        Board(){
            cout << "Please enter the size of the board: ";
            cout <<endl;
            cin >> size;
            cout <<endl;
            table = new int*[size];// add memory to the row
            for (int i = 0; i < size; i++){
                table[i]= new int [size]; // add memory to the column
            }
            play();
        }
        void displayBoard();
        bool isValidMove(int, int);
        bool getMove(int&,int&);
        void player_human();
        void addMove(int, int);
        int gameStatus(int&);
        bool straigh_line_player(int& , int&);
        bool random_player(int& , int&);
        void choice_1();
        void choice_2();
        void choice_3();
        void play();
        void switch_player();
        bool check_adjacent(int , int);
        bool check_col(int , int);
        bool P_winning();
        ~Board();
};
Board::~Board(){
    for (int i = 0; i< size; i++){
        delete[] table[i];
    }
    delete[] table;
}
void Board::displayBoard(){
    for (int n = 1; n <= size; n++){
        if (n == 1){
            cout <<"   " << n;
        }
        else{
            cout <<"    " << n;
        }
    }
    cout << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1;
		for (int j = 0; j < size; j++) {
			char playerSymbol = ' ';
			if (table[i][j] == 1){
				playerSymbol = 'P';
            }
			else if (table[i][j] == -1){
				playerSymbol = 'E';
            }
			cout << setw(3) << playerSymbol;
			if (j != (size)){
                if (j < 9 ){
                    cout << " |";

                }
                else{
                    cout << "| ";
                }
            }
		}
		cout << endl;
		if (i != (size))
            for (int m = 0; m <= size; m++){
			    //cout << " ____|____|____" << endl << "     |    |    " << endl;
                if (m == 0){
                    cout << "  ";
                }
                else if (m >= 10 && m < size){
                    cout << " ___|_";
                    
                }
                else if ( m == size){
                    cout << "___|";
                }
                else{
                    cout << "___|_";
                }
            }
            cout << endl;
            cout << " ";
            for (int m = 0; m < size; m++){
			    //cout << " ____|____|____" << endl << "     |    |    " << endl;
                cout << "    |" ;
            }
            cout <<endl;
	}
	cout << endl ;
}
bool Board::isValidMove(int x, int y){
    //passer rules
    if (player == 1){ 
        if (x >= 0 && x <= size && y >= 0 && y <= size && table[x-1][y-1] == 0 ){
            return true;
        }
        else{
            cout << "Invalid. Please try again !"<<endl;
            return false;
        }
    }
    //Eater rules
    if (player == -1){
        if (x >= 0 && x <= size && y >= 0 && y <= size && table[x-1][y-1] == 0){
            return true;
        }
        else if (x >= 0 && x <= size && y >= 0 && y <= size && table[x-1][y-1] == 1){
            return true;
        }
        else{
            cout << "Invalid. Please try again !"<<endl;
            return false;
        }
    }
    
    return false;
}
bool Board::getMove(int& x, int& y){
    if (noOfMoves >= (size*size))
		return false;
	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(row, col));
	x = row - 1;
	y = col - 1;
	return true;
}
void Board::addMove(int x, int y){
    table[x][y] = player;
}
int Board::gameStatus(int& x){
    if (x >= (size*size)){
        return -1;
    }
	return 0;
}

void Board::player_human(){
    int x, y;
    getMove(x, y);
	addMove(x, y);
}
bool Board::random_player(int& x, int& y){
    if (noOfMoves >= (size*size))
		return false;
	int row, col;
	do {
		row = rand()% size + 1;
        col = rand()% size + 1;
	} while (!isValidMove(row, col));
    cout << row <<endl;
    cout << col << endl;
	x = row - 1;
	y = col - 1;
    addMove(x, y);
	return true;

}
bool Board::straigh_line_player(int& x, int& y){
    if (noOfMoves >= (size*size))
		return false;
	int row, col;
    row = holder_row;
    col = holder_col;
	do {
		if (col == size){
            col = 0;
            row ++;
        }
        else{
            col ++;
        }
	} while (!isValidMove(row, col));
	x = row - 1;
	y = col - 1;
    addMove(x, y);
    holder_col = col;
    holder_row = row;
	return true;
}
void Board::switch_player(){
    if (player == 1){
        player = - 1;
        player_symbol = 'E';
    }
    else if (player == -1){
        player = 1;
        player_symbol = 'P';
    }
}
void Board::choice_1(){
    int x, y;
    if (player == -1){
        switch_player();
    }
    cout << "Player " << player_symbol << " enter move: " <<endl;
    player_human();
    switch_player();
    cout << "Player " << player_symbol << " enter move: "<<endl;
    player_human();
    displayBoard();
    noOfMoves += 2;
    done = gameStatus(noOfMoves);
}
void Board::choice_2(){
    int x, y;
    if (player_eater_passer == 1){
        if (player == -1){
            switch_player();
        }
        cout << "Player " << player_symbol << " enter move: " <<endl;
        player_human();
        switch_player();
        cout << "Player " << player_symbol << " enter move: "<<endl;
        random_player(x,y);
        displayBoard();
    }
    else{
        if (player == -1){
            switch_player();
        }
        cout << "Player " << player_symbol << " enter move: " <<endl;
        random_player(x,y);
        switch_player();
        cout << "Player " << player_symbol << " enter move: "<<endl;
        player_human();
        displayBoard();
    }
    noOfMoves += 2;
    done = gameStatus(noOfMoves);
}
void Board::choice_3(){
    int x, y;
    if (bot_eater_passer == 1){
        if (player == 1){
            switch_player();
        }
        cout << "Player " << player_symbol << " enter move: " <<endl;
        straigh_line_player(x,y);
        switch_player();
        cout << "Player " << player_symbol << " enter move: "<<endl;
        random_player(x,y);
        displayBoard();
    }
    else{
        if (player == -1){
            switch_player();
        }
        cout << "Player " << player_symbol << " enter move: " <<endl;
        random_player(x,y);
        switch_player();
        cout << "Player " << player_symbol << " enter move: "<<endl;
        straigh_line_player(x,y);
        displayBoard();
    }
    noOfMoves += 2;
    done = gameStatus(noOfMoves);
}
bool Board::check_adjacent(int r, int c){
    if (r >= 0 && r <= size){
        if (c >= 0 && c <= size){
            return true;
        }
    }
    return false;
}

bool Board::check_col(int x, int y){
    //check the column of each row
    for (int i = 0 ; i < size; i++){
        if (table[x][i] == 1){
            return true;
        }
    }
    return false;
}
bool Board::P_winning(){
    for (int i = 0; i < size; i ++){
        for (int j = 0; j  < size ; j++){
            if (table[i][j] == 1){
                if (check_adjacent(i+1,j-1)== true){
                    P_win_counter ++;
                }
                else if (check_adjacent(i+1,j)== true){
                    P_win_counter ++;
                }
                else if (check_adjacent(i+1,j+1)== true){
                    P_win_counter ++;
                }
            }
            else if (table[i][j] == -1){
                if (check_adjacent(i+1,j-1)== true){
                    P_win_counter --;
                }
                else if (check_adjacent(i+1,j)== true){
                    P_win_counter --;
                }
                else if (check_adjacent(i+1,j+1)== true){
                    P_win_counter --;
                }
            }
        }
    }
    cout << P_win_counter <<endl;
    if (P_win_counter == size){
        return true;
    }
    return false;
}
void Board::play(){
    for (int row = 0; row < size; row++){
        for (int col =0 ; col < size; col++){
            table[row][col]= 0;
        }
    }
    cout << "Please choose your game choice: "<< endl;
    cout <<  "1. vs Player 2" << endl;
    cout << " 2. vs Bot" << endl;
    cout << "3. Straighline vs Random player" << endl;
    cin >> choice;
    cout << endl;
    if (choice == 2){
        cout << "What player do you want to be? " << endl;
        cout << "1. Passer" << endl;
        cout << "2. Eater" << endl;
        cin >> player_eater_passer;
        cout << endl;
    }
    if (choice == 3){
        cout << "What bot do you want to be? " << endl;
        cout << "1. Passer" << endl;
        cout << "2. Eater" << endl;
        cin >> bot_eater_passer;
        cout << endl;
    }
    displayBoard();
    while (done == 0) {
		if (choice == 1 ){
            choice_1();
        }
        else if (choice == 2){
            choice_2();
        }
        else if (choice == 3){
            choice_3();
        }
		if (done == 1) {
			cout << "Player P wins!" << endl;
		} else if (done == -1) {
			cout << "Player E wins!" << endl;
		} else if (done == 2) {
			cout << "Draw game!" << endl;
		}
	}
}
#endif