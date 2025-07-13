#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data1){
        this->data = data1;
        this->next = nullptr;
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

Node* deleteHead(Node* head){
    if(head==nullptr) return head;
    Node* temp = head;
    head=head->next;
    free(temp);
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr) return head;
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    delete(temp->next);
    temp->next = nullptr;
    return head;
}

Node* deleteAtPos(Node* head, int pos){
    if(head==nullptr) return head;
    if(pos==1) return deleteHead(head);
    Node* temp = head;
    while(temp->next!=nullptr && pos>2){
        temp=temp->next;
        pos--;
    }
    if(pos>2 || temp->next==nullptr) return head;
    Node* p = temp->next;
    temp->next = temp->next->next;
    free(p);
    delete(p);
    return head;
}
int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5};
    Node* head = createLL(v);
    // cout<<"Previous List Head: "<<head->data<<endl;
    // head = deleteHead(head);
    // cout<<"After deleting First Node List Head: "<<head->data<<endl;

    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
    // head = deleteTail(head);
    // temp=head;
    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    // cout<<endl;
    
    
    head = deleteAtPos(head, 4);
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    

    return 0;
}