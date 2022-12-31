/*SOLUTION:
 the given vector of character is postfix expression, to solve it I have used stack;while traversing the tokens vector
 if the found char is a operator like *,/,-,+ then the first 2 top elements are popped and and resultant operation is 
 performed and pushed back in stack but if it is number we need to type cast the character and then push it into the 
 stack. and result is left in the top of stack which is returned.
*/

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            int t1, t2;
            if (tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/")
            {
                if (tokens[i] == "*")
                {
                    t1 = s.top();
                    s.pop();
                    t2 = s.top();
                    s.pop();
                    s.push(t1 * t2);
                }
                if (tokens[i] == "-")
                {
                    t1 = s.top();
                    s.pop();
                    t2 = s.top();
                    s.pop();
                    s.push(t2 - t1);
                }
                if (tokens[i] == "+")
                {
                    t1 = s.top();
                    s.pop();
                    t2 = s.top();
                    s.pop();

                    s.push(t1 + t2);
                }
                if (tokens[i] == "/")
                {
                    t1 = s.top();
                    s.pop();
                    t2 = s.top();
                    s.pop();
                    cout << t2 / t1;
                    s.push(t2 / t1);
                }
            }
            else
            {
                int num;
                num = stoi(tokens[i]);
                s.push(num);
            }
        }
        return s.top();
    }
};