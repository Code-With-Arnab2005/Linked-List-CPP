#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    //constructor
    Node(int v){
        val = v;
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

Node* deleteHead(Node* head){
    if(head==nullptr) return head;
    Node* temp = head;
    if(temp->next==nullptr) return nullptr;
    temp->next->prev = nullptr;
    head = head->next;
    temp->next = nullptr;
    free(temp);
    delete(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr) return head;
    if(head->next==nullptr){
        free(head);
        delete(head);
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next != nullptr) temp=temp->next;
    temp->next->prev = nullptr;
    free(temp->next);
    delete(temp->next);
    temp->next = nullptr;
    return head;
}

Node* deleteAtPos(Node* head, int pos){
    if(head==nullptr) return head;
    if(pos==1) return deleteHead(head);
    Node* temp = head;
    while(temp->next!=nullptr && pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==nullptr) return deleteTail(head);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next=nullptr;
    temp->prev=nullptr;
    delete(temp);
    return head;
}

Node* insertAtFirst(Node* head, int val){
    if(head==nullptr) return head;
    Node* temp = new Node(val);
    temp->next = head;
    head->prev = temp;
    return temp;
}

Node* insertAtLast(Node* head, int val){
    if(head==nullptr) return head;
    Node* temp = head;
    while(temp->next!=nullptr) temp=temp->next;
    Node* newNode = new Node(val);
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* insertAtPos(Node* head, int pos, int val){
    if(head==nullptr) return head;
    if(pos==1){
        return insertAtFirst(head, val);
    }
    Node* temp = head;
    while(temp->next!=nullptr && pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==nullptr){
        return insertAtLast(head, val);
    }
    Node* newNode = new Node(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
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

int length(Node* head){
    Node* temp = head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5};
    Node* head = create(v);
    print(head);
    cout<<"length: "<<length(head)<<endl;

    //delete the head of the doubly LL
    // head = deleteHead(head);
    // print(head);

    //delete the tail of the doubly LL
    // head = deleteTail(head);
    // print(head);
    // cout<<length(head)<<endl;
    
    //delete at any position of the doubly LL
    // head = deleteAtPos(head, 4);
    // print(head);
    // cout<<length(head)<<endl;
    
    //insert at first position of the doubly LL
    // head = insertAtFirst(head, 10);
    // print(head);
    // cout<<"length: "<<length(head)<<endl;
    
    //insert at first position of the doubly LL
    // head = insertAtLast(head, 10);
    // print(head);
    // cout<<"length: "<<length(head)<<endl;
    
    //insert at any position of the doubly LL
    // head = insertAtPos(head, 10, 11);
    // print(head);
    // cout<<"length: "<<length(head)<<endl;

    return 0;
}