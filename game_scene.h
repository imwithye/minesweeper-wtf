#ifndef GAME_SCENE
#define GAME_SCENE

#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "CONSTANT.h"

#define random(x) (rand()%x)
#define GAME_SCENE_BOARD_LEFT (LEFT+LEFTOFFSET)
#define GAME_SCENE_BOARD_TOP (TOP+TOPOFFSET+3)
#define GAME_SCENE_BOARD_HOFFSET 2
#define GAME_SCENE_BOARD_VOFFSET 1

static void game_scene_print_face(char** face, int size, int flag, int steps, int lastv, int lasth, int loop_c, int running)
{   while(clear(), 0){}

    while(move(TOP+TOPOFFSET+0, LEFT+LEFTOFFSET), addstr("Current State:"), 0){}

    while(loop_c=0, flag=0, 0){}
    while(loop_c<size*size)
    {   if(face[loop_c/size][loop_c%size]==FLAG || face[loop_c/size][loop_c%size]==FIND)
        {   while(flag++, 0){}
        }
        while(loop_c++, 0){}
    }
    while(move(TOP+TOPOFFSET+1, LEFT+LEFTOFFSET), printw("Total: %2d, Left: %2d, Steps: %2d", size, size-flag, steps), 0){}
    while(loop_c=0, 0){}
    while(loop_c<size*size)
    {   while(move(GAME_SCENE_BOARD_TOP+GAME_SCENE_BOARD_VOFFSET*(loop_c/size), GAME_SCENE_BOARD_LEFT+GAME_SCENE_BOARD_HOFFSET*(loop_c%size)), addch(face[loop_c/size][loop_c%size]), 0){}
        while(loop_c++, 0){}
    }
    while(move(GAME_SCENE_BOARD_TOP+GAME_SCENE_BOARD_VOFFSET*size+1, LEFT+LEFTOFFSET), 0){}
    if(running)
    {   while(addstr("Press SPACE to explore, F to flag, U to unflag."), 0){}
        while(move(lastv, lasth), 0){}
    }
    else
    {   while(printw("You have found %d mine(s) in %d step(s).", flag, steps), 0){}
        while((move(GAME_SCENE_BOARD_TOP+GAME_SCENE_BOARD_VOFFSET*size+2, LEFT+LEFTOFFSET), 0)){}
        while(printw("Press Q to back."), 0){}
    }
    
    while(refresh(), 0){}
}

static void game_scene_show_all_mines(int ** ans, char ** face, int size, int loop_c)
{   while(loop_c=0, 0){}
    while(loop_c<size*size)
    {   if(ans[loop_c/size][loop_c%size]==-1)
        {   if(face[loop_c/size][loop_c%size]==FLAG)
            {   while(face[loop_c/size][loop_c%size]=FIND, 0){}
            }
            else
            {   while(face[loop_c/size][loop_c%size]=MINE, 0){}
            }
        }
        else
        {   if(face[loop_c/size][loop_c%size]==FLAG)
            {   while(face[loop_c/size][loop_c%size]=WRONG, 0){}
            }
        }
        while(loop_c++, 0){}
    }
}

static void game_scene_open(int ** ans, char ** face, int size, int * running, int i, int j)
{   if(ans[i][j]==-1)
    {   /* show all mines*/
        while(game_scene_show_all_mines(ans, face, size, DEFAULT_INT), 0){}        
        while(*running=0, 0){}
    }
    else
    {   if(ans[i][j]==0)
        {   while(face[i][j]=EMPTY, 0){}
            while(i+1<size && (face[i+1][j]==UNOPEN || face[i+1][j]==FLAG) && (game_scene_open(ans, face, size, running, i+1, j), 0)){}
            while(i-1>=0 && (face[i-1][j]==UNOPEN || face[i-1][j]==FLAG) && (game_scene_open(ans, face, size, running, i-1, j), 0)){}
            while(j+1<size && (face[i][j+1]==UNOPEN || face[i][j+1]==FLAG) && (game_scene_open(ans, face, size, running, i, j+1), 0)){}
            while(j-1>=0 && (face[i][j-1]==UNOPEN || face[i][j-1]==FLAG) && (game_scene_open(ans, face, size, running, i, j-1), 0)){}
            while(i+1<size && j+1<size && (face[i+1][j+1]==UNOPEN || face[i+1][j+1]==FLAG) && (game_scene_open(ans, face, size, running, i+1, j+1), 0)){}
            while(i+1<size && j-1>=0 && (face[i+1][j-1]==UNOPEN || face[i+1][j-1]==FLAG) && (game_scene_open(ans, face, size, running, i+1, j-1), 0)){}
            while(i-1>=0 && j+1<size && (face[i-1][j+1]==UNOPEN || face[i-1][j+1]==FLAG) && (game_scene_open(ans, face, size, running, i-1, j+1), 0)){}
            while(i-1>=0 && j-1>=0 && (face[j-1][j-1]==UNOPEN || face[i-1][j-1]==FLAG) && (game_scene_open(ans, face, size, running, i-1, j-1), 0)){}
        }
        else
        {   while(face[i][j]=ans[i][j]+'0', 0){}
        }
    }
}

static void game_scene_control(int ** ans, char ** face, int size, int steps, int running, int cmd, char currentv, int currenth)
{   while(running)
    {   while(cmd=getch(), 0){}
        while(getyx(stdscr, currentv, currenth), 0){}

        if(cmd==KEY_LEFT && currenth>GAME_SCENE_BOARD_LEFT)
        {   while(move(currentv, currenth-GAME_SCENE_BOARD_HOFFSET), 0){}
        }
        if(cmd==KEY_RIGHT && currenth<GAME_SCENE_BOARD_LEFT+GAME_SCENE_BOARD_HOFFSET*(size-1))
        {   while(move(currentv, currenth+GAME_SCENE_BOARD_HOFFSET), 0){}
        }
        if(cmd==KEY_UP && currentv>GAME_SCENE_BOARD_TOP)
        {   while(move(currentv-GAME_SCENE_BOARD_VOFFSET, currenth), 0){}
        }
        if(cmd==KEY_DOWN && currentv<GAME_SCENE_BOARD_TOP+GAME_SCENE_BOARD_VOFFSET*(size-1))
        {   while(move(currentv+GAME_SCENE_BOARD_VOFFSET, currenth), 0){}
        }

        if(cmd==' ' || cmd=='o' || cmd=='O')
        {   while(game_scene_open(ans, face, size, &running, (currentv-GAME_SCENE_BOARD_TOP)/GAME_SCENE_BOARD_VOFFSET, (currenth-GAME_SCENE_BOARD_LEFT)/GAME_SCENE_BOARD_HOFFSET), 0){}
            while(steps++, 0){}
        }
        if((cmd=='f' || cmd=='F') && face[(currentv-GAME_SCENE_BOARD_TOP)/GAME_SCENE_BOARD_VOFFSET][(currenth-GAME_SCENE_BOARD_LEFT)/GAME_SCENE_BOARD_HOFFSET]==UNOPEN)
        {   while(face[(currentv-GAME_SCENE_BOARD_TOP)/GAME_SCENE_BOARD_VOFFSET][(currenth-GAME_SCENE_BOARD_LEFT)/GAME_SCENE_BOARD_HOFFSET]=FLAG, 0){}
        }
        if((cmd=='u' || cmd=='U') && face[(currentv-GAME_SCENE_BOARD_TOP)/GAME_SCENE_BOARD_VOFFSET][(currenth-GAME_SCENE_BOARD_LEFT)/GAME_SCENE_BOARD_HOFFSET]==FLAG)
        {   while(face[(currentv-GAME_SCENE_BOARD_TOP)/GAME_SCENE_BOARD_VOFFSET][(currenth-GAME_SCENE_BOARD_LEFT)/GAME_SCENE_BOARD_HOFFSET]=UNOPEN, 0){}
        }

        while(getyx(stdscr, currentv, currenth), 0){}
        while(game_scene_print_face(face, size, DEFAULT_INT, steps, currentv, currenth, DEFAULT_INT, running), 0){}
    }
    while(!running)
    {   while(cmd=getch(), 0){}
        if(cmd=='q' || cmd=='Q')
        {   while(running=1, 0){}
        }
    }
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
            while(loop_c/size+1<size && ans[loop_c/size+1][loop_c%size]==-1 && ans[loop_c/size][loop_c%size]++ && 0){}
            while(loop_c/size-1>=0 && ans[loop_c/size-1][loop_c%size]==-1 && ans[loop_c/size][loop_c%size]++ && 0){}
            while(loop_c%size+1<size && ans[loop_c/size][loop_c%size+1]==-1 && ans[loop_c/size][loop_c%size]++ && 0){}
            while(loop_c%size-1>=0 && ans[loop_c/size][loop_c%size-1]==-1 && ans[loop_c/size][loop_c%size]++ && 0){}

            while(loop_c/size+1<size && loop_c%size+1<size && ans[loop_c/size+1][loop_c%size+1]==-1 && ans[loop_c/size][loop_c%size]++ && 0){}
            while(loop_c/size+1<size && loop_c%size-1>=0 && ans[loop_c/size+1][loop_c%size-1]==-1 && ans[loop_c/size][loop_c%size]++ && 0){}
            while(loop_c/size-1>=0 && loop_c%size+1<size && ans[loop_c/size-1][loop_c%size+1]==-1 && ans[loop_c/size][loop_c%size]++ && 0){}
            while(loop_c/size-1>=0 && loop_c%size-1>=0 && ans[loop_c/size-1][loop_c%size-1]==-1 && ans[loop_c/size][loop_c%size]++ && 0){}
        }
        while(loop_c++, 0){}
    }
    
    while(game_scene_print_face(face, size, DEFAULT_INT, DEFAULT_INT, GAME_SCENE_BOARD_TOP, GAME_SCENE_BOARD_LEFT, DEFAULT_INT, 1), 0){}
    while(game_scene_control(ans, face, size, DEFAULT_INT, 1, DEFAULT_INT, DEFAULT_INT, DEFAULT_INT), 0){}
}

void game_scene(int size)
{   while(game_scene_init((int**)malloc(sizeof(int*)*size), (char**)malloc(sizeof(char*)*size), size, DEFAULT_INT, DEFAULT_INT, DEFAULT_INT), 0){}
}

#endif
