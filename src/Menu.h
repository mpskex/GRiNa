#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <iostream> 
#include <thread>
#include <list>
#include <vector>

#include "GR_Particle.h"
#include "GR_Button.h"
#include "GR_Background.h"
#include "GR_Element.h"
#include "GR_Resource.h"

#include "GR_Log.h"
#include "Vector2D.h"

/*****************************
#	文件名：	Menu.h
#	日期：		2017-8-17
#	版本号：	0.4.0
#	功能：		菜单对象 
#	mpsk's game engine proj
*****************************/ 

#define MENU_NEWGAME	0xF001
#define MENU_RESUME		0xF002
#define MENU_OPTION		0xF003
#define MENU_ABOUT		0xF004
#define	MENU_QUIT		0xFFFF

#define MENU_CITY1		0xE001
#define MENU_CITY2		0xE002
#define MENU_CITY3		0xE003

#define MENU_MARGIN		60
#define MENU_BUTTON_W	160
#define MENU_BUTTON_H	50


class Menu
{
	private:
		SDL_Renderer *renderer;
		SDL_Event event;
		vector<SDL_RWops*> resources;
		GR_Background *background;

		GR_ElementList *button_list;
		GR_ElementList *plain_list;
		GR_ResourceManager *res_manager;

		int Quit();
	public:
		int SCREEN_WIDTH;		//画面分辨率 
		int SCREEN_HEIGHT;
		bool quit = false;
		Menu(SDL_Renderer *renderer, int w, int h);
		~Menu();
        int Init();
        int Load(std::string filename);
		Uint32 Loop();
};


#endif