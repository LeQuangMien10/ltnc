#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <ctime>
#include <cstdlib>

//Screen
const int SCREEN_WIDTH = 788;
const int SCREEN_HEIGHT = 438;
const int SCREEN_BPP = 32;

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static char g_name_background[] = ("bg.jpg");

const std::string title_content = "Your guess: ";
const int TITLE_X_POS = 350;
const int TITLE_Y_POS = 215;

//bar
const int BAR_WIDTH = 310;
const int BAR_HEIGHT = 60;

static SDL_Surface* g_bar = NULL;
static char g_bar_name[] = ("bar.jpg");

const int BAR_X_POS = (SCREEN_WIDTH - BAR_WIDTH) / 2;
const int BAR_Y_POS = 250;

//textBox
const int TEXTBOX_WIDTH = 200;
const int TEXTBOX_HEIGHT = 100;

static SDL_Surface* g_textbox = NULL;
static char g_name_textbox[] = ("TextBox.png");

const int TEXTBOX_X_POS = 0;
const int TEXTBOX_Y_POS = SCREEN_HEIGHT / 2 - TEXTBOX_HEIGHT;


static SDL_Event g_even;
static TTF_Font* g_font_text = NULL;
static TTF_Font* g_font_note = NULL;
static TTF_Font* g_font_input = NULL;
static TTF_Font* g_font_menu = NULL;



//Text
const int INPUT_X_POS = BAR_X_POS + BAR_WIDTH / 2 - 8;
const int INPUT_Y_POS = BAR_Y_POS + BAR_HEIGHT / 2 - 15;
const int RESULT_X_POS = TEXTBOX_X_POS + 50;
const int RESULT_Y_POS = TEXTBOX_Y_POS + 25;

//Menu
static SDL_Surface* g_start_menu;
static char g_name_start_menu[] = ("StartMenu.jpg");
const int START_PLAY_X_POS = 300;
const int START_PLAY_Y_POS = 200;
const int START_EXIT_X_POS = 300;
const int START_EXIT_Y_POS = 250;

static SDL_Surface* g_end_menu;
static char g_name_end_menu[] = ("board.jpg");
const int END_MENU_WIDTH = 640;
const int END_MENU_HEIGHT = 360;
const int END_MENU_X_POS = (SCREEN_WIDTH - END_MENU_WIDTH) / 2;
const int END_MENU_Y_POS = (SCREEN_HEIGHT - END_MENU_HEIGHT) / 2;

const int END_PLAY_X_POS = 2 * END_MENU_X_POS;
const int END_PLAY_Y_POS = 250;
const int END_EXIT_X_POS = END_MENU_WIDTH - 50;
const int END_EXIT_Y_POS = 250;

const int GUESS_COUNT_X_POS = 150;
const int GUESS_COUNT_Y_POS = 100;

const int QUESTION_X_POS = 150;
const int QUESTION_Y_POS = 150;

namespace SDLCommonFunction
{
	SDL_Surface* LoadImage(std::string file_path);
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();

	int ShowStartMenu(SDL_Surface* des, TTF_Font* font);
	int ShowEndMenu(SDL_Surface* des, TTF_Font* font, const int& count);
	bool CheckMouseFocus(const int& x, const int& y, const SDL_Rect& rect);
}




#endif
