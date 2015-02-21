#include <string>
using namespace std;

template <typename T>
class linked_list{
    
private:
    struct Node{
        T data;
        Node* next;
        Node* prev;
        Node(const T& data_item, Node* prev_val = NULL, Node* next_val = NULL) :
        data(data_item), prev(prev_val), next(next_val) {}
    };
    
    Node* head;
    Node*tail;
    int num_items;
    
public:
    linked_list () : head(NULL), tail(NULL), num_items(0) {}
    ~linked_list (){
        while (head != NULL) {
            Node* current = head;
            head = head->next;
            delete current;
        }
        tail = NULL;
        num_items = 0;
    }
    void add_node (const T& data){ //Adds to front
        head = new Node(data, NULL, head);
        if (head->next != NULL)
            head->next->prev = head;
        if (tail == NULL)
            tail = head;
        num_items++;
    }
    void delete_node (const T& data){
        Node* current_node = head;
        
        while (current_node != NULL){
            
            if (current_node->data == data){
                if (current_node->next == NULL)//the last element in the list
                    return pop_back();
                
                if (current_node == head) //if the node we are deleting is the head
                    head = current_node->next;
                
                Node* to_be_deleted = current_node;
                current_node->next->prev = current_node->prev;
                if (current_node->prev != NULL)
                    current_node->prev->next = current_node->next;
                
                current_node = current_node->next;
                delete to_be_deleted;
                num_items--;
            }
            else
                current_node = current_node->next;
        }
    }
    void pop_back() {
        if (tail == NULL)
            throw invalid_argument ("Attempt to call pop_back() on an empty list");
        Node* removed_node = tail;
        tail = tail->prev;
        delete removed_node;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;
        num_items--;
    }
    bool is_empty (){
        if (num_items == 0)
            return true;
        else
            return false;
    }
    
    void print_list (){
        Node* current_node = head -> next;
        while(current_node != tail){
            cout << current_node ->data << '\n';
            current_node = current_node->next;
        }
    }

};
