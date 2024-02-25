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
        node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
    else{
        if(head==NULL){
            head = newnode;
            newnode->next = head;
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
    if(head==NULL || head->next==head) return NULL;
    if(k==1){
        node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        node* delnode = head;
        head = head->next;
        temp->next = head;
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

void printlist(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        if(temp==head) break;
    }
    cout<<endl;
}

int main(){
    node *head = NULL;
    while(true){
        cout<<"1. Insert at kth position"<<endl;
        cout<<"2. Delete at kth position"<<endl;
        cout<<"3. Print Circular Linked List"<<endl;
        cout<<"4. Exit"<<endl;
        int x; cin>>x;
        if(x==1){
            int newval, k; cin>>newval>>k;
            head = insertatkthposition(head, k, newval);
        }
        else if(x==2){
            int k; cin>>k;
            deleteatkthposition(head, k);
        }
        else if(x==3){
            printlist(head);
        }
        else{
            break;
        }
    }
}