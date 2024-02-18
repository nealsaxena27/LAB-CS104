# include <bits/stdc++.h>
using namespace std;

bool palindrome(string &s){
    int l = 0, r = s.length() - 1;
    while(l < r){
        if(s[l]!=s[r]) return false;
        l++; r--;
    }
    return true;
}

int main(){
    string x;
    cin>>x;
    if(palindrome(x)){
        cout<<"Yes, a palindrome\n";
    }
    else{
        cout<<"No, not a palindrome\n";
    }
}
