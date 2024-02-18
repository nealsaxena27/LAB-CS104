# include <bits/stdc++.h>
using namespace std;

void input_2d_array(int arr[][5], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter subject marks of student"<<(i+1)<<endl;
        for (int j = 0; j < 5; j++)
        {
            cin>>arr[i][j];
        }
    }
}

void total_each_student(int arr[][5], int n){
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += arr[i][j];
        }
        cout<<"Total - Student - "<<(i+1)<<" is "<<sum<<endl;
    }
}

void average_each_subject(int arr[][5], int n){
    for (int i = 0; i < 5; i++)
    {
        int avg = 0;
        for (int j = 0; j < n; j++)
        {
            avg += arr[j][i];
        }
        avg = avg / n; 
        cout<<"Average - Subject - "<<(i+1)<<" is "<<avg<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n][5];
    input_2d_array(arr, n);
    total_each_student(arr, n);
    average_each_subject(arr, n);
}
