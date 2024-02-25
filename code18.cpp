# include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

node* insertatkthposition(node *head, int k , int x){
    node* newnode = new node(x);
    if(k==1){
        newnode->next = head;
        head = newnode;
    }
    else{
        if(head==NULL){
            head = newnode;
            return head;
        }
        node* temp = head;
        int cnt = 1;
        while(temp->next!=NULL && cnt!=k){
            temp = temp->next;
            cnt++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

node* deleteatkthposition(node* head, int k){
    if(head==NULL || head->next==NULL) return NULL;
    if(k==1){
        node* delnode = head;
        head = head->next;
        delete delnode;
    }
    else{
        node* temp = head;
        int cnt = 1;
        while(temp->next!=NULL && cnt!=(k-1)){
            temp = temp->next;
            cnt++;
        }
        node* delnode = temp->next;
        temp->next = temp->next->next;
        delete delnode;
    }
    return head;
}

int main(){
    node *head = NULL;
    while(true){
        cout<<"1. Insert at kth position"<<endl;
        cout<<"2. Delete at kth position"<<endl;
        cout<<"3. Exit"<<endl;
        int x; cin>>x;
        if(x==1){
            int newval, k; cin>>newval>>k;
            head = insertatkthposition(head, k, newval);
        }
        else if(x==2){
            int k; cin>>k;
            deleteatkthposition(head, k);
        }
        else{
            break;
        }
    }
}