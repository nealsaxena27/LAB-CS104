# include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val){
        data = val;
        left = NULL; right = NULL;
    }
};

vector<int> TopView(TreeNode *root)
{
    vector<int> ans;
    map<int, int> topview;
    queue<pair<TreeNode *, int>> q;
    if(root) q.push({root, 0});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        TreeNode * node = p.first;
        int v = p.second;
        if(topview.find(v)==topview.end()){
            topview[v] = node->data;
        }
        if(node->left) q.push({node->left, v - 1});
        if(node->right) q.push({node->right, v + 1});
    }
    for (auto i : topview)
    {
        ans.push_back(i.second);
    }
    return ans;
}

TreeNode* createBinaryTree(TreeNode *root){
    TreeNode * curr;
    cout<<"Enter root node: ";
    int x; cin>>x;
    if(x==-1) return root;
    root = new TreeNode(x);
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        curr = q.front(); q.pop();
        cout<<"Enter data in left of "<<curr->data<<" : ";
        cin>>x;
        if(x!=-1){
            curr->left = new TreeNode(x);
            q.push(curr->left);
        }
        cout<<"Enter data in right of "<<curr->data<<" : ";
        cin>>x;
        if(x!=-1){
            curr->right = new TreeNode(x);
            q.push(curr->right);
        }
    }
    return root;
}

int main(){
    TreeNode *root = NULL;
    root = createBinaryTree(root);
    vector<int> TV = TopView(root);
    for (int i = 0; i < TV.size(); i++)
    {
        cout<<TV[i]<<" ";
    }
    cout<<endl;
}