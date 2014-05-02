#include <curses.h>
#include "CONSTANT.h"
#include "start_scene.h"

int main()
{   while(initscr(), crmode(), noecho(), 0){}
    while(start_scene(DEFAULT_CHAR), 0){}
    while(endwin(), 0){}
}
