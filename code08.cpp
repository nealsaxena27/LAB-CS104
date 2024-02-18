# include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &arr){
    for (int i = arr.size()-1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {   
            bool flag = false;
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                flag = true;
            }
            if(!flag){
                break;
            }
        }
    }
}

void input_array(vector<int> &arr, int n){
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
}

void print_array(vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    input_array(arr, n);
    bubblesort(arr);
    print_array(arr);
}
