/*Algorithm:
1) Declare a character stack S.
2) Now traverse the expression string exp.
    a) If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
    b) If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket 
	then fine else parenthesis are not balanced.
3) After complete traversal, if there is some starting bracket left in stack then “not balanced”*/

#include<bits/stdc++.h>
using namespace std;

// function to check if paranthesis are balanced
bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
           return false;

        switch (expr[i])
        {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            if (x=='{' || x=='[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.top();
            s.pop();
            if (x=='(' || x=='[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.top();
            s.pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}

// Driver program to test above function
int main()
{
    string expr = "{()}[]";

    if (areParanthesisBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}


----------------------------------------------------------------------------------------------------------------------------------------------------------

Given a string of balanced expression, find if it contains a redundant parenthesis or not.
 A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant else ‘No’.
 
 ((a+b))
(a+(b)/c)
(a+b*(c-d))
Output: 
Yes
Yes
No

Explanation:
1. ((a+b)) can reduced to (a+b), this Redundant
2. (a+(b)/c) can reduced to (a+b/c) because b is
surrounded by () which is redundant.
3. (a+b*(c-d)) doesn't have any redundant or multiple
brackets.

We iterate through the given expression and for each character in the expression, if the character is a open parenthesis ‘(‘ or 
any of the operators or operands, we push it to the stack. If the character is close parenthesis ‘)’, then pop characters from the stack till
 matching open parenthesis ‘(‘ is found.
Now for redundancy two condition will arise while popping-

1. If immediate pop hits a open parenthesis ‘(‘, then we have found a duplicate parenthesis. For example, (((a+b))+c) has duplicate brackets around a+b.
 When we reach second “)” after a+b, we have “((” in the stack. Since the top of stack is a opening bracket, we conclude that there are duplicate brackets.
2. If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) then it indicates the presence of unwanted brackets surrounded by expression.
 For instance, (a)+b contain unwanted () around a thus it is redundant.
 
 bool checkRedundancy(string& str) 
{ 
    // create a stack of characters 
    stack<char> st; 
  
    // Iterate through the given expression 
    for (auto& ch : str) { 
  
        // if current character is close parenthesis ')' 
        if (ch == ')') { 
            char top = st.top(); 
            st.pop(); 
  
            // If immediate pop have open parenthesis '(' 
            // duplicate brackets found 
            bool flag = true; 
  
            while (top != '(') { 
  
                // Check for operators in expression 
                if (top == '+' || top == '-' ||  
                    top == '*' || top == '/') 
                    flag = false; 
  
                // Fetch top element of stack 
                top = st.top(); 
                st.pop(); 
            } 
  
            // If operators not found 
            if (flag == true) 
                return true; 
        } 
  
        else
            st.push(ch); // push open parenthesis '(', 
                  // operators and operands to stack 
    } 
    return false; 
} 
