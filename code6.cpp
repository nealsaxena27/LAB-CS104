# include <bits/stdc++.h>
using namespace std;

# define maxsize 100000

void input_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}

int linear_search(int arr[], int n, int val){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[maxsize];
    input_array(arr, n);
    int ans = linear_search(arr, n, 7);
    if(ans==-1){
        cout<<"Not Found\n";
    }
    else{
        cout<<"Found at index "<<ans<<endl;
    }
}