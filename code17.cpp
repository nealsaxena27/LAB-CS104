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

node* insertatend(node *head, int x){
    node* newnode = new node(x);
    if(head==NULL) head = newnode;
    else{
        node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

node* deleteatend(node* head){
    if(head==NULL || head->next==NULL) return NULL;
    node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

int main(){
    node *head = NULL;
    while(true){
        cout<<"1. Insert at end"<<endl;
        cout<<"2. Delete at end"<<endl;
        cout<<"3. Exit"<<endl;
        int x; cin>>x;
        if(x==1){
            int newval; cin>>newval;
            head = insertatend(head, newval);
        }
        else if(x==2){
            deleteatend(head);
        }
        else{
            break;
        }
    }
}