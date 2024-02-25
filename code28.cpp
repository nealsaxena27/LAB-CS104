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

node* reverseLinkedList(node *head)
{
    node* temp = head, *prev = NULL, *front;
    while(temp!=NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool isPalindrome(node *head)
{
    if(head==NULL || head->next==NULL) return true;
    node* slow = head, *fast= head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* newhead = reverseLinkedList(slow->next);
    node *first = head, *second = newhead;
    while(second!=NULL){
        if(first->data!=second->data){
            reverseLinkedList(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newhead);
    return true;
}

node* findNthnode(node* head, int n)
{
    node* fast = head, *slow = head;
    while(n--) fast = fast->next;
    if(fast==NULL) return head->next;
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(){
    node *head;
    while(true){
        cout<<"1. Insert in list"<<endl;
        cout<<"2. Find Nth Node from end"<<endl;
        cout<<"3. Exit"<<endl;
        int x; cin>>x;
        if(x==1){
            int newval; cin>>newval;
            head = insertatend(head, newval);
        }
        else if(x==2){
            int n; cin>>n;
            node* nthnode = findNthnode(head, n);
            if(nthnode) cout<<"Nth Node from end -> "<<nthnode->data<<endl;
        }
        else{
            break;
        }
    }
}