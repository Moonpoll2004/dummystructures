#include <iostream>
#include <cstdlib>
#include <list>

struct Node{
    int data;
    Node * link = nullptr;

    Node(int n){
        data = n;
    }
};

struct LinkedList{
    Node* last_node = nullptr;
    Node* head_node;
    size_t count = 0;

    LinkedList(Node * h){
        head_node = h;
        ++count;
    }

    void link(Node * n){
        if(last_node == nullptr){
            head_node->link = n;
            last_node = n;
        } else {
            last_node->link = n;
            last_node = n;
        }
        
    }

    Node * begin(){
        return head_node;
    }

    Node* end(){
        return last_node;
    }

    bool isEmpty()
    {
        return last_node == nullptr;
    }

    void add(const int d){
        Node*n = new Node(d);
        link(n);
        ++count;
    }

    int operator[](signed int n){
        Node*temp = head_node;
        for(int i=0;i<n;++i){
            temp = temp->link;
        }
        return temp->data;
    }
};
int main ()
{
    Node *head = new Node(0);
    LinkedList ls = LinkedList(head);
    //adding nodes
    ls.add(2);
    ls.add(3);
    ls.add(4);
    ls.add(5);
    ls.add(6);
    ls.add(7);
    ls.add(8);

    //count or size
    std::cout<<"size is "<<ls.count<<'\n';

    //is list Empty
    std::cout<<"isEmpty "<<ls.isEmpty()<<'\n';

    //cout
    std::cout<<"secodn "<<ls[1]<<'\n';
    std::cout<<"last "<<ls[2]<<'\n';
    std::cout<<"frist "<<ls[0]<<'\n';
    return 0;
}