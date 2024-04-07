# include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> hshmap;
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() < nums2[i]){
            st.pop();
        }
        if(st.empty()) hshmap[nums2[i]] = -1;
        else hshmap[nums2[i]] = st.top();
        st.push(nums2[i]);
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        if(hshmap.find(nums1[i])!=hshmap.end()) ans.push_back(hshmap[nums1[i]]);
        else ans.push_back(-1);
    }
    return ans;
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
    vector<int> arr1, arr2;
    int n1, n2;
    cin>>n1>>n2;
    input_array(arr1, n1);
    input_array(arr2, n2);
    vector<int> ans = nextGreaterElement(arr1, arr2);
    print_array(ans);
}