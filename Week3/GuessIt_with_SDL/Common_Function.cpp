#include "Common_Function.h"
#include "TextObject.h"

SDL_Surface* SDLCommonFunction::LoadImage(std::string file_path)
{
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;

	load_image = IMG_Load(file_path.c_str());
	if (load_image != NULL)
	{
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);
		if (optimize_image != NULL)
		{
			UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0xFF, 0xFF);
			SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
		}
	}

	return optimize_image;
}


SDL_Rect SDLCommonFunction::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);

	return offset;
}

void SDLCommonFunction::CleanUp()
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
}

int SDLCommonFunction::ShowStartMenu(SDL_Surface* des, TTF_Font* font)
{
    g_start_menu = LoadImage(g_name_start_menu);
    if (g_start_menu == NULL)
        return 1;

    const int NumberofMenuItem = 2;
    SDL_Rect pos_arr[NumberofMenuItem];
    pos_arr[0].x = START_PLAY_X_POS;
    pos_arr[0].y = START_PLAY_Y_POS;

    pos_arr[1].x = START_EXIT_X_POS;
    pos_arr[1].y = START_EXIT_Y_POS;

    TextObject text_menu[NumberofMenuItem];
    text_menu[0].setText("Play Game");
    text_menu[0].setTextColor(TextObject::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].setText("Exit");
    text_menu[1].setTextColor(TextObject::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);


    bool selected[NumberofMenuItem] = { 0, 0 };
    int xm = 0;
    int ym = 0;
    SDL_Event m_event;
    while (true)
    {
        SDLCommonFunction::ApplySurface(g_start_menu, des, 0, 0);
        for (int i = 0; i < NumberofMenuItem; i++)
        {
            text_menu[i].CreateText(font, des);
        }

        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return 1;
            case SDL_MOUSEMOTION:
                xm = m_event.motion.x;
                ym = m_event.motion.y;

                for (int j = 0; j < NumberofMenuItem; j++)
                {
                    if (CheckMouseFocus(xm, ym, text_menu[j].GetRect()))
                    {
                        if (selected[j] == false)
                        {
                            selected[j] = 1;
                            text_menu[j].setTextColor(TextObject::RED_TEXT);
                        }
                    }
                    else
                    {
                        if (selected[j] == true)
                        {
                            selected[j] = 0;
                            text_menu[j].setTextColor(TextObject::BLACK_TEXT);
                        }
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                xm = m_event.button.x;
                ym = m_event.button.y;

                for (int j = 0; j < NumberofMenuItem; j++)
                {
                    if (CheckMouseFocus(xm, ym, text_menu[j].GetRect()))
                        return j;
                }
                break;
            case SDL_KEYDOWN:
                if (m_event.key.keysym.sym == SDLK_ESCAPE)
                    return 1;
                break;
            default:
                break;
            }
        }
        SDL_Flip(des);
    }

    return 1;
}

int SDLCommonFunction::ShowEndMenu(SDL_Surface* des, TTF_Font* font, const int& count)
{
    g_end_menu = LoadImage(g_name_end_menu);
    if (g_end_menu == NULL)
        return 1;


    const int NumberofMenuItem = 2;
    SDL_Rect pos_arr[NumberofMenuItem];
    pos_arr[0].x = END_PLAY_X_POS;
    pos_arr[0].y = END_PLAY_Y_POS;

    pos_arr[1].x = END_EXIT_X_POS;
    pos_arr[1].y = END_EXIT_Y_POS;

    TextObject text_menu[NumberofMenuItem];
    text_menu[0].setText("Play Again");
    text_menu[0].setTextColor(TextObject::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].setText("Exit");
    text_menu[1].setTextColor(TextObject::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);


    bool selected[NumberofMenuItem] = { 0, 0 };
    int xm = 0;
    int ym = 0;
    SDL_Event m_event;
    while (true)
    {
        SDLCommonFunction::ApplySurface(g_end_menu, des, END_MENU_X_POS, END_MENU_Y_POS);

        //Create Guess Count Line
        TextObject guess_count;
        guess_count.SetRect(GUESS_COUNT_X_POS, GUESS_COUNT_Y_POS);
        guess_count.setTextColor(TextObject::BLACK_TEXT);
        std::string str_count_val = std::to_string(count);
        std::string str_count = "You have guessed " + str_count_val + " time(s)";
        guess_count.setText(str_count);
        guess_count.CreateText(font, des);


        //Create Play Again Question
        TextObject question;
        question.SetRect(QUESTION_X_POS, QUESTION_Y_POS);
        question.setTextColor(TextObject::BLACK_TEXT);
        question.setText("Do you want to play again?");
        question.CreateText(font, des);

        for (int i = 0; i < NumberofMenuItem; i++)
        {
            text_menu[i].CreateText(font, des);
        }

        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return 1;
            case SDL_MOUSEMOTION:
                xm = m_event.motion.x;
                ym = m_event.motion.y;

                for (int j = 0; j < NumberofMenuItem; j++)
                {
                    if (CheckMouseFocus(xm, ym, text_menu[j].GetRect()))
                    {
                        if (selected[j] == false)
                        {
                            selected[j] = 1;
                            text_menu[j].setTextColor(TextObject::RED_TEXT);
                        }
                    }
                    else
                    {
                        if (selected[j] == true)
                        {
                            selected[j] = 0;
                            text_menu[j].setTextColor(TextObject::BLACK_TEXT);
                        }
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                xm = m_event.button.x;
                ym = m_event.button.y;

                for (int j = 0; j < NumberofMenuItem; j++)
                {
                    if (CheckMouseFocus(xm, ym, text_menu[j].GetRect()))
                        return j;
                }
                break;
            case SDL_KEYDOWN:
                if (m_event.key.keysym.sym == SDLK_ESCAPE)
                    return 1;
                break;
            default:
                break;
            }
        }
        SDL_Flip(des);
    }

    return 1;
}

bool SDLCommonFunction::CheckMouseFocus(const int& x, const int& y, const SDL_Rect& rect)
{
    if (x >= rect.x and x < rect.x + rect.w and y >= rect.y and y <= rect.y + rect.h)
        return true;
    return false;
}


