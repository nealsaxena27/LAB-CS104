# include <bits/stdc++.h>
using namespace std;

# define maxsize 100000

void input_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}

int binary_search(int arr[], int n, int val){
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l)/2;
        if(arr[m]==val){
            return m;
        }
        else if(arr[m] < val){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[maxsize];
    input_array(arr, n);
    int ans = binary_search(arr, n, 7);
    if(ans==-1){
        cout<<"Not Found\n";
    }
    else{
        cout<<"Found at index "<<ans<<endl;
    }
}