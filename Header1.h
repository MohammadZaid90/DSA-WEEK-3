#pragma once
#include<iostream>
#include<stack>

using namespace std;

class Solutions1 {
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

	bool isOperator(char c)
	{
		return (!isalpha(c) && !isdigit(c));
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
		infix = '(' + infix + ')';
		int length = infix.length();
		string postFix = "";
		stack<char> sk;

		for (int i = 0; i < length; i++)
		{
			if (isalpha(infix[i]) || isdigit(infix[i]))
			{
				postFix += infix[i];
			}
			else if (infix[i] >= '0' && infix[i] <= '9')
			{
				postFix += infix[i];
			}
			else if (infix[i] == '(')
			{
				sk.push('(');
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
				if (isOperator(sk.top()))
				{
					if (infix[i] == '^')
					{
						while (precedence(infix[i]) <= precedence(sk.top()))
						{
							postFix += sk.top();
							sk.pop();
						}
					}
					else {
						while (precedence(infix[i]) < precedence(sk.top()))
						{
							postFix += sk.top();
							sk.pop();
						}
					}
					sk.push(infix[i]);
				}
			}
		}
		while (!sk.empty())
		{
			postFix += sk.top();
			sk.pop();
		}

		return postFix;
	}

	string InfixToPreFix(string infix)
	{
		int length = infix.length();
		reverse(infix.begin(), infix.end());

		for (int i = 0; i < length; i++)
		{
			if (infix[i] == '(')
			{
				infix[i] = ')';
			}
			else if (infix[i] == ')')
			{
				infix[i] = '(';
			}
		}
		string preFix = InfixToPostFix(infix);

		reverse(preFix.begin(), preFix.end());

		return preFix;

	}
};