# include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int x){
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

node* deleteatkthposition(node* head, int k){
    int cnt = 0;
    node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }
    if(temp->prev == NULL && temp->next==NULL){
        delete temp;
        return NULL;
    }
    else if(temp->prev == NULL){
        temp->next->prev = NULL;
        head = temp->next;
        delete temp;
        return head;
    }
    else if(temp->next == NULL){
        temp->prev->next = NULL;
        delete temp;
        return head;
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        return head;
    }
}

node* insertatkthposition(node* head, int k, int val){
    node* newnode = new node(val);
    if(k==1){
        newnode->next = head;
        if(!head){
            head->prev = newnode;
        }
        return newnode;
    }
    node* temp = head;
    int cnt = 1;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    if(newnode->next!=NULL){
        newnode->next->prev = newnode;
    }
    return head;
}

int searchelement(node* head, int x){
    int cnt = 1;
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==x) return cnt;
        temp = temp->next;
        cnt++;
    }
    return -1;
}

void printlist(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;
}

int main(){
    node *head = NULL;
    while(true){
        cout<<"1. Insert at kth position"<<endl;
        cout<<"2. Delete at kth position"<<endl;
        cout<<"3. Search element"<<endl;
        cout<<"4. Print List"<<endl;
        cout<<"5. Exit"<<endl;
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
            int x; cin>>x;
            int ans = searchelement(head, x);
            if(ans==-1) cout<<"Not Found"<<endl;
            else cout<<"Found at "<<ans<<endl;
        }
        else if(x==4){
            printlist(head);
        }
        else{
            break;
        }
    }
}