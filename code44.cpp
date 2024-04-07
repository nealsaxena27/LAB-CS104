# include <bits/stdc++.h>
using namespace std;

bool isOpening(char &c){
    return c=='[' || c=='{' || c=='(';
}

bool isClosing(char &c){
    return c==']' || c=='}' || c==')';
}

char getComplement(char &c){
    switch(c){
        case ']' : return '[';
        case '}' : return '{';
        case ')' : return '(';
    }
    return '\0';
}

bool isValidParenthesis(string &s){
    stack<char> stk;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if(isOpening(s[i])){
            stk.push(s[i]);
        }
        else if(isClosing(s[i])){
            if(stk.empty() || getComplement(s[i])!=stk.top()) return false;
            stk.pop();
        }
    }
    if(stk.empty()) return true;
    return false;
}

int main(){
    string inputstring;
    cin>>inputstring;
    if(isValidParenthesis(inputstring)){
        cout<<"Valid Parenthesis\n";
    }
    else{
        cout<<"Not Valid\n";
    }
}