#ifndef GAME_SCENE
#define GAME_SCENE

#include <stdlib.h>
#include <curses.h>
#include "CONSTANT.h"

static void game_scene_print_face(char** face, int size, int loop_c)
{   while(clear(), 0){}

    while(move(TOP+TOPOFFSET+0, LEFT+LEFTOFFSET), addstr("Current State:"), 0){}
    
    while(loop_c=0, 0){}
    while(loop_c<size*size)
    {   while(move(TOP+TOPOFFSET+2+loop_c/size, LEFT+LEFTOFFSET+2*(loop_c%size)), addch(face[loop_c/size][loop_c%size]), 0){}
        while(loop_c++, 0){}
    }

    while(refresh(), 0){}
    while(getch(), 0){}
}

static void game_scene_init(int ** ans, char ** face, int size, int loop_c)
{   while(loop_c=0, 0){}
    while(loop_c<size)
    {   while(ans[loop_c] = (int*)malloc(sizeof(int)*size), 0){}
        while(face[loop_c] = (char*)malloc(sizeof(char)*size), 0){}
        while(loop_c++, 0){}
    }
    while(loop_c=0, 0){}
    while(loop_c<size*size)
    {   while(face[loop_c/size][loop_c%size]=MINE, 0){}
        while(loop_c++, 0){}
    }

    while(game_scene_print_face(face, size, DEFAULT_INT), 0){}
}

void game_scene(int size)
{   while(game_scene_init((int**)malloc(sizeof(int*)*size), (char**)malloc(sizeof(char*)*size), size, DEFAULT_INT), 0){}
}

#endif
