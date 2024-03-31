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

int lowestCommonAncestor(TreeNode *root, int x, int y)
{
	if(!root) return -1;
    if(root->data==x || root->data==y) return root->data;
    int left = lowestCommonAncestor(root->left, x, y); 
    int right = lowestCommonAncestor(root->right, x, y);
    if(left==-1){
        return right;
    } 
    else if(right==-1){
        return left;
    }
    else{
        return root->data;
    }
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
    int x, y;
    cout<<"Enter x and y to find their lowest common ancestor: ";
    cin>>x>>y;
    int ans = lowestCommonAncestor(root, x, y);
    if(ans==-1) cout<<"Atleast one of the nodes is not in given tree"<<endl;
    else cout<<"Lowest Common Ancestor of "<<x<<" and "<<y<<" is "<<ans<<endl;
}