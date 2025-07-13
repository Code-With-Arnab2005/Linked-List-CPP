#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    //constructor
    Node(int dt){
        val = dt;
        next = nullptr;
    }
};

Node* createLL(vector<int> &v){
    Node* head = new Node(v[0]);
    Node* mover = head;
    for(int i=1; i<v.size(); i++){
        Node* temp = new Node(v[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node* InsretAtFirst(Node* head, int n){
    if(head==NULL) return head;
    Node* temp = new Node(n);
    temp->next = head;
    return temp;
}

Node* InsretAtLast(Node* head, int n){
    if(head==NULL) return head;
    Node* temp = head;
    while(temp->next!=nullptr) temp=temp->next;
    Node* newNode = new Node(n);
    temp->next = newNode;
    return head;
}

Node* InsertAtPos(Node* head, int n, int pos){
    if(head==NULL) return head;
    if(pos==1) return InsretAtFirst(head, n);
    Node* temp = head;
    while(temp->next!=nullptr && pos>2){
        temp=temp->next;
        pos--;
    }
    Node* newNode = new Node(n);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5};
    Node* head = createLL(v);

    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    //insert a node at first
    // head = InsretAtFirst(head, 6);
    // temp=head;
    // while(temp!=nullptr){
    //     cout<<temp->val<<" ";
    //     temp=temp->next;
    // }
    // cout<<endl;

    //insert a node at last
    // head = InsretAtLast(head, 7);
    // temp=head;
    // while(temp!=nullptr){
    //     cout<<temp->val<<" ";
    //     temp=temp->next;
    // }
    // cout<<endl;
    
    //insert at any pos
    head = InsertAtPos(head, 10, 10);
    temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;


    return 0;
}