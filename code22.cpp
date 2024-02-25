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

bool detectCycle(node *head)
{
	node* slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

void *removeCycle(node *head)
{
    node * slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
}

int main(){
    node *head;
    while(true){
        cout<<"1. Insert in list"<<endl;
        cout<<"2. Detect Cycle"<<endl;
        cout<<"3. Remove Cycle"<<endl;
        cout<<"4. Exit"<<endl;
        int x; cin>>x;
        if(x==1){
            int newval; cin>>newval;
            head = insertatend(head, newval);
        }
        else if(x==2){
            if(detectCycle(head)) cout<<"Cycle detected"<<endl;
            else cout<<"No cycle detected"<<endl;
        }
        else if(x==3){
            removeCycle(head);
        }
        else{
            break;
        }
    }
}