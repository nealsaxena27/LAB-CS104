# include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    // pivot - always first element
    int i = low, j = high, pivot = arr[low];
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quicksort(arr,low, pi-1);
        quicksort(arr,pi+1,high);
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
    quicksort(arr, 0, n-1);
    print_array(arr);
}