#include <iostream>
#include <ctime>

using namespace std;

const int MAX_BAD_GUESS = 7;
const string WORD_LIST[] = { "angle", "ant", "apple", "arch", "arm", "army",
"baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
"bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
"brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
"cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
"chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
"cow", "cup", "curtain", "cushion",
"dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
"face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
"foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
"hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
"hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
"leaf", "leg", "library", "line", "lip", "lock",
"map", "match", "monkey", "moon", "mouth", "muscle",
"nail", "neck", "needle", "nerve", "net", "nose", "nut",
"office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
"pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
"rail", "rat", "receipt", "ring", "rod", "roof", "root",
"sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
"shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
"square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
"store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
"toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
"wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm" };
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
const string FIGURE[] = {
	" -------------   \n"
	" |               \n"
	" |               \n"
	" |               \n"
	" |               \n"
	" |               \n"
	" -----           \n",

	" -------------   \n"
	" |           |   \n"
	" |               \n"
	" |               \n"
	" |               \n"
	" |               \n"
	" -----           \n",

	" -------------   \n"
	" |           |   \n"
	" |           O   \n"
	" |               \n"
	" |               \n"
	" |               \n"
	" -----           \n",

	" -------------   \n"
	" |           |   \n"
	" |           O   \n"
	" |           |   \n"
	" |               \n"
	" |               \n"
	" -----           \n",

	" -------------   \n"
	" |           |   \n"
	" |           O   \n"
	" |          /|   \n"
	" |               \n"
	" |               \n"
	" -----           \n",

	" -------------   \n"
	" |           |   \n"
	" |           O   \n"
	" |          /|\\ \n"
	" |               \n"
	" |               \n"
	" -----           \n",

	" -------------   \n"
	" |           |   \n"
	" |           O   \n"
	" |          /|\\ \n"
	" |          /    \n"
	" |               \n"
	" -----           \n",

	" -------------   \n"
	" |           |   \n"
	" |           O   \n"
	" |          /|\\ \n"
	" |          / \\ \n"
	" |               \n"
	" -----           \n"

};

char keyboard[26] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
		'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
		'z', 'x', 'c', 'v', 'b', 'n', 'm'
};

char initialKeyboard[26] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
		'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
		'z', 'x', 'c', 'v', 'b', 'n', 'm'
};

string chooseSecretWord()
{
	srand(time(0));
	int index = rand() % WORD_COUNT;
	string secretWord = WORD_LIST[index];
	return secretWord;
}

void displayKeyboard()
{
	for (int i = 0; i < 26; i++)
	{
		if (i == 9)
		{
			cout << keyboard[i] << endl << ' ';
		}
		else if (i == 18)
		{
			cout << keyboard[i] << endl << "  ";
		}
		else if (i == 25)
		{
			cout << keyboard[i] << endl;
		}
		else
			cout << keyboard[i] << ' ';
	}
	cout << endl;
}

void updateKeyboard(char ch)
{
	for (int i = 0; i < 26; i++)
	{
		if (keyboard[i] == ch)
			keyboard[i] = '.';
	}
}

void renderGame(string guessWord, int badGuessCount)
{
	cout << FIGURE[badGuessCount] << endl;
	displayKeyboard();
	cout << guessWord << endl;
	cout << "Number of wrong guesses: " << badGuessCount << endl << endl;
}

char readAGuess()
{
	char ch;
	cout << "Enter your guess: ";
	cin >> ch;
	updateKeyboard(ch);
	return ch;
}

bool contains(string secretWord, char guess)
{
	for (char ch : secretWord)
		if (ch == guess)
			return true;
	return false;
}

string updateGuessWord(string &guessWord, string secretWord, char guess)
{
	int length = secretWord.length();
	for (int i = 0; i < length; i++)
		if (guess == secretWord[i])
			guessWord[i] = guess;
	return guessWord;
}

void displayGameResult(string secretWord, int badGuessCount)
{
	if (badGuessCount < MAX_BAD_GUESS)
		cout << "Congratulation! You won!" << endl;
	else
	{
		cout << "The secret word is: " << secretWord << endl << endl;
		cout << "You lose!" << endl << endl;
	}
}


void playHangman()
{
	string secretWord = chooseSecretWord();
	string guessWord = string(secretWord.length(), '_');
	int badGuessCount = 0;

	do {
		renderGame(guessWord, badGuessCount);
		char guess = readAGuess();
		if (contains(secretWord, guess))
			guessWord = updateGuessWord(guessWord, secretWord, guess);
		else badGuessCount++;
	} while (badGuessCount < MAX_BAD_GUESS and guessWord != secretWord);

	renderGame(guessWord, badGuessCount);
	displayGameResult(secretWord, badGuessCount);
}


int main(int argc, char* argv[])
{
	char option;
	do {
		playHangman();
		cout << "Do you want to continue?" << endl <<
			"    [Y]          [N]    " << endl;
		cin >> option;
		if (option != 'Y' and option != 'y' and option != 'n' and option != 'N')
		{
			cout << "Invalid choice!" << endl;
			cin >> option;
		}
		cout << endl;
		copy(begin(initialKeyboard), end(initialKeyboard), begin(keyboard));
	} while (option != 'N' and option != 'n');
	cout << "Good Bye!" << endl;
	return 0;
}