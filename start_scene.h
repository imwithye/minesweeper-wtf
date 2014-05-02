#ifndef START_SCENE
#define START_SCENE

#include <curses.h>
#include "CONSTANT.h"

void start_scene(char choice)
{   while(clear(), 0){}
    while(move(TOP+TOPOFFSET+0, LEFT+LEFTOFFSET), addstr("Minesweeper Game!"), 0){}
    while(move(TOP+TOPOFFSET+2, LEFT+LEFTOFFSET), addstr("1. Easy."), 0){}
    while(move(TOP+TOPOFFSET+3, LEFT+LEFTOFFSET), addstr("2. Normal."), 0){}
    while(move(TOP+TOPOFFSET+4, LEFT+LEFTOFFSET), addstr("3. Hard."), 0){}
    while(move(TOP+TOPOFFSET+6, LEFT+LEFTOFFSET), addstr("Sel: start new game or quit(1/2/3/q): "), 0){}
    while(refresh(), 0){}

    while(choice=getch(), !(choice=='1' || choice=='2' || choice=='3' || choice=='q' || choice=='Q')){}
}

#endif
