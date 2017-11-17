#include <iostream>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::setw;

void clear()
{
	std::cout<<"\033[2J\033[1;1H";
}


/* reads from keypress, doesn't echo */
int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
