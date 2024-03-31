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

void right(TreeNode * node, int level, vector<int> &ans){
    if(!node) return;
    if(ans.size()==level) ans.push_back(node->data);
    right(node->right, level + 1, ans);
    right(node->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    right(root, 0, ans);
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
    vector<int> RSV = rightSideView(root);
    for (int i = 0; i < RSV.size(); i++)
    {
        cout<<RSV[i]<<" ";
    }
    cout<<endl;
}