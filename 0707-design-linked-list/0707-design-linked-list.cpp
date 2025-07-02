class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int value) : val(value), next(nullptr) {}
    };

    Node* head;
    int size;


public:
    MyLinkedList() {
        head=nullptr;
        size=0;
        
    }
    
    int get(int index) {
        int ans=-1;
        if(index < 0 || index >= size){
            return ans;
        }
        Node* curr=head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr ? curr->val : -1;
    }
    
    void addAtHead(int val) {
        Node* curr=new Node(val);
        curr->next=head;
        head=curr;
        size++;
        
    }
    
    void addAtTail(int val) {
        Node* curr=new Node(val);
        if(head==nullptr){
            head=curr;
        }
        else{
            Node* temp=head;
            while(temp && temp->next){
                temp=temp->next;
            }
            temp->next = curr;
        }
        size++;
        
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node* curr=new Node(val);
        curr->next=temp->next;
        temp->next=curr;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        size--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */