//BY:
//Sagar Agrawal
//21COB298
//GM6623-A2CO-41

#include <iostream>
#include <stack>
#include<math.h>
#include <algorithm>
using namespace std;

int precidence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

string Infix_to_Prefix(string s1)
{
    reverse(s1.begin(), s1.end());
    
    string s2;
    stack<char> stk;
    

    for (int i = 0 ; i < s1.length() ; i++)
    {
        if (s1[i] >= '0' && s1[i] <= '9')
        {
            s2 += s1[i];
        }
        else if (s1[i] == ')')
        {
            stk.push(s1[i]);
        }
        else if (s1[i] == '(')
        {
            while (!stk.empty() && stk.top() != ')')
            {
                s2 += stk.top();
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else
        {
            while (!stk.empty() && precidence(stk.top()) > precidence(s1[i]))
            {
                s2 += stk.top();
                stk.pop();
            }
            stk.push(s1[i]);
        }
        
        
    }
    while (!stk.empty())
    {
        s2 += stk.top();
        stk.pop();
    }
    
    reverse(s2.begin(), s2.end());
    return s2;
}

int Evaluate_prefix(string s1)
{
    stack<int> stk;
    for(int i= s1.length()-1; i>=0; i--)
    {
        if(s1[i]>='0' && s1[i]<='9')
        {
            stk.push(s1[i]-'0');
        }
        else{
            int A=stk.top();
            stk.pop();
            int B=stk.top();
            stk.pop();

            switch(s1[i])
            {
                case '^':
                    stk.push(pow(A,B));
                    break;
                case '/':
                    stk.push(A/B);
                    break;
                case '*':
                    stk.push(A*B);
                    break;
                case '+':
                    stk.push(A+B);
                    break;
                case '-':
                    stk.push(A-B);
                    break;
            }
        }
        
    
    }
    return stk.top();
}


int main()
{
    cout << "Enter a Infix Expression: ";
    string s;
    cin >> s;
    string s2 = Infix_to_Prefix(s);
    cout <<endl<<"PreFix of given Infix Expression is:  "<< s2<<endl<<endl;
    cout<<"Calculation of Evaluated PreFix  :=  "<< Evaluate_prefix(s2);
    return 0;
}