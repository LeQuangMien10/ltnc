#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateNumber()
{
    srand(time(0));
    return rand() % 100 + 1;
}

int getNumber()
{
    int guess;
    cout << "Enter your guess ";
    cin >> guess;
    if (guess > 100)
        guess = -1;
    else if (!std::cin)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        guess = -1;
    }
    else
    {
        cin.ignore(100000, '\n');
    }
    return guess;
}

void result(int guess, int answer, bool& con, int& count)
{
    if (guess == -1)
        cout << "Your input is invalid" << endl << endl;
    else if (guess < answer)
    {
        cout << "Too small!" << endl << endl;
        count++;
    }
    else if (guess > answer)
    {
        cout << "Too big!" << endl << endl;
        count++;
    }
    else
    {
        cout << "Correct!" << endl << endl;
        count++;
        cout << "You guessed " << count << " time(s)" << endl;
        con = false;
    }
}

void playGuessIt()
{
    int count = 0;
    int answer = generateNumber();
    bool check = true;
    while (check)
    {
        int guess = getNumber();
        result(guess, answer, check, count);
    }
}


int main()
{
    char option;
    do {
        playGuessIt();
        cout << "Do you want to continue?" << endl <<
        "    [Y]          [N]    " << endl;
        cin >> option;
        if (option != 'Y' and option != 'y' and option != 'n' and option != 'N')
        {
            cout << "Invalid choice!" << endl;
            cin >> option;
        }
    } while (option != 'N' and option != 'n');
    cout << "Good Bye!" << endl;
    return 0;
}
