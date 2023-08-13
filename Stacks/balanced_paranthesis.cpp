#include <iostream>
#include <stack>
#include <string>
using namespace std;
//!Check if the Brackets are Balanced
//!For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. 
//!Brackets are said to be balanced if the bracket which opens last, closes first
//!watch video for more clarity https://www.youtube.com/watch?v=QZOLb0xHB_Q
// (()()) => true
bool checkBalancedexp(string exp){
    int len = exp.length();
    stack<char> s;
    for(int i = 0;i<len;i++){
        if(exp[i]== '(' || exp[i] == '{' || exp[i] == '['){//if opening bracket then push 
            s.push(exp[i]);
        }
        //first character has to be opening bracket so if closing bracket(means stack is empty for first iteration) comes first then return false.
        else if(s.empty() == true){//if stack is empty or top of stack is not equal to current character then return false
            return false;
        }
        else if(exp[i] == ')'){
            if(s.top() == '('){
                s.pop();
            }
            else{
                return false;
            }
        }
        else if(exp[i] == '}'){
            if(s.top() == '{'){
                s.pop();
            }
            else{
                return false;
            }
        }
        else if(exp[i] == ']'){
            if(s.top() == '['){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    //if balanced then stack should be empty
    //if not empty then not balanced.
    return s.empty();
}
int main(){
    string exp;
    exp = "({}";
    cout<<checkBalancedexp(exp);
    return 0;
}