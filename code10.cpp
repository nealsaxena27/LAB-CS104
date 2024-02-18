# include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &arr){
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;        
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
    insertionsort(arr);
    print_array(arr);
}