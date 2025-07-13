#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    //constructor
    Node(int data1, Node* node1){
        data = data1;
        next = node1;
    }

    //constructor
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

int lenOfLL(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

void traversLL(Node* head){
    Node* p = head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    int arr[4] = {2, 3, 4, 5};
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<4; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover=mover->next;
    }
    traversLL(head);
    cout<<"Length of LL: "<<lenOfLL(head)<<endl;
    return 0;
}