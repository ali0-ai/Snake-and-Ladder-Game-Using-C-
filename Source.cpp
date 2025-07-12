//Author : SHAHZAIB ALI
//DEPARTMENT OF MECHATRONICS ENGINEERING,CEME,NUST.
//DEGREE : 41
//SYNDICATE : B
//FUNDAMENTALS OF PROGRAMMING
//SEMESTER PROJECT : SNAKE AND LADER GAME

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;
void menu();
void menu1();
int draw_line(int n, char ch);
void board();
int gamescore(char name1[], char name2[], int p1, int p2);
int play_dice(int& score);
int computer_dice(int& computer_score);
void savegame();
void instructions();
void credits();
void quit();
void MENU();
int squares[200];
void positions();
void multiplayer();
void singleplayer();
int role_P1;
int score;
int role_P2;
int player1 = 0, player2 = 0, lastposition1,lastposition2;
char player1name[80], player2name[80];
int main()
{

    cout << endl;
    MENU();
    menu1();
    cout << endl;
    draw_line(168, '=');
}
void multiplayer()
{
    cout << "Welcome To Snakes and Laders Game \n HUMAN vs HUMAN";
    cout << "\n\n\nEnter Name of player 1 :";
    cin >> player1name;
    cout << "enter Name of player 2 :";
    cin >> player2name;
    for (int i = 1; i <= 100; i++) // this loop just makes it possible for us to give our squares values
    {
        squares[i] = i;
    }
    do
    {

        board();
        gamescore(player1name, player2name, player1, player2);
        cout << "\n\n--->" << player1name << " Now your Turn >> Press any key to play ";
        _getch();
        lastposition1 = player1;
        role_P1 = play_dice(player1);
        if (player1 < lastposition1)
        {
            cout << "\n\aOops!! Snake found !! You are at postion " << player1 << "\n";
        }
        else if (player1 > lastposition1 + 6)
        {
            cout << "\nGreat!! you got a ladder !! You are at position " << player1;
        }
   

        cout << "\n\n--->" << player2name << " Now your Turn >> Press any key to play ";
        _getch();

        lastposition2 = player2;
        role_P2 = play_dice(player2);
        if (player2 < lastposition2)
        {
            cout << "\n\n\aOops!! Snake found !! You are at position " << player2 << "\n";
        }
        else if (player2 > lastposition2 + 6)
        {
            cout << "\n\nGreat!! you got a ladder !! You are at position " << player2 << "\n";
        }
        _getch();
        
        board();
    } while (player1 <= 100 && player2 <= 100);
    cout << "\n\n\n";
    draw_line(50, '+');
    cout << "\n\n\t\tRESULT\n\n";
    draw_line(50, '+');
    cout << endl;
    gamescore(player1name, player2name, player1, player2);
    cout << "\n\n\n";
    if (player1 >= player2)
        cout << player1name << " !! You are the winner of the game\n\n";
    else
        cout << player2name << " !! You are the winner of the game\n\n";
    draw_line(50, '+');
    _getch();
}
void singleplayer()
{
    ofstream save("saveGame.txt");
    int roll; //holds the rolled value for the player
    int computer_roll; //holds the rolled value for computer
    int input=1; //variable to hold the users input, any number to roll dice and 0 to quit game, although entering a not a number value ends  the game as well...
    int player = 0;
    int computer = 0;

    srand(time(NULL)); //we need random numbers
    cout << "Welcome to snakes and ladders \n COMPUTER vs HUMAN";
   int lastposition;
    char player1[80], computer1[80];
    cout << "\n\n\nEnter Name of player:";
    cin >> player1;
    cout << "enter Name of computer :";
    cin >> computer1;
    for (int i = 1; i <= 100; i++) // this loop just makes it possible for us to give our squares values
    {
        squares[i] = i;
    }

    do // every game is in some sort of loop
    {
        board();
        gamescore(player1, computer1, player, computer);
        cout << "\n\n--->" << player1 << " Now your Turn >> Press any key to play ";
        _getch();
        lastposition = player;
        role_P1 = play_dice(player);
        if (player < lastposition)
        {
            cout << "\n\aOops!! Snake found !! You are at postion " << player1 << "\n";
        }
        else if (player > lastposition + 6)
        {
            cout << "\nGreat!! you got a ladder !! You are at position " << player1;
        }

        computer_roll = computer_dice(computer);//computer rolls dice

        if (input != 0)
        {
            board();
        }
    } while (player <= 100 && computer <= 100);
    
    if (player >= 100)
    {
        cout << "\n ||You Win!||" << endl;
    }
    else if (computer >= 100)
    {
        cout << "\n ||Game Over Computer Wins!" << endl;
    }
    else
    {
        cout << "\n You Quit!";
    }
    _getch();
}
void menu()
{
    system("color 6B");
    cout << endl << endl;
    draw_line(168, '=');
    cout << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t...S"; Sleep(100); cout << "N"; Sleep(100); cout << "A"; Sleep(100); cout << "K"; Sleep(100); cout << "E"; Sleep(100); cout << " &"; Sleep(100); cout << " L"; Sleep(100); cout << "A"; Sleep(100); cout << "D"; Sleep(100); cout << "E"; Sleep(100); cout << "R"; Sleep(100); cout << "..." << endl;
    cout << endl << endl;
    draw_line(168, '=');
    cout << "\n\n\t\t\t\t\t\t\t\t\tCredit: S"; Sleep(200); cout << "H"; Sleep(200); cout << "A"; Sleep(200); cout << "H"; Sleep(200); cout << "Z"; Sleep(200); cout << "A"; Sleep(200); cout << "I"; Sleep(200); cout << "B "; Sleep(200); cout << "A"; Sleep(200); cout << "L";Sleep(200); cout << "I";
    cout << "\n\n\n\t\t\t\t\t\t\t\tLoading";
    for (int i = 0; i < 8; i++)
    {
        Sleep(500);
        cout << ".";
    }
   
}
void menu1()
{
    
    system("color 7C");
    ifstream in;
    int gamemode;
    cin >> gamemode;
 
    in.open("saveGame.txt");
    while (gamemode != 6)
    {
        switch (gamemode)
        {
        case 1:

            system("color 8E");
            singleplayer();
            break;
        case 2:

            system("color 8E");
            multiplayer();
            break;
        case 3:
            system("color F5");
            savegame();
            break;
        case 4:
            credits();
            break;
        case 5:
            instructions();
            break;
        default:
            cout << "\nInvalid\n";
        }
        
        MENU();
        cin >> gamemode;
        system("CLS");
    }
    switch (gamemode)
    {
    case 6:
        quit();
        break;
    }
}
int draw_line(int n, char ch)
{
    for (int i = 0; i < n; i++)
        cout << ch;
    return ch;
}
void positions() //defines the positions of snakes and laders on the Board
{
    cout << "\n\n";
    draw_line(50, '-');
    cout << "\n\t\tSNAKE AT POSITION\n”";
    draw_line(50, '-');
    cout << "\n\tFrom 98 to 28 \n\tFrom 95 to 24\n\tFrom 92 to 51\n\tFrom 83 to 19\n\tFrom 73 to 1\n\tFrom 69 to 33\n\tFrom 64 to 36\n\tFrom 59 to 17\n\tFrom 55 to 7\n\tFrom 52 to 11\n\tFrom 48 to 9\n\tFrom 46 to 5\n\tFrom 44 to 22\n\n";
    draw_line(50, '-');
    cout << "\n\t\t LADDER AT POSITION\n";
    draw_line(50, ' - ');
    cout << "\n\tFrom 8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
    draw_line(50, ' - ');
    cout << endl;
}
void board()//define the board drawing mechanism!
{
    system("CLS");
    positions();
    cout << "----------------------------------------------------------------------------" << endl << endl;
    cout << squares[100] << "\t" << squares[99] << "\t" << squares[98] << "\t" << squares[97] << "\t" << squares[96] << "\t"
        << squares[95] << "\t" << squares[94] << "\t" << squares[93] << "\t" << squares[92] << "\t" << squares[91] << endl << endl;

    cout << squares[81] << "\t" << squares[82] << "\t" << squares[83] << "\t" << squares[84] << "\t" << squares[85] << "\t"
        << squares[86] << "\t" << squares[87] << "\t" << squares[88] << "\t" << squares[89] << "\t" << squares[90] << endl << endl;

    cout << squares[80] << "\t" << squares[79] << "\t" << squares[78] << "\t" << squares[77] << "\t" << squares[76] << "\t"
        << squares[75] << "\t" << squares[74] << "\t" << squares[73] << "\t" << squares[72] << "\t" << squares[71] << endl << endl;

    cout << squares[61] << "\t" << squares[62] << "\t" << squares[63] << "\t" << squares[64] << "\t" << squares[65] << "\t"
        << squares[66] << "\t" << squares[67] << "\t" << squares[68] << "\t" << squares[69] << "\t" << squares[70] << endl << endl;

    cout << squares[60] << "\t" << squares[59] << "\t" << squares[58] << "\t" << squares[57] << "\t" << squares[56] << "\t"
        << squares[55] << "\t" << squares[54] << "\t" << squares[53] << "\t" << squares[52] << "\t" << squares[51] << endl << endl;

    cout << squares[41] << "\t" << squares[42] << "\t" << squares[43] << "\t" << squares[44] << "\t" << squares[45] << "\t"
        << squares[46] << "\t" << squares[47] << "\t" << squares[48] << "\t" << squares[49] << "\t" << squares[50] << endl << endl;

    cout << squares[40] << "\t" << squares[39] << "\t" << squares[38] << "\t" << squares[37] << "\t" << squares[36] << "\t"
        << squares[35] << "\t" << squares[34] << "\t" << squares[33] << "\t" << squares[32] << "\t" << squares[31] << endl << endl;

    cout << squares[21] << "\t" << squares[22] << "\t" << squares[23] << "\t" << squares[24] << "\t" << squares[25] << "\t"
        << squares[26] << "\t" << squares[27] << "\t" << squares[28] << "\t" << squares[29] << "\t" << squares[30] << endl << endl;

    cout << squares[20] << "\t" << squares[19] << "\t" << squares[18] << "\t" << squares[17] << "\t" << squares[16] << "\t"
        << squares[15] << "\t" << squares[14] << "\t" << squares[13] << "\t" << squares[12] << "\t" << squares[11] << endl << endl;

    cout << squares[1] << "\t" << squares[2] << "\t" << squares[3] << "\t" << squares[4] << "\t" << squares[5] << "\t"
        << squares[6] << "\t" << squares[7] << "\t" << squares[8] << "\t" << squares[9] << "\t" << squares[10] << endl << endl;
    cout << "----------------------------------------------------------------------------" << endl;
}
int gamescore(char name1[], char name2[], int p1, int p2)
{
    cout << "\n";
    draw_line(50, '~');
    cout << "\n\t\tGAME STATUS\n";
    draw_line(50, '~');
    cout << "\n\t--->" << name1 << " is at position " << p1 << endl;
    cout << "\t--->" << name2 << " is at position " << p2 << endl;
    draw_line(50, '_');
    cout << endl;
    return 1;
}
int play_dice(int& score)
{
    int dice;
    srand(time(0));
    dice = rand() % 6 + 1;

    cout << "\nYou got " << dice << " Point !! ";
    score = score + dice;
    cout << "Now you are at position " << score;
    switch (score)
    {
    case 98:
        score = 28;
        break;
    case 95:
        score = 24;
        break;
    case 92:
        score = 51;
        break;
    case 83:
        score = 19;
        break;
    case 73:
        score = 1;
        break;
    case 69:
        score = 33;
        break;
    case 64:
        score = 36;
        break;
    case 59:
        score = 17;
        break;
    case 55:
        score = 7;
        break;
    case 52:
        score = 11;
        break;
    case 48:
        score = 9;
        break;
    case 46:
        score = 5;
        break;
    case 44:
        score = 22;
        break;
    case 8:
        score = 26;
        break;
    case 21:
        score = 82;
        break;
    case 43:
        score = 77;
        break;
    case 50:
        score = 91;
        break;
    case 54:
        score = 93;
        break;
    case 62:
        score = 96;
        break;
    case 66:
        score = 87;
        break;
    case 80:
        score = 100;
    }
    return 0;
}
int computer_dice(int& computer_score)
{
    int computer_dice;
    srand(time(0));
    computer_dice = rand() % (6 - 1) + 1;
    
    cout << "\nYou got " << computer_dice << " Point !! ";
    computer_score = computer_score + computer_dice;
    cout << "Now you are at position " << computer_score;
    switch (computer_score)
    {
    case 98:
        computer_score = 28;
        break;
    case 95:
        computer_score = 24;
        break;
    case 92:
        computer_score = 51;
        break;
    case 83:
        computer_score = 19;
        break;
    case 73:
        computer_score = 1;
        break;
    case 69:
        computer_score = 33;
        break;
    case 64:
        computer_score = 36;
        break;
    case 59:
        computer_score = 17;
        break;
    case 55:
        computer_score = 7;
        break;
    case 52:
        computer_score = 11;
        break;
    case 48:
        computer_score = 9;
        break;
    case 46:
        computer_score = 5;
        break;
    case 44:
        computer_score = 22;
        break;
    case 8:
        computer_score = 26;
        break;
    case 21:
        computer_score = 82;
        break;
    case 43:
        computer_score = 77;
        break;
    case 50:
        computer_score = 91;
        break;
    case 54:
        computer_score = 93;
        break;
    case 62:
        computer_score = 96;
        break;
    case 66:
        computer_score = 87;
        break;
    case 80:
        computer_score = 100;
    }
    return 0;
}
void savegame()
{

    for (int i = 1; i <= 100; i++) // this loop just makes it possible for us to give our squares values
    {
        squares[i] = i;
    }
    ofstream save("saveGame.txt");
    cout << "----------------------------------------------------------------------------" << endl << endl;
    save<< "----------------------------------------------------------------------------" << endl << endl;
    cout << squares[100] << "\t" << squares[99] << "\t" << squares[98] << "\t" << squares[97] << "\t" << squares[96] << "\t"
        << squares[95] << "\t" << squares[94] << "\t" << squares[93] << "\t" << squares[92] << "\t" << squares[91] << endl << endl;
    save<< squares[100] << "\t" << squares[99] << "\t" << squares[98] << "\t" << squares[97] << "\t" << squares[96] << "\t"
        << squares[95] << "\t" << squares[94] << "\t" << squares[93] << "\t" << squares[92] << "\t" << squares[91] << endl << endl;
    cout << squares[81] << "\t" << squares[82] << "\t" << squares[83] << "\t" << squares[84] << "\t" << squares[85] << "\t"
        << squares[86] << "\t" << squares[87] << "\t" << squares[88] << "\t" << squares[89] << "\t" << squares[90] << endl << endl;
    save << squares[81] << "\t" << squares[82] << "\t" << squares[83] << "\t" << squares[84] << "\t" << squares[85] << "\t"
        << squares[86] << "\t" << squares[87] << "\t" << squares[88] << "\t" << squares[89] << "\t" << squares[90] << endl << endl;
    cout << squares[80] << "\t" << squares[79] << "\t" << squares[78] << "\t" << squares[77] << "\t" << squares[76] << "\t"
        << squares[75] << "\t" << squares[74] << "\t" << squares[73] << "\t" << squares[72] << "\t" << squares[71] << endl << endl;
    save << squares[80] << "\t" << squares[79] << "\t" << squares[78] << "\t" << squares[77] << "\t" << squares[76] << "\t"
        << squares[75] << "\t" << squares[74] << "\t" << squares[73] << "\t" << squares[72] << "\t" << squares[71] << endl << endl;
    cout << squares[61] << "\t" << squares[62] << "\t" << squares[63] << "\t" << squares[64] << "\t" << squares[65] << "\t"
        << squares[66] << "\t" << squares[67] << "\t" << squares[68] << "\t" << squares[69] << "\t" << squares[70] << endl << endl;
    save << squares[61] << "\t" << squares[62] << "\t" << squares[63] << "\t" << squares[64] << "\t" << squares[65] << "\t"
        << squares[66] << "\t" << squares[67] << "\t" << squares[68] << "\t" << squares[69] << "\t" << squares[70] << endl << endl;
    cout << squares[60] << "\t" << squares[59] << "\t" << squares[58] << "\t" << squares[57] << "\t" << squares[56] << "\t"
        << squares[55] << "\t" << squares[54] << "\t" << squares[53] << "\t" << squares[52] << "\t" << squares[51] << endl << endl;
    save << squares[60] << "\t" << squares[59] << "\t" << squares[58] << "\t" << squares[57] << "\t" << squares[56] << "\t"
        << squares[55] << "\t" << squares[54] << "\t" << squares[53] << "\t" << squares[52] << "\t" << squares[51] << endl << endl;
    cout << squares[41] << "\t" << squares[42] << "\t" << squares[43] << "\t" << squares[44] << "\t" << squares[45] << "\t"
        << squares[46] << "\t" << squares[47] << "\t" << squares[48] << "\t" << squares[49] << "\t" << squares[50] << endl << endl;
    save << squares[41] << "\t" << squares[42] << "\t" << squares[43] << "\t" << squares[44] << "\t" << squares[45] << "\t"
        << squares[46] << "\t" << squares[47] << "\t" << squares[48] << "\t" << squares[49] << "\t" << squares[50] << endl << endl;
    cout << squares[40] << "\t" << squares[39] << "\t" << squares[38] << "\t" << squares[37] << "\t" << squares[36] << "\t"
        << squares[35] << "\t" << squares[34] << "\t" << squares[33] << "\t" << squares[32] << "\t" << squares[31] << endl << endl;
    save << squares[40] << "\t" << squares[39] << "\t" << squares[38] << "\t" << squares[37] << "\t" << squares[36] << "\t"
        << squares[35] << "\t" << squares[34] << "\t" << squares[33] << "\t" << squares[32] << "\t" << squares[31] << endl << endl;
    cout << squares[21] << "\t" << squares[22] << "\t" << squares[23] << "\t" << squares[24] << "\t" << squares[25] << "\t"
        << squares[26] << "\t" << squares[27] << "\t" << squares[28] << "\t" << squares[29] << "\t" << squares[30] << endl << endl;
    save << squares[21] << "\t" << squares[22] << "\t" << squares[23] << "\t" << squares[24] << "\t" << squares[25] << "\t"
        << squares[26] << "\t" << squares[27] << "\t" << squares[28] << "\t" << squares[29] << "\t" << squares[30] << endl << endl;
    cout << squares[20] << "\t" << squares[19] << "\t" << squares[18] << "\t" << squares[17] << "\t" << squares[16] << "\t"
        << squares[15] << "\t" << squares[14] << "\t" << squares[13] << "\t" << squares[12] << "\t" << squares[11] << endl << endl;
    save << squares[20] << "\t" << squares[19] << "\t" << squares[18] << "\t" << squares[17] << "\t" << squares[16] << "\t"
        << squares[15] << "\t" << squares[14] << "\t" << squares[13] << "\t" << squares[12] << "\t" << squares[11] << endl << endl;
    cout << squares[1] << "\t" << squares[2] << "\t" << squares[3] << "\t" << squares[4] << "\t" << squares[5] << "\t"
        << squares[6] << "\t" << squares[7] << "\t" << squares[8] << "\t" << squares[9] << "\t" << squares[10] << endl << endl;
    save << squares[1] << "\t" << squares[2] << "\t" << squares[3] << "\t" << squares[4] << "\t" << squares[5] << "\t"
        << squares[6] << "\t" << squares[7] << "\t" << squares[8] << "\t" << squares[9] << "\t" << squares[10] << endl << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    save << "----------------------------------------------------------------------------" << endl;
    _getch();

    cout<< gamescore(player1name, player2name, player1, player2) << endl;
    save<< gamescore(player1name, player2name, player1, player2)<<endl;
    while (player1 == 100 || player2==100)
    {
        player1 = 20;
        player2 = 35;
        play_dice(score);
        multiplayer();
    }
    save << play_dice(score)<<endl;
}
void instructions()
{
    cout << "In Human vs Human two players can play.\n";
    cout << "Each player gets its turn and roll the dice after intervals.\n";
    cout << "The player who reaches 100 firt wins the game.\n";
    cout << "In computer vs human 1 human player and 1 computer player plays\n";
            cout << "Each player gets its turn and roll the dice after intervals.\n";
        cout << "The player who reaches 100 firt wins the game.\n";
}
void credits()
{
    system("cls");
    cout << "\n\n\tSnake and Ladder";
    cout << "\n\tThis Game is made by Shahzaib Ali\n";
    cout << "\n I also ackknowledge the work of Amna Mujahid one of my friend";
   cout << "\n\nPress any Key to go back";
    _getch();
    system("CLS");
}
void quit()
{
}
void MENU()
{
    system("color 7C");
    menu();
    cout << "\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO SNAKE LADDER GAME\n\n\n\n";
    draw_line(168, '=');
    cout << "\n\t\t\t\t\t\tPress 1 : For Player vs Computer \n"
        << "\t\t\t\t\t\tPress 2 : For Two Players \n"
        << "\t\t\t\t\t\tPress 3 : For Saved Game\n"
        << "\t\t\t\t\t\tPress 4 : For credits\n"
        <<"\t\t\t\t\t\tPress 5: Instructions\n"
        <<"\t\t\t\t\t\tPress 6: To QUIT\n";

}
//***************************************************************
// END OF PROJECT
//**************************************************************