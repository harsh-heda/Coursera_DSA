#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class node{
public:
    char data;
    struct node* next;
    struct node* prev;
    int index;
};
void append(node ** head_ref,char n){
    node* temp=new node();
    temp->data=n;
    temp->next=NULL;
    node *last=*head_ref;
    if(*head_ref==NULL){
       *head_ref=temp;
       return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=temp;
    return;
}
void addfront(node** head_ref,char n,int val){
    node* temp=new node();
    temp->data=n;
    temp->index=val;
    temp->next=*head_ref;
    *head_ref=temp;
}
void insertafter(node *prev_node,int n){
    if(prev_node==NULL){
        cout << "Not possible";
        return;
    }
    node *temp=new node();
    temp->data=n;
    temp->next=prev_node->next;
    prev_node->next=temp;
}
void print(node *node){
    while(node!=NULL){
        cout <<node->data << " ";
        node=node->next;
    }
}
void popfront(node** head_ref){
    node* temp=*head_ref;
    *head_ref=temp->next;
}
int main()
{
    string s;
    cin >>s;
    node* head=NULL;
    for(int i=0;i<(int)s.length();i++){
        if((s[i]=='}' || s[i]==']' || s[i]==')') && head==NULL){
            cout <<i+1;
            return 0;
        }
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            addfront(&head,s[i],i+1);
        }
        if(s[i]=='}' && i>0){
            if(head->data=='{')
                popfront(&head);
            else{
                cout <<i+1;
                return 0;
            }
        }
        else if(s[i]==']' && i>0){
            if(head->data=='[')
                popfront(&head);
            else{
                cout <<i+1;
                return 0;
            }
        }
        else if(s[i]==')' && i>0){
            if(head->data=='(')
                popfront(&head);
            else{
                cout <<i+1;
                return 0;
            }
        }

    }
    if(head!=NULL)
        cout << head->index;
    else
        cout << "Success";
    return 0;

}
