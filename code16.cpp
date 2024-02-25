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

node* insertatbeginning(node *head, int x){
    node* newnode = new node(x);
    if(head==NULL) head = newnode;
    else{
        newnode->next = head;
        head = newnode;
    }
    return head;
}

node* deleteatbeginning(node* head){
    if(head==NULL) return NULL;
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
    node *head = NULL;
    while(true){
        cout<<"1. Insert at beginning"<<endl;
        cout<<"2. Delete at beginning"<<endl;
        cout<<"3. Exit"<<endl;
        int x; cin>>x;
        if(x==1){
            int newval; cin>>newval;
            head = insertatbeginning(head, newval);
        }
        else if(x==2){
            deleteatbeginning(head);
        }
        else{
            break;
        }
    }
}