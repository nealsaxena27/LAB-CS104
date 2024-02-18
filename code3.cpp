# include <bits/stdc++.h>
using namespace std;

# define maxsize 100000

void input_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}

void insert_element(int arr[], int &n, int pos, int data){
    if(n==maxsize){
        cout<<"Overflow"<<endl;
        return;
    }
    for (int i = pos + 1; i <= n; i++)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = data;
    n++;
}

void delete_element(int arr[], int &n, int pos){
    if(n==0){
        cout<<"Underflow"<<endl;
        return;
    }
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

void print_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[maxsize];
    input_array(arr, n);
    insert_element(arr, n, 2, 10);
    delete_element(arr, n, 1);
    print_array(arr, n);
}