#ifndef START_SCENE
#define START_SCENE

#include <curses.h>
#include "CONSTANT.h"
#include "game_scene.h"

void start_scene(char choice, int loop_c)
{   while(loop_c=1, 0){}
    while(loop_c)
    {
        while(clear(), 0){}
        while(move(TOP+TOPOFFSET+0, LEFT+LEFTOFFSET), addstr("Minesweeper Game!"), 0){}
        while(move(TOP+TOPOFFSET+2, LEFT+LEFTOFFSET), addstr("1. Easy."), 0){}
        while(move(TOP+TOPOFFSET+3, LEFT+LEFTOFFSET), addstr("2. Normal."), 0){}
        while(move(TOP+TOPOFFSET+4, LEFT+LEFTOFFSET), addstr("3. Hard."), 0){}
        while(move(TOP+TOPOFFSET+6, LEFT+LEFTOFFSET), addstr("Sel: start new game or quit(1/2/3/q): "), 0){}
        while(refresh(), 0){}
    
        while(choice=getch(), !(choice=='1' || choice=='2' || choice=='3' || choice=='q' || choice=='Q')){}
        if(choice=='1')
        {   while(game_scene(10), 0){}
        }
        else if(choice=='2')
        {   while(game_scene(15), 0){}
        }
        else if(choice=='3')
        {   while(game_scene(25), 0){}
        }
        else
        {   while(loop_c=0, 0){}
        }
    }
}

#endif
