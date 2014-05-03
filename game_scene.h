#ifndef GAME_SCENE
#define GAME_SCENE

#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "CONSTANT.h"

#define random(x) (rand()%x)
#define GAME_SCENE_BOARD_LEFT LEFT+LEFTOFFSET
#define GAME_SCENE_BOARD_TOP TOP+TOPOFFSET+3
#define GAME_SCENE_BOARD_OFFSET 2

static void game_scene_print_face(char** face, int size, int lastv, int lasth, int loop_c)
{   while(clear(), 0){}

    while(move(TOP+TOPOFFSET+0, LEFT+LEFTOFFSET), addstr("Current State:"), 0){}
    
    while(loop_c=0, 0){}
    while(loop_c<size*size)
    {   while(move(GAME_SCENE_BOARD_TOP+loop_c/size, GAME_SCENE_BOARD_LEFT+GAME_SCENE_BOARD_OFFSET*(loop_c%size)), addch(face[loop_c/size][loop_c%size]), 0){}
        while(loop_c++, 0){}
    }
    
    while(move(lastv, lasth), 0){}
    while(refresh(), 0){}
    while(getch(), 0){}
}

static void game_scene_init(int ** ans, char ** face, int size, int loop_c, int i, int j)
{   while(srand((int)time(0)), 0){}
    while(keypad(stdscr, 1), 0){}
    while(loop_c=0, 0){}
    while(loop_c<size)
    {   while(ans[loop_c] = (int*)malloc(sizeof(int)*size), 0){}
        while(face[loop_c] = (char*)malloc(sizeof(char)*size), 0){}
        while(loop_c++, 0){}
    }

    while(loop_c=0, 0){}
    while(loop_c<size*size)
    {   while(face[loop_c/size][loop_c%size]=UNOPEN, 0){}
        while(loop_c++, 0){}
    }
    
    while(loop_c=0, 0){}
    while(loop_c<size*size)
    {   while(ans[loop_c/size][loop_c%size]=0, 0){}
        while(loop_c++, 0){}
    }
    while(loop_c=0, 0){}
    while(loop_c<size)
    {   while(i=random(size), 0){}
        while(j=random(size), 0){}
        if(ans[i][j]!=-1)
        {   while(ans[i][j]=-1, loop_c++, 0){}
        }
    }
    while(loop_c=0, 0){}
    while(loop_c<size*size)
    {   if(ans[loop_c/size][loop_c%size]!=-1)
        {
            if(loop_c/size==0)
            {   if(loop_c%size==0)
                {   if(ans[loop_c/size+1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                }
                else if(loop_c%size==size-1)
                {   if(ans[loop_c/size+1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                }
                else
                {   if(ans[loop_c/size+1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                }
            }
            else if(loop_c/size==size-1)
            {   if(loop_c%size==0)
                {   if(ans[loop_c/size-1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size-1][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                }
                else if(loop_c%size==size-1)
                {   if(ans[loop_c/size-1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size-1][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                }
                else
                {   if(ans[loop_c/size-1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size-1][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size-1][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                }
            }
            else
            {   if(loop_c%size==0)
                {   if(ans[loop_c/size-1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size-1][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                }
                else if(loop_c%size==size-1)
                {   if(ans[loop_c/size-1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size-1][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                }
                else
                {   if(ans[loop_c/size-1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size-1][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size-1][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size-1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                    if(ans[loop_c/size+1][loop_c%size+1]==-1)
                    {   while(ans[loop_c/size][loop_c%size]++, 0){}
                    }
                }
            }
        }
        while(loop_c++, 0){}
    }

    while(loop_c=0, 0){}
    while(loop_c<size*size)
    {   while(face[loop_c/size][loop_c%size] = ans[loop_c/size][loop_c%size] == -1 ? MINE : ans[loop_c/size][loop_c%size]+'0', 0){}
        while(loop_c++, 0){}
    }
    while(game_scene_print_face(face, size, GAME_SCENE_BOARD_TOP, GAME_SCENE_BOARD_LEFT, DEFAULT_INT), 0){}
}

void game_scene(int size)
{   while(game_scene_init((int**)malloc(sizeof(int*)*size), (char**)malloc(sizeof(char*)*size), size, DEFAULT_INT, DEFAULT_INT, DEFAULT_INT), 0){}
}

#endif
