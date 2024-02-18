# include <bits/stdc++.h>
using namespace std;

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

int floor(vector<int> &arr, int x){
    int n = arr.size(), low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] <= x){
            ans = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int ceil(vector<int> &arr, int x){
    int n = arr.size(), low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= x){
            ans = arr[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int findMin(vector<int> &arr){
	int n = arr.size();
	int ans = INT_MAX, l = 0, r = n - 1;
	while(l <= r){
		int m = l + (r - l)/2;
        if(arr[l]==arr[m] && arr[m]==arr[r]){
            ans = min(ans, arr[m]);
            l++; r--; continue;
        }
		if(arr[l] <= arr[m]){
			ans = min(ans, arr[l]);
			l = m + 1;
		}
		else{
			ans = min(ans, arr[m]);
			r = m - 1;
		}
	}
	return ans;
}

int findPeakElement(vector<int> &a) {
    int n = a.size();
    if(n==1){
        return 0;
    }
    if(a[0] > a[1]){
        return 0;
    }
    if(a[n-1] > a[n-2]){
        return n - 1;
    }
    int l = 1, r = n - 2;
    while(l <= r){
        int m = l + (r - l)/2;
        if(a[m] > a[m-1] && a[m] > a[m+1]){
            return m;
        }
        else if(a[m] > a[m-1]){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr;
    int n, x;
    cin>>n>>x;
    input_array(arr, n);
    print_array(arr);
    cout<<floor(arr, x)<<endl;
    cout<<ceil(arr, x)<<endl;
    cout<<findPeakElement(arr)<<endl;
    cout<<findMin(arr)<<endl;
}