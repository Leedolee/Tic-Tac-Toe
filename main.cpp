/* 
 * File:   main.cpp
 * Author: Lee
 *
 * Created on December 8, 2015, 9:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void board(char markLoc[]);
void playerOneMove(char markLoc[],char loc);
bool valid(char markLoc[],char loc);
bool checkWin(char markLoc[]);
void playerTwoMove(char markLoc[],char loc);
bool fullBoard(char markLoc[]);
void dumbAI(char markLoc);
bool ticTacToeTwoPlayer(char markLoc[]);
void clear();
bool ticTacToeDumbAI(char markLoc[]);
void smartAI(char markLoc[]);
bool ticTacToeSmartAI(char markLoc[]);
char smartAIChecks(char markLoc[]);
void stats(string name);
void ticTacToeGame(char markLoc[]);






int main(int argc, char** argv) {
    srand(time(0));
    char markLoc[10];
    markLoc[1] = '1';
    markLoc[2] = '2';
    markLoc[3] = '3';
    markLoc[4] = '4';
    markLoc[5] = '5';
    markLoc[6] = '6';
    markLoc[7] = '7';
    markLoc[8] = '8';
    markLoc[9] = '9';
    
    
    cout << "What game would you like to play?\n";
    cout << "1: Tic Tac Toe\n2: Escape\n";
    int game;
    cin >> game;
    while(cin.fail())
        {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Invalid input, try again";
        cin >> game;
        }
    switch(game)
    {
        case 1:
            ticTacToeGame(markLoc);
            break;
        case 2:
            escapeGame();
            break;
    }
    
    
    return 0;
}

/**
 * It shows the current board and the moves that have been made
 * @param a an array that keeps the location of each move made by the player
 * or computer AI
 */
void board(char a[])
{
    cout << " " << a[1] << " " << "|"<< " " << a[2] << " " << "|"<< " " << a[3];
    cout << " " << endl;
    cout << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-";
    cout << "-" << endl;
    cout << " " << a[4] << " " << "|"<< " " << a[5] << " " << "|"<< " " << a[6];
    cout << " " << endl;
    cout << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-";
    cout << "-" << endl;
    cout << " " << a[7] << " " << "|"<< " " << a[8] << " " << "|"<< " " << a[9];
    cout << " " << endl;
    cout << endl;
    
}
/**
 * This is a function that allows the player to place their mark
 * @param markLoc an array that holds the location of each mark
 * @param loc the location that the player chooses to make
 */
void playerOneMove(char markLoc[],char loc)
{
    if(loc == '1')
    {
        markLoc[1] = 'x';
    }
    else if(loc == '2')
    {
        markLoc[2] = 'x';
    }
    else if(loc == '3')
    {
        markLoc[3] = 'x';
    }
    else if(loc == '4')
    {
        markLoc[4] = 'x';
    }
    else if(loc == '5')
    {
        markLoc[5] = 'x';
    }
    else if(loc == '6')
    {
        markLoc[6] = 'x';
    }
    else if(loc == '7')
    {
        markLoc[7] = 'x';
    }
    else if(loc == '8')
    {
        markLoc[8] = 'x';
    }
    else if(loc == '9')
    {
        markLoc[9] = 'x';
    }
    else
    {
        cout << "invalid move\n";
    }
}
/**
 * This function checks to see if the move made by the player is valid
 * @param markLoc The array that holds the marks made as well as the locations
 * @param loc The location that the player chose
 * @return returns whether or not the location is valid
 */
bool valid(char markLoc[],char loc)
{
    if(markLoc[1] == '1' && loc == '1')
    {
         return true;
    }
    else if(markLoc[2] == '2' && loc == '2')
    {
        return true;
    }
    else if(markLoc[3] == '3' && loc == '3')
    {
        return true;
    }
    else if(markLoc[4] == '4' && loc == '4')
    {
        return true;
    }
    else if(markLoc[5] == '5' && loc == '5')
    {
       return true;
    }
    else if(markLoc[6] == '6' && loc == '6')
    {
        return true;
    }
    else if(markLoc[7] == '7' && loc == '7')
    {
        return true;
    }
    else if(markLoc[8] == '8' && loc == '8')
    {
        return true;
    }
    else if(markLoc[9] == '9' && loc == '9')
    {
        return true;
    }
    else
    {
        cout << "invalid move\n"; 
        return false;
    }
}
/**
 * Function checks to see if the winning condition is met
 * @param markLoc The array that holds the marks as well as locations
 * @return Returns true if the winning condition is met
 */
bool checkWin(char markLoc[])
{
    if(markLoc[1] == markLoc[2] && markLoc[2] == markLoc[3])
    {
        return true;
    }
    else if(markLoc[1] == markLoc[5] && markLoc[5] == markLoc[9])
    {
        return true;
    }
    else if(markLoc[1] == markLoc[4] && markLoc[4] == markLoc[7])
    {
        return true;
    }
    else if(markLoc[2] == markLoc[5] && markLoc[5] == markLoc[8])
    {
        return true;
    }
    else if(markLoc[3] == markLoc[6] && markLoc[6] == markLoc[9])
    {
        return true;
    }
    else if(markLoc[3] == markLoc[5] && markLoc[5] == markLoc[7])
    {
        return true;
    }
    else if(markLoc[4] == markLoc[5] && markLoc[5] == markLoc[6])
    {
        return true;
    }
    else if(markLoc[7] == markLoc[8] && markLoc[8] == markLoc[9])
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * Function that checks to see if the board is full or not.
 * @param markLoc The array that holds the data about the board
 * @return returns true if board is full, false if still space available
 */
bool fullBoard(char markLoc[])
{
    if(markLoc[1] == '1')
    {
         return false;
    }
    else if(markLoc[2] == '2')
    {
        return false;
    }
    else if(markLoc[3] == '3')
    {
        return false;
    }
    else if(markLoc[4] == '4')
    {
        return false;
    }
    else if(markLoc[5] == '5')
    {
       return false;
    }
    else if(markLoc[6] == '6')
    {
        return false;
    }
    else if(markLoc[7] == '7')
    {
        return false;
    }
    else if(markLoc[8] == '8')
    {
        return false;
    }
    else if(markLoc[9] == '9')
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
 * Function that allows the second player to make the move
 * @param markLoc The array that holds the board's data
 * @param loc the location that the player wants to move
 */
void playerTwoMove(char markLoc[],char loc)
{
    if(loc == '1')
    {
        markLoc[1] = 'o';
    }
    else if(loc == '2')
    {
        markLoc[2] = 'o';
    }
    else if(loc == '3')
    {
        markLoc[3] = 'o';
    }
    else if(loc == '4')
    {
        markLoc[4] = 'o';
    }
    else if(loc == '5')
    {
        markLoc[5] = 'o';
    }
    else if(loc == '6')
    {
        markLoc[6] = 'o';
    }
    else if(loc == '7')
    {
        markLoc[7] = 'o';
    }
    else if(loc == '8')
    {
        markLoc[8] = 'o';
    }
    else if(loc == '9')
    {
        markLoc[9] = 'o';
    }
    else
    {
        cout << "invalid move\n";
    }
}

/**
 * Function that runs the dumb AI whose move is RNG based
 * @param markLoc Array that holds the board's data
 */
void dumbAI(char markLoc[])
{
    srand(time(0));
    int loc;
    char loc2;
    do
    {
        loc = rand()%9+1;
        cout << loc;
        loc2 = loc + '0'; 
    }while(!valid(markLoc,loc2));
     if(loc == 1)
        {
            markLoc[1] = 'o';
        }
        else if(loc == 2)
        {
            markLoc[2] = 'o';
        }
        else if(loc == 3)
        {
            markLoc[3] = 'o';
        }
        else if(loc == 4)
        {
            markLoc[4] = 'o';
        }
        else if(loc == 5)
        {
            markLoc[5] = 'o';
        }
        else if(loc == 6)
        {
            markLoc[6] = 'o';
        }
        else if(loc == 7)
        {
            markLoc[7] = 'o';
        }
        else if(loc == 8)
        {
            markLoc[8] = 'o';
        }
        else if(loc == 9)
        {
            markLoc[9] = 'o';
        }
}

/**
 * Function that mimics a clear console;
 */
void clear()
{
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

/**
 * Function that clears the data to mimic a new game
 * @param markLoc array that holds the board data
 */
void newGame(char markLoc[])
{
    markLoc[1] = '1';
    markLoc[2] = '2';
    markLoc[3] = '3';
    markLoc[4] = '4';
    markLoc[5] = '5';
    markLoc[6] = '6';
    markLoc[7] = '7';
    markLoc[8] = '8';
    markLoc[9] = '9';
}

/**
 * 
 * Function that checks if there is a move that can win the game and check if
 * there is a move it can block.
 * @param markLoc Array that holds the board's data
 * @return 
 */
char smartAIChecks(char markLoc[])
{
    char move;
    char temp[10];
    
    for (int i = 1; i < 10; i++)
    {
        for( int j = 1; j < 10; j++)
        {
            temp[j] = markLoc[j];
        }
        if(valid(temp,i + '0'))
        {
            temp[i] = 'o';
            if(checkWin(temp))
            {
                return i + '0';
            }
        }
    }

    
    for (int i = 1; i < 10; i++)
    {
        for( int j = 1; j < 10; j++)
        {
            temp[j] = markLoc[j];
        }
        if(valid(temp,i + '0'))
        {
            temp[i] = 'x';
            if(checkWin(temp))
            {
                return i+'0';
            }
        }

    }
}

// Smart AI that can never lose, only win or tie
void smartAI(char markLoc[])
{
    // Checks to see if the AI can win or the player can win and blocks it
    char move = smartAIChecks(markLoc);
    
    if(valid(markLoc,move))
    {
    playerTwoMove(markLoc, move);
    return;
    }
    
    // Plays the center if the player plays a corner square
    if(markLoc[1] == 'x' && markLoc[5] == '5')
    {
        playerTwoMove(markLoc,'5');
        return;
    }
    else if((markLoc[3] == 'x' && markLoc[5] == '5'))
    {
        playerTwoMove(markLoc,'5');
        return;
    }
    else if((markLoc[7] == 'x' && markLoc[5] == '5'))
    {
        playerTwoMove(markLoc,'5');
        return;
    }
    else if((markLoc[9] == 'x' && markLoc[5] == '5'))
    {
        playerTwoMove(markLoc,'5');
        return;
    }
    
    //Checks to see if it can block a fork from the player
    if(markLoc[1] == 'x' && markLoc[9] == 'x')
    {
        if(valid(markLoc,'2'))
        {
            playerTwoMove(markLoc,'2');
            return;
        }
        else if(valid(markLoc,'4'))
        {
            playerTwoMove(markLoc,'4');
            return;
        }
        else if(valid(markLoc,'6'))
        {
            playerTwoMove(markLoc,'6');
            return;
        }
        else if(valid(markLoc,'8'))
        {
            playerTwoMove(markLoc,'8');
            return;
        }    
    }
    else if(markLoc[3] == 'x' && markLoc[7] == 'x')
    {
        if(valid(markLoc,'2'))
        {
            playerTwoMove(markLoc,'2');
            return;
        }
        else if(valid(markLoc,'4'))
        {
            playerTwoMove(markLoc,'4');
            return;
        }
        else if(valid(markLoc,'6'))
        {
            playerTwoMove(markLoc,'6');
            return;
        }
        else if(valid(markLoc,'8'))
        {
            playerTwoMove(markLoc,'8');
            return;
        }    
    }
    
    //Plays the only space available if the previous conditions hold false
    if(valid(markLoc,'1'))
    {
        playerTwoMove(markLoc,'1');
    }
    else if(valid(markLoc,'3'))
    {
        playerTwoMove(markLoc,'3');
    }
    else if(valid(markLoc,'7'))
    {
        playerTwoMove(markLoc,'7');
    }
    else if(valid(markLoc,'9'))
    {
        playerTwoMove(markLoc,'9');
    }
    else if(valid(markLoc, '5'))
    {
        playerTwoMove(markLoc,'5');
    }
    else if(valid(markLoc,'2'))
    {
        playerTwoMove(markLoc,'2');
    }
    else if(valid(markLoc,'4'))
    {
        playerTwoMove(markLoc,'4');
    }
    else if(valid(markLoc,'6'))
    {
        playerTwoMove(markLoc,'6');
    }
    else if(valid(markLoc,'8'))
    {
        playerTwoMove(markLoc,'8');
    }    
}
/**
 * Function that runs the game for 2 players
 * @param markLoc Holds the data of the board
 */
bool ticTacToeTwoPlayer(char markLoc[])
{
    int player = 1;
    char move;
    do
    {
        clear();
        board(markLoc);
        do
        {
        cout << "player " << player << " Enter location: ";
        cin >> move;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Invalid input, try again";
            cin >> move;
        }
        }while(!valid(markLoc,move));

        playerOneMove(markLoc,move);
        
        
        clear();

        board(markLoc);
        

        if(checkWin(markLoc))
        {
            cout << "Player " << player << "Wins\n";
            newGame(markLoc);
            return true;
        }
        else if(!fullBoard(markLoc))
            {
            player++;

            do
            {
            cout << "Player " << player << " Enter location: ";
            cin >> move;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(256,'\n');
                cout << "Invalid input, try again";
                cin >> move;
            }
            }while(!valid(markLoc,move));

            playerTwoMove(markLoc,move);

            clear();

            board(markLoc);

            if(checkWin(markLoc))
            {
                cout << "Player " << player << "Wins\n";
                newGame(markLoc);
                return false;
            } 
            player--;
            }
    }while(!checkWin(markLoc) && !fullBoard(markLoc));
    
    if(fullBoard(markLoc))
    {
        cout << "It is a tie!" << endl;
        newGame(markLoc);
        return false;
    }
       
}

/**
 * Function that runs the Dumb AI
 * @param markLoc Array that holds the board's data
 * @return returns if it is a win or not
 */
bool ticTacToeDumbAI(char markLoc[])
{   
    int player = 1;
    char move;
    do
    {
        clear();
        board(markLoc);
        do
        {
        cout << "player " << player << " Enter location: ";
        cin >> move;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Invalid input, try again";
            cin >> move;
        }
        }while(!valid(markLoc,move));

        playerOneMove(markLoc,move);
        
        clear();

        board(markLoc);
        
        if(checkWin(markLoc))
        {
            cout << "Player " << player << "Wins\n";
            newGame(markLoc);
            return true;
        }
        else if(!fullBoard(markLoc))
        {
            dumbAI(markLoc);

            clear();

            board(markLoc);

            if(checkWin(markLoc))
            {
                cout << " AI Wins\n";
                newGame(markLoc);
                return false;
            } 
        }
    }while(!checkWin(markLoc) && !fullBoard(markLoc));
    
    if(fullBoard(markLoc))
    {
    cout << "It is a tie!" << endl;
    }
    newGame(markLoc);
    return false;
}

/**
 * Function that runs the smart AI
 * @param markLoc Array that holds the board's data
 * @return returns if it is a win or not
 */
bool ticTacToeSmartAI(char markLoc[])
{
    int player = 1;
    char move;
    do
    {
        clear();
        board(markLoc);
        do
        {
        cout << "player " << player << " Enter location: ";
        cin >> move;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Invalid input, try again";
            cin >> move;
        }
        }while(!valid(markLoc,move));

        playerOneMove(markLoc,move);
        
        clear();

        board(markLoc);
        
        if(checkWin(markLoc))
        {
            cout << "Player " << player << "Wins\n";
            newGame(markLoc);
            return true;
        }
        else if(!fullBoard(markLoc))
        {
            smartAI(markLoc);

            clear();

            board(markLoc);

            if(checkWin(markLoc))
            {
                cout << " AI Wins\n";
                newGame(markLoc);
                return false;
            } 
        }
    }while(!checkWin(markLoc) && !fullBoard(markLoc));
    
    if(fullBoard(markLoc))
    {
    cout << "It is a tie!" << endl;
    }
    newGame(markLoc);
    return false;
}

/**
 * Function that displays the stats of the user
 * @param name The Username
 */
void stats(string name)
{
    int totGame;
    int totGameWin;
    double totWinRate;
    int totGameVSDumbAI;
    int totGameVSDumbAIWin;
    double totWinRate2;
    int totGameVSSmartAI;
    int totGameVSSmartAIWin;
    double totWinRate3;
    ifstream infile;
    string stats;
    infile.open(name.c_str());
    if(infile.is_open())
    {
        infile >> totGame >> totGameWin >> totWinRate >> totGameVSDumbAI;
        infile >> totGameVSDumbAIWin >> totWinRate2 >> totGameVSSmartAI;
        infile >> totGameVSSmartAIWin >> totWinRate3;
        infile.close();
    }
    else
    {
        cout << "file can't be open";
    }
    cout << "Total Games is: " << totGame << endl; 
    cout << "Total wins is: " << totGameWin << endl; 
    cout << "Total win rate is: " << totWinRate << endl; 
    cout << "Total Games VS Dumb AI is: " << totGameVSDumbAI << endl;
    cout << "Total Wins VS Dumb AI is: " << totGameVSDumbAIWin << endl;
    cout << "Win rate VS Dumb AI is: " <<  totWinRate2 << endl; 
    cout << "Total Games VS Smart AI is: " << totGameVSSmartAI << endl;
    cout << "Total Wins VS Smart AI is: " << totGameVSSmartAIWin << endl; 
    cout << "Win rate VS Smart AI is: " << totWinRate3 << endl;
    infile.close();
}

/**
 * Function that runs the Tic Tac Toe Game
 * @param markLoc Array that holds the board's data
 */
void ticTacToeGame(char markLoc[])
{
    clear();
    int totGame = 0;
    int totGameWin = 0;
    double totWinRate = 0;
    int totGameVSDumbAI = 0;
    int totGameVSDumbAIWin = 0;
    double totWinRate2 = 0;
    int totGameVSSmartAI = 0;
    int totGameVSSmartAIWin = 0;
    double totWinRate3= 0;
    
    int fileCheck = 0;
    ifstream infile;
    ofstream outfile;
    string name;
    cout << "Welcome to TicTacToe!\n";
    bool valid;
    int response;
    do
    {
    cout << "1: New Player\n2: Existing player\n";
    cin >> response;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Invalid input, try again";
        cin >> response;
    }
    switch(response)
    {
        case 1: 
            cout << "Please enter your Profile name: \n";
            cin >> name;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(256,'\n');
                cout << "Invalid input, try again";
                cin >> name;
            }
            valid = true;
            break;
        case 2: 
            cout << "Please enter your previous name: \n";
            cin >> name;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(256,'\n');
                cout << "Invalid input, try again";
                cin >> name;
            }
            fileCheck++;
            valid = true;
            break;
        default : 
            cout << "Invalid choice!\n";
            valid = false;
    }
    }while(!valid);

    // Loads the User profile data
    if(fileCheck == 1)
    {
    infile.open(name.c_str());
    infile >> totGame >> totGameWin >> totWinRate >> totGameVSDumbAI;
    infile >> totGameVSDumbAIWin >> totWinRate2 >> totGameVSSmartAI;
    infile >> totGameVSSmartAIWin >> totWinRate3;
    infile.close();
    }
    
    
    cout << "Please choose an Option:\n";
    cout << "1:Player vs Player\n2:Player vs Easy AI\n";
    cout << "3:Player vs Hard AI\n4:Stats\n";
    cout << "5:To end the game\n";
    int choice;
    cin >> choice;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Invalid input, try again";
        cin >> choice;
    }
    do
    {
    switch(choice)
    {
        case 1:
            if(ticTacToeTwoPlayer(markLoc))
            {
                totGameWin++;
            }
            totGame++;
            break;
        case 2:
            if(ticTacToeDumbAI(markLoc))
            {
                totGameWin++;
                totGameVSDumbAIWin++;
            }
            totGameVSDumbAI++;
            totGame++;
            break;
        case 3:
            if(ticTacToeSmartAI(markLoc))
            {
                totGameWin++;
                totGameVSSmartAIWin++;
            }
            totGameVSSmartAI++;
            totGame++;
            break;
        case 4:
            stats(name);
            break;
    }
    outfile.open(name.c_str());
    outfile << totGame << " " << totGameWin << " "; 
    outfile << totGameWin/static_cast<double>(totGame) << " ";
    outfile << totGameVSDumbAI << " " << totGameVSDumbAIWin << " ";
    outfile << totGameVSDumbAIWin/static_cast<double>(totGameVSDumbAI) << " "; 
    outfile << totGameVSSmartAI << " " << totGameVSSmartAIWin << " "; 
    outfile << totGameVSSmartAIWin/static_cast<double>(totGameVSSmartAI);
    outfile.close();
    
    cout << "Please choose an Option:\n";
    cout << "1:Player vs Player\n2:Player vs Easy AI\n";
    cout << "3:Player vs Hard AI\n4:Stats\n";
    cout << "5:To end the game\n";
    cin >> choice;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Invalid input, try again";
        cin >> choice;
    }
    }while(choice != 5);
}

