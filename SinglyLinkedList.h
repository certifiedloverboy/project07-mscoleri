#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <iostream>

struct Node {
    int data;
    Node * next;
};

class SinglyLinkedList {
private:
    Node * _head;
    Node * _tail;
    size_t _size;
public:
    // lifecycle methods
    SinglyLinkedList();
    ~SinglyLinkedList();
    // methods from the List interface
    size_t size() const;
    int get(const size_t index) const;
    void set(const size_t index, const int data);
    void add(const size_t index, const int data);
    void remove(const size_t index);
    // new methods to implement
    SinglyLinkedList(const SinglyLinkedList & other);
    void read(std::istream & input);
    void write(std::ostream & output) const;
    void custom_upsort();
private:
    Node * get_node(const size_t index) const;
    void add_first(Node * baby);
    void add_after(Node * previous_node, Node * baby);
    void remove_first();
    void remove_after(Node * previous_node);
    void clear();
};

#endif // SINGLYLINKEDLIST_H
