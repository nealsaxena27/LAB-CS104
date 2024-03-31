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

int findmax(TreeNode * root, int &dia){
    if(root==NULL) return 0;
    int lh = findmax(root->left, dia);
    int rh = findmax(root->right, dia);
    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root){
	int dia = 0;
    findmax(root, dia);
    return dia;
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
    cout<<"Diameter of Tree = "<<diameterOfBinaryTree(root)<<endl;
}