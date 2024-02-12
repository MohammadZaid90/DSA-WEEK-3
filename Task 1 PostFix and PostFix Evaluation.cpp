#include<iostream>
#include"Header.h"
#include"Header1.h"

using namespace std;

int main()
{
    Solution s;
    Solution1 s1;

    cout << "The Postfix Expression Outputs!! \n\n\n";
    cout<<s.calculatePostfix("134*2/+53*-6+7^");
    cout << "\n" << s.calculatePostfix("23*4+");
    cout << "\n" << s.calculatePostfix("562+*4/");
    cout << "\n" << s.calculatePostfix("32+456--*");

    cout << "\n\n\nThe PreFix Expression Outputs!! \n\n\n";
    cout << s1.calculatePrefix("+*234")<<endl;
    cout << s1.calculatePrefix("/*5+624")<<"\n\n\n";
}