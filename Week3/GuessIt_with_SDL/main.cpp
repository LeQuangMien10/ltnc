#include "Common_Function.h"
#include "BaseObject.h"
#include "TextObject.h"

#undef main

bool Init()
{
	//Initialize screen
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return false;
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
		return false;

	//Initialize fonts
	if (TTF_Init() == -1)
		return false;

	g_font_text = TTF_OpenFont("LoveDays-2v7Oe.ttf", 20);
	g_font_note = TTF_OpenFont("Paul-le1V.ttf", 10);
	g_font_input = TTF_OpenFont("Sendcat.ttf", 25);
	g_font_menu = TTF_OpenFont("Paul-le1V.ttf", 50);
	if (g_font_text == NULL or g_font_note == NULL or g_font_input == NULL)
		return false;


	return true;
}


int playGuessIt()
{
	//Generate random number
	srand(time(0));
	int randomNumber = rand() % 100 + 1;
	int count = 0;

	bool is_quit = false;
	if (Init() == false)
		return 0;

	//Load Background and bar
	g_bkground = SDLCommonFunction::LoadImage(g_name_background);
	g_bar = SDLCommonFunction::LoadImage(g_bar_name);
	g_textbox = SDLCommonFunction::LoadImage(g_name_textbox);
	if (g_bkground == NULL or g_textbox == NULL or g_bar == NULL)
		return 0;


	//Show Title
	TextObject title;
	title.setTextColor(TextObject::WHITE_TEXT);
	title.setText(title_content);
	title.SetRect(TITLE_X_POS, TITLE_Y_POS);

	//Get Input
	TextObject input;
	input.setTextColor(TextObject::BLACK_TEXT);
	input.SetRect(INPUT_X_POS, INPUT_Y_POS);

	int number_input = 0;
	std::string text_input = "";

	//Show result
	TextObject result;
	result.setTextColor(TextObject::BLACK_TEXT);
	result.SetRect(RESULT_X_POS, RESULT_Y_POS);

	//Show note
	TextObject note;
	note.setTextColor(TextObject::WHITE_TEXT);
	note.setText("Note: Use 'Keypad_Enter' instead of normal 'Enter");
	note.SetRect(0, 0);


	int ret_start_menu = SDLCommonFunction::ShowStartMenu(g_screen, g_font_menu);
	if (ret_start_menu == 1)
		is_quit = true;
	else
	{
		SDLCommonFunction::ApplySurface(g_bkground, g_screen, 0, 0);
		SDLCommonFunction::ApplySurface(g_bar, g_screen, BAR_X_POS, BAR_Y_POS);
		title.CreateText(g_font_text, g_screen);
		note.CreateText(g_font_note, g_screen);
	}
	

	while (!is_quit)
	{
		while (SDL_PollEvent(&g_even))
		{
			if (g_even.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			else if (g_even.type == SDL_KEYDOWN)
			{
				switch (g_even.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					is_quit = true;
					break;
				case SDLK_0: case SDLK_KP0:
					number_input = number_input * 10 + 0;
					text_input += '0';
					break;
				case SDLK_1: case SDLK_KP1:
					number_input = number_input * 10 + 1;
					text_input += '1';
					break;
				case SDLK_2: case SDLK_KP2:
					number_input = number_input * 10 + 2;
					text_input += '2';
					break;
				case SDLK_3: case SDLK_KP3:
					number_input = number_input * 10 + 3;
					text_input += '3';
					break;
				case SDLK_4: case SDLK_KP4:
					number_input = number_input * 10 + 4;
					text_input += '4';
					break;
				case SDLK_5: case SDLK_KP5:
					number_input = number_input * 10 + 5;
					text_input += '5';
					break;
				case SDLK_6: case SDLK_KP6:
					number_input = number_input * 10 + 6;
					text_input += '6';
					break;
				case SDLK_7: case SDLK_KP7:
					number_input = number_input * 10 + 7;
					text_input += '7';
					break;
				case SDLK_8: case SDLK_KP8:
					number_input = number_input * 10 + 8;
					text_input += '8';
					break;
				case SDLK_9: case SDLK_KP9:
					number_input = number_input * 10 + 9;
					text_input += '9';
					break;
				case SDLK_BACKSPACE:
					number_input /= 10;
					if (!text_input.empty())
						text_input.pop_back();
					SDLCommonFunction::ApplySurface(g_bkground, g_screen, 0, 0);
					SDLCommonFunction::ApplySurface(g_bar, g_screen, BAR_X_POS, BAR_Y_POS);
					title.CreateText(g_font_text, g_screen);
					note.CreateText(g_font_note, g_screen);
					break;
				case SDLK_KP_ENTER:
					count++;
					SDLCommonFunction::ApplySurface(g_bkground, g_screen, 0, 0);
					SDLCommonFunction::ApplySurface(g_bar, g_screen, BAR_X_POS, BAR_Y_POS);
					title.CreateText(g_font_text, g_screen);
					note.CreateText(g_font_note, g_screen);
					if (text_input != "")
					{
						SDLCommonFunction::ApplySurface(g_textbox, g_screen, TEXTBOX_X_POS, TEXTBOX_Y_POS);

						//Show result
						if (number_input == randomNumber)
						{
							result.setText("Correct!");
							result.CreateText(g_font_text, g_screen);

							int ret_end_menu = SDLCommonFunction::ShowEndMenu(g_screen, g_font_menu, count);
							if (ret_end_menu == 1)
								is_quit = true;
							else
							{
								srand(time(0));
								randomNumber = rand() % 100 + 1;
								count = 0;
								SDLCommonFunction::ApplySurface(g_bkground, g_screen, 0, 0);
								SDLCommonFunction::ApplySurface(g_bar, g_screen, BAR_X_POS, BAR_Y_POS);
								title.CreateText(g_font_text, g_screen);
								note.CreateText(g_font_note, g_screen);
							}
						}
						else if (number_input < randomNumber)
						{
							result.setText("Too Small!");
							result.CreateText(g_font_text, g_screen);
						}
						else if (number_input > randomNumber)
						{
							result.setText("Too Big!");
							result.CreateText(g_font_text, g_screen);
						}

						number_input = 0;
						text_input = "";
						break;
					}
				default:
					break;
				}
			}
			if (text_input.length() > 2)
			{
				number_input /= 10;
				text_input.pop_back();
				SDLCommonFunction::ApplySurface(g_bkground, g_screen, 0, 0);
				SDLCommonFunction::ApplySurface(g_bar, g_screen, BAR_X_POS, BAR_Y_POS);
				title.CreateText(g_font_text, g_screen);
				note.CreateText(g_font_note, g_screen);
			}
			input.setText(text_input);
			input.CreateText(g_font_input, g_screen);

			if (SDL_Flip(g_screen) == -1)
			{
				SDLCommonFunction::CleanUp();
				SDL_Quit();
				return 0;
			}
		}


		if (SDL_Flip(g_screen) == -1)
		{
			SDLCommonFunction::CleanUp();
			SDL_Quit();
			return 0;
		}

	}


}

int main(int argc, char* argv[])
{
	playGuessIt();

	if (SDL_Flip(g_screen) == -1)
	{
		SDLCommonFunction::CleanUp();
		SDL_Quit();
		return 0;
	}

	SDLCommonFunction::CleanUp();
	SDL_Quit();

	return 0;
}