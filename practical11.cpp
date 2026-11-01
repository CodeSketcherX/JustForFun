
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;

int priority(string op)
{
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

void showStack(stack<string> s)
{
    cout << "Stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void showValues(stack<double> s)
{
    cout << "Stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

string convert(string infix)
{
    stack<string> s;
    string postfix = "";
    string token;

    for (int i = 0; i < infix.length(); )
    {
        if (infix[i] == ' ')
        {
            i++;
            continue;
        }

        if (isalnum(infix[i]) || infix[i] == '.')
        {
            token = "";
            while (i < infix.length() &&
                  (isalnum(infix[i]) || infix[i] == '.'))
                token += infix[i++];

            postfix += token + " ";
        }
        else
        {
            token = infix[i++];

            if (token == "(")
                s.push(token);
            else if (token == ")")
            {
                while (!s.empty() && s.top() != "(")
                {
                    postfix += s.top() + " ";
                    s.pop();
                }
                if (!s.empty()) s.pop();
            }
            else
            {
                while (!s.empty() && s.top() != "(" &&
                       priority(s.top()) >= priority(token))
                {
                    postfix += s.top() + " ";
                    s.pop();
                }
                s.push(token);
            }
        }

        showStack(s);
    }

    while (!s.empty())
    {
        postfix += s.top() + " ";
        s.pop();
        showStack(s);
    }

    return postfix;
}

double evaluate(string postfix, map<string, double> values)
{
    stack<double> s;
    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        if (values.count(token))
            s.push(values[token]);
        else if (token != "+" && token != "-" &&
                 token != "*" && token != "/")
            s.push(stod(token));
        else
        {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();

            if (token == "+") s.push(a + b);
            if (token == "-") s.push(a - b);
            if (token == "*") s.push(a * b);
            if (token == "/") s.push(a / b);
        }

        showValues(s);
    }

    return s.top();
}

int main()
{
    string infix, postfix;
    map<string, double> values;

    cout << "Enter fee formula: ";
    getline(cin, infix);

    cout << "\n--- Infix to Postfix Conversion ---\n";
    postfix = convert(infix);

    cout << "\nPostfix: " << postfix << endl;

    cout << "\nEnter Tuition: ";
    cin >> values["Tuition"];

    cout << "Enter Hostel: ";
    cin >> values["Hostel"];

    cout << "Enter ExamFee: ";
    cin >> values["ExamFee"];

    cout << "Enter Scholarship: ";
    cin >> values["Scholarship"];

    cout << "\n--- Postfix Evaluation ---\n";
    double total = evaluate(postfix, values);

    cout << fixed << setprecision(2);
    cout << "\nFinal Payable Fees = Rs. " << total << endl;

    return 0;
}
