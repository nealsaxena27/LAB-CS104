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

node* mergeTwoLists(node* first, node* second)
{
    node* dummynode = new node(-1);
    node* temp = dummynode;
    while(first!=NULL && second!=NULL){
        if(first->data < second->data){
            temp->next = first;
            first = first->next;
            temp = temp->next;
            temp->next = NULL; 
        }
        else{
            temp->next = second;
            second = second->next;
            temp = temp->next;
            temp->next = NULL;
        }
    }
    if(first) temp->next = first;
    if(second) temp->next = second;
    return dummynode->next;
}

void printlist(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    while(true){
        cout<<"1. Insert in list 1"<<endl;
        cout<<"2. Insert in list 2"<<endl;
        cout<<"3. Merge 2 lists"<<endl;
        cout<<"4. Exit"<<endl;
        int x; cin>>x;
        if(x==1){
            int newval; cin>>newval;
            head1 = insertatend(head1, newval);
        }
        else if(x==2){
            int newval; cin>>newval;
            head2 = insertatend(head2, newval);
        }
        else if(x==3){
            head3 = mergeTwoLists(head1, head2);
            printlist(head3);
        }
        else{
            break;
        }
    }
}