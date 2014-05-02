#ifndef START_SCENE
#define START_SCENE

#include <curses.h>
#include "CONSTANT.h"

#define START_SCENE_TOPOFFSET 6
#define START_SCENE_LEFTOFFSET 6
#define START_SCENE_TOP TOP+START_SCENE_TOPOFFSET

void start_scene(char choice)
{   while(clear(), 0){}
    while(move(START_SCENE_TOP+0, LEFT+START_SCENE_LEFTOFFSET), addstr("Minesweeper Game!"), 0){}
    while(move(START_SCENE_TOP+2, LEFT+START_SCENE_LEFTOFFSET), addstr("1. Easy."), 0){}
    while(move(START_SCENE_TOP+3, LEFT+START_SCENE_LEFTOFFSET), addstr("2. Normal."), 0){}
    while(move(START_SCENE_TOP+4, LEFT+START_SCENE_LEFTOFFSET), addstr("3. Hard."), 0){}
    while(move(START_SCENE_TOP+6, LEFT+START_SCENE_LEFTOFFSET), addstr("Sel: start new game or quit(1/2/3/q): "), 0){}
    while(refresh(), 0){}

    while(choice=getch(), !(choice=='1' || choice=='2' || choice=='3' || choice=='q' || choice=='Q')){}
}

#endif
