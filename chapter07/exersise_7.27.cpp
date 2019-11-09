#include <iostream>
#include <Screen.h>
using namespace std;

int main()
{
    Screen myScreen("testassfs");
    myScreen.mov(4).set('#').display();
    cout << "\n";
    myScreen.display();
    cout << "\n";
    return 0;
}
