# include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int li = i, left = 2*i + 1, right = 2*i + 2;
    if(left < n && arr[left] > arr[li]){
        li = left;
    }
    if(right < n && arr[right] > arr[li]){
        li = right;
    } 
    if(li!=i){
        swap(arr[li], arr[i]);
        heapify(arr, n, li);
    }
}

void make_heap(vector<int> &arr, int n){
    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void delete_max(vector<int> &arr, int n){
    swap(arr[0], arr[n-1]);
    heapify(arr,n-1, 0);
}

void heapsort(vector<int> &arr){
    int n = arr.size();
    make_heap(arr,n);
    for (int i = n; i > 1; i--)
    {
        delete_max(arr,i);
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

void print_array(vector<int> arr){
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
    heapsort(arr);
    print_array(arr);
}