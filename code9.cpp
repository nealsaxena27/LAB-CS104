# include <bits/stdc++.h>
using namespace std;

void selectionsort(vector<int> &arr){
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minid = i;
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[j]<arr[minid]){
                minid = j;
            }
        }
        swap(arr[i], arr[minid]);
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
    selectionsort(arr);
    print_array(arr);
}