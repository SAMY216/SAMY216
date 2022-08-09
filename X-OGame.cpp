#include <iostream>
using namespace std;

void replace(int, char);
void draw();
bool checkAvailability(int);
bool checkWinner(char);
char c1, c2, c3, c4, c5, c6, c7, c8, c9;
char currentPlayer = 'X';
void retype();

int main()
{
    while (true)
    {
        retype();
        cout << "Welcome to X-O game\n\n";
        int input;
        int counter = 0;
        draw();
        while (true)
        {
            cout << "Player " << currentPlayer << endl;
            cin >> input;
            while (!checkAvailability(input))
            {
                cout << "This number is already taken or it is unavailable number" << endl;
                cout << "Enter another number" << endl;
                cin >> input;
            }
            if (counter % 2 == 0)
            {
                replace(input, currentPlayer);
                currentPlayer = 'O';
            }
            else
            {
                replace(input, currentPlayer);
                currentPlayer = 'X';
            }
            draw();
            counter++;
            if (checkWinner('X') || checkWinner('O'))
                break;
            else if (counter == 9)
            {
                cout << "Draw" << endl;
                break;
            }
        }
        cout << "Do you want to play again ?\n1- continue\n2- exit" << endl;
        cin >> input;
        if (input == 1)
            continue;
        else
            break;
    }
    return 0;
}

void retype()
{
    c1 = '1';
    c2 = '2';
    c3 = '3';
    c4 = '4';
    c5 = '5';
    c6 = '6';
    c7 = '7';
    c8 = '8';
    c9 = '9';
}

void draw()
{
    cout << "\t||\t \t||\t \t||\t \t||" << endl;
    cout << "\t||\t" << c1;
    cout << "\t||\t" << c2;
    cout << "\t||\t" << c3 << "\t||" << endl;
    cout << "\t||\t \t||\t \t||\t \t||" << endl;
    cout << "\t==================================================" << endl;
    cout << "\t||\t \t||\t \t||\t \t||" << endl;
    cout << "\t||\t" << c4;
    cout << "\t||\t" << c5;
    cout << "\t||\t" << c6 << "\t||" << endl;
    cout << "\t||\t \t||\t \t||\t \t||" << endl;
    cout << "\t==================================================" << endl;
    cout << "\t||\t \t||\t \t||\t \t||" << endl;
    cout << "\t||\t" << c7;
    cout << "\t||\t" << c8;
    cout << "\t||\t" << c9 << "\t||" << endl;
    cout << "\t||\t \t||\t \t||\t \t||" << endl;
}

void replace(int i, char c)
{
    switch (i)
    {
    case 1:
        c1 = c;
        break;
    case 2:
        c2 = c;
        break;
    case 3:
        c3 = c;
        break;
    case 4:
        c4 = c;
        break;
    case 5:
        c5 = c;
        break;
    case 6:
        c6 = c;
        break;
    case 7:
        c7 = c;
        break;
    case 8:
        c8 = c;
        break;
    case 9:
        c9 = c;
        break;
    }
}

bool checkAvailability(int input)
{
    if (input < 1 || input > 9)
        return false;
    switch (input)
    {
    case 1:
        if (c1 == '1')
            return true;
        break;
    case 2:
        if (c2 == '2')
            return true;
        break;
    case 3:
        if (c3 == '3')
            return true;
        break;
    case 4:
        if (c4 == '4')
            return true;
        break;
    case 5:
        if (c5 == '5')
            return true;
        break;
    case 6:
        if (c6 == '6')
            return true;
        break;
    case 7:
        if (c7 == '7')
            return true;
        break;
    case 8:
        if (c8 == '8')
            return true;
        break;
    case 9:
        if (c9 == '9')
            return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}

bool checkWinner(char player)
{
    bool ro1(c1 == player && c2 == player && c3 == player);
    bool ro2(c4 == player && c5 == player && c6 == player);
    bool ro3(c7 == player && c8 == player && c9 == player);
    bool cl1(c1 == player && c4 == player && c7 == player);
    bool cl2(c2 == player && c5 == player && c8 == player);
    bool cl3(c3 == player && c6 == player && c9 == player);
    bool di1(c1 == player && c5 == player && c9 == player);
    bool di2(c3 == player && c5 == player && c7 == player);

    if (ro1 || ro2 || ro3 || cl1 || cl2 || cl3 || di1 || di2)
    {
        cout << "Player " << player << " won" << endl;
        return true;
    }
    return false;
}