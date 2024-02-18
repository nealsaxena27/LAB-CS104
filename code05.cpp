# include <bits/stdc++.h>
using namespace std;

# define maxsize 100000

void input_array(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}

void insert_at_end(int arr[], int &n, int data){
    if(n==maxsize){
        cout<<"Overflow"<<endl;
        return;
    }
    arr[n++] = data;
}

void delete_at_end(int arr[], int &n){
    if(n==0){
        cout<<"Underflow"<<endl;
        return;
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
    insert_at_end(arr, n, 10);
    delete_at_end(arr, n);
    print_array(arr, n);
}
