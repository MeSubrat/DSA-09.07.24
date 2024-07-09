#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
Node* arr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"x";
}

Node* findNthNode(Node* head, int n)
{
    Node* temp=head;
    int cnt=1;
    while(temp!=NULL)
    {
        if(cnt==n)return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
}

Node* RotateLL(Node* head, int k)
{
    Node* tail=head;
    int len=1;
    while(tail->next!=NULL)
    {
        len++;
        tail=tail->next;
    }
    if(k%len==0)return head;
    k=k%len;
    tail->next=head;
    Node* newLast=findNthNode(head,len-k);
    head=newLast->next;
    newLast->next=NULL;
    return head;
}

int main()
{
    vector<int> arr={1,2,3,4,5};
    Node* head=arr2LL(arr);
    head=RotateLL(head,2);
    print(head);
}