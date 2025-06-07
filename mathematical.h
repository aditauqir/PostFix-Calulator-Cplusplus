#pragma once //ensures each function is called once only
#include <vector>
#include <string> 
#include <stack>
#include <cctype>
#include <sstream>
#include <locale>
#include <cmath>
using namespace std;

int errorcheck(string x)
{
    for (char y:x)
    {
        if (isalpha(y))
        {
            return 5000;
        }
    }
    return 0;
}

bool doublecheck(string y)
{
    for (char cur:y)
    {
        if (cur == '.')
        {
            return true;
        }
    }
    return false;
}

bool intcheck(string y)
{
    for (char cur:y)
    {
        if (isalpha(cur))
        {
            return true;
        }
    }
    return false;
}

bool is_string_num(string& str) {
    int dot_count=0;
    bool result;
    for (char c : str) {
        if (c== '.')
        {   
            dot_count+=1;
            if (dot_count>1)
            {
                result = false;
            }
        }
        else if (isdigit(c)) {
            result = true; 
        }
        else
        {
            result = false;
        }
    }
    return result;
}

int checks(string c)
{
    if (c=="^") //R-L just push
    {
        return 4;
    }
    else if (c=="*" || c=="/") //L-R pop top and push
    {
        return 2;
    }
    else if (c=="+" || c=="-") //L-R
    {
        return 1;
    } else
    {
        return -1;
    }
}

double the_main_stuff(string& x)
{
    vector <string> items;
    string a;
    
    if (errorcheck(x)>0)
    {
        return 505;
    }

        for (char ch: x)
        {
            if (ch == ' ')
            {
                continue;
            }
            else if (ch == '+' || ch == '^' || ch == '*' || ch == '/' || ch == '-' || ch == '(' || ch == ')')
            {
                if (!a.empty())
                {
                    items.push_back(a);
                    a.clear();
                }
                items.push_back(string(1,ch));
            }
            else
            {
                a+=ch;
            }
        }
        
        if(!a.empty()) {items.push_back(a);}
        vector<string> postfix;
        stack <string> my_stack;
        for (string x: items)
        {   
            if (is_string_num(x))
            {
                postfix.push_back(x);
            }
            else if (x == "(" )
            {
                my_stack.push(x);
            }
            else if (x == ")")
            {
                while (!my_stack.empty() && my_stack.top() != "(")
                {
                    postfix.push_back(my_stack.top());
                    my_stack.pop();
                }
                if (!my_stack.empty()){my_stack.pop();}
            }
            else
            {
                while(!my_stack.empty() && checks(x)<=checks(my_stack.top()))
                {postfix.push_back(my_stack.top());
                my_stack.pop();
            }
                my_stack.push(x);
            }
        }
        while (!my_stack.empty())
        {
            postfix.push_back(my_stack.top());
            my_stack.pop();
        }
        cout<<"\nPOSTFIX: ";
        for (auto i: postfix)
        {cout << i;}

        cout<<"\n---------------------"<<endl;

        stack<double> eval;
        for (auto k:postfix)
        {
            if (is_string_num(k))
            {
                eval.push(stod(k));
            }
            else
            {
                int num_one= eval.top();
                eval.pop();
                int num_two= eval.top();
                eval.pop();
                if (k == "*")
                {
                    eval.push(num_one*num_two);
                }
                else if (k == "+")
                {
                    eval.push(num_one+num_two);
                }
                else if (k == "-")
                {
                    eval.push(num_two-num_one);
                }
                else if (k == "/")
                {
                    eval.push(num_two/num_one);
                }
                else if (k == "^")
                {
                    eval.push(pow(num_two,num_one));
                }
            }
        }
        return eval.top(); //end of logic
    } 