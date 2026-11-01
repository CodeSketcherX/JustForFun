
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string post = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c >= '0' && c <= '9')
            post += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                post += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && st.top() != '(' &&
                   priority(st.top()) >= priority(c))
            {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        post += st.top();
        st.pop();
    }

    return post;
}

int evaluate(string post)
{
    stack<int> st;

    for (int i = 0; i < post.length(); i++)
    {
        char c = post[i];

        if (c >= '0' && c <= '9')
            st.push(c - '0');
        else
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
        }
    }

    return st.top();
}

int main()
{
    string infix, postfix;

    cout << "Enter infix expression: ";
    cin >> infix;

    postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Result: " << evaluate(postfix) << endl;

    return 0;
}
