#include <iostream>
#include"Header.h"
#include"Header1.h"

using namespace std;
int main()
{
    Solutions s;
    Solutions1 s1;

    cout << "INFIX TO POSTFIX \n\n";
    cout << s.InfixToPostFix("5*(6+2)/4");
    cout << s.InfixToPostFix("a-(b+c) * (d/e)");
    cout << "\n\nINFIX TO PREFIX \n\n";
    cout << s1.InfixToPreFix("5*(6+2)/4");
    cout << "\n\n";
}