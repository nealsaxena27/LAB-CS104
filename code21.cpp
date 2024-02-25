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

node* findIntersection(node *firstHead, node *secondHead)
{
    if(firstHead==NULL || secondHead==NULL){
        return NULL;
    }
    node *t1 = firstHead, *t2 = secondHead;
    while(t1!=t2){
        t1 = t1==NULL ? secondHead : t1->next;
        t2 = t2==NULL ? firstHead : t2->next;
    }
    return t1;
}

int main(){
    node *head1 = NULL, *head2 = NULL;
    while(true){
        cout<<"1. Insert in list 1"<<endl;
        cout<<"2. Insert in list 2"<<endl;
        cout<<"3. Find Merge Point of list 1 and 2"<<endl;
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
            node* ans = findIntersection(head1, head2);
            if(ans==NULL) cout<<"No merge point"<<endl;
            else cout<<"Merge point is "<<ans->data<<endl;
        }
        else{
            break;
        }
    }
}