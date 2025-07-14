#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int x){
        val = x;
        next = nullptr;
        prev = nullptr;
    }
};

Node* create(vector<int> &v){
    Node* head = new Node(v[0]);
    Node* temp = head;
    for(int i=1; i<v.size(); i++){
        Node* newNode = new Node(v[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp=newNode;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverseDLL(Node* head){
    if(head==nullptr) return head;
    if(head->next==nullptr){
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = head->next;
    while(curr!=nullptr){
        next=curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5};
    Node* head = create(v);
    print(head);

    //reverse a doubly linked list
    head = reverseDLL(head);
    print(head);

    return 0;
}