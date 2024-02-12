#pragma once
#include<iostream>
#include<stack>

using namespace std;

class Solutions {
public:
	bool isAlpha(char alpha)
	{
		if (alpha >= 'a' && alpha <= 'z' || alpha >= 'A' && alpha <= 'Z')
		{
			return true;
		}

		return 0;
	}

	bool isdigit(char digit)
	{
		if (digit >= '0' && digit <= '9')
		{
			return true;
		}

		return 0;
	}

	int precedence(char pf)
	{
		if (pf == '+' || pf == '-')
		{
			return 1;
		}
		if (pf == '*' || pf == '/')
		{
			return 2;
		}
		if (pf == '^')
		{
			return 3;
		}

		return 0;
	}

	string InfixToPostFix(string infix)
	{
		int length = infix.length();
		string postFix = "";
		stack<char> sk;

		for (int i = 0; i < length; i++)
		{
			if (isalpha(infix[i]) || isdigit(infix[i]))
			{
				postFix += infix[i];
			}
			/*else if (infix[i] >= '0' && infix[i] <= '9')
			{
				postFix += infix[i];
			}*/
			else if (infix[i] == '(')
			{
				sk.push(infix[i]);
			}
			else if (infix[i] == ')')
			{
				while (sk.top() != '(')
				{
					postFix += sk.top();
					sk.pop();
				}
				sk.pop();
			}
			else {
				while (!sk.empty() && precedence(infix[i]) <= precedence(sk.top()))
				{
					postFix += sk.top();
					sk.pop();
				}
				sk.push(infix[i]);
			}
		}
		while(!sk.empty())
		{
			postFix += sk.top();
			sk.pop();
		}

		return postFix;
	}
};