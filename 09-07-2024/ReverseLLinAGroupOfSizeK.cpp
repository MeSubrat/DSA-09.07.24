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

Node* reverse(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* findKthNode(Node* head, int k){
    k-=1;
    Node* temp=head;
    while(k>0 && temp!=NULL)
    {
        k--;
        temp=temp->next;
    }
    return temp;
}
Node* reverseKthGroup(Node* head, int k){
    Node* temp=head;
    Node* nextNode=NULL, *prevNode=NULL;
    while(temp!=NULL)
    {
        Node* kthNode=findKthNode(temp,k);
        if(kthNode==NULL){
            if(prevNode){
                prevNode->next=temp;
            }
            break;
        }
        nextNode=kthNode->next;
        kthNode->next=NULL;
        reverse(temp);
        if(temp==head)
        {
            head=kthNode;
        }
        else{
            prevNode->next=kthNode;
        }
        prevNode=temp;
        temp=nextNode;
    }
    return head;
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    Node* head=arr2LL(arr);
    head=reverseKthGroup(head,3);
    print(head);
}