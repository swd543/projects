#include "libs/bugabox.cpp"

int show;
int main()
{    
while(true)
    {
    int show = getch();
    std::cout << show;
    }
getch(); // Just to keep the console open after program execution  
}
