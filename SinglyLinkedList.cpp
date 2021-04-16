#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

/**************************************************
               Note from Professors:

- Do not change the methods already provided
- Implement the copy constructor, read, write, custom_upsort()
  and any helper methods you wish.

***************************************************/

/**
 * Create an empty linked list
 */
SinglyLinkedList::SinglyLinkedList() {
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

/**
 * Delete any remaining Nodes in the linked list
 */
SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

/**
 * Return the number of elements stored in the linked list
 */
size_t SinglyLinkedList::size() const {
    return _size;
}

/**
 * Get the Node at the given index of the linked list (a helper function)
 * @param index the index of the Node to return
 * @return (a pointer to) the Node at the given index.
 */
Node * SinglyLinkedList::get_node(const size_t index) const {
    Node * current_node = _head;
    for (size_t current_index = 0; current_index < index; current_index++) {
        current_node = current_node->next;
    }
    return current_node;
}

/**
 * Return the data stored at the given index
 * @param index the index of the data element
 * @return the data stored at the given index
 */
int SinglyLinkedList::get(const size_t index) const {
    return get_node(index)->data;
}

/**
 * Change the data stored at the given index to the provided data.
 * @param index the index of the data to change
 * @param data the new data
 */
void SinglyLinkedList::set(const size_t index, const int data) {
    get_node(index)->data = data;
}

/**
 * Add the given Node to the beginning of the linked list (a helper function)
 * @param baby The Node to add to the beginning of the linked list.
 */
void SinglyLinkedList::add_first(Node * baby) {
    baby->next = _head;
    _head = baby;
    if (_tail == nullptr)
        _tail = _head;
    _size++;
}

/**
 * Add the given Node to the linked list after the specified Node (a helper method).
 * @param previous_node The Node to precede the new Node in the linked list
 * @param baby The Node to add to the list.
 */
void SinglyLinkedList::add_after(Node * previous_node, Node * baby) {
    baby->next = previous_node->next;
    previous_node->next = baby;
    if (previous_node == _tail)
        _tail = baby;
    _size++;
}

/**
 * Add the given data to the linked list so that it appears at the given index.
 * This displaces the nodes after it to be later in the linked list.
 * @param index The index to place the given data.
 * @param data The data to place at the index.
 */
void SinglyLinkedList::add(const size_t index, const int data) {
    Node * baby = new Node;
    baby->next = nullptr;
    baby->data = data;

    if (index == 0) {
        add_first(baby);
        return;
    }

    add_after(get_node(index - 1), baby);
}

/**
 * Remove the first Node from the linked list (a helper function)
 */
void SinglyLinkedList::remove_first() {
    Node * saved = _head;
    _head = _head->next;

    if (_head == nullptr)
        _tail = nullptr;

    _size--;
    delete saved;
}

/**
 * Remove the Node appearing after previous_node in the linked list (a helper function)
 * @param previous_node the Node appearing before the one we want to remove.
 */
void SinglyLinkedList::remove_after(Node * previous_node) {
    Node * removed = previous_node->next;
    previous_node->next = removed->next;

    if (removed == _tail)
        _tail = previous_node;

    _size--;
    delete removed;
}

/**
 * Remove the element stored in the given index of the linked list
 * @param index the index of the element we wish to remove.
 */
void SinglyLinkedList::remove(const size_t index) {
    if (index == 0) {
        remove_first();
        return;
    }
    remove_after(get_node(index - 1));
}

/**
 * Delete all of the Nodes in the linked list
 */
void SinglyLinkedList::clear() {
    while (_head != nullptr) {
        remove_first();
    }
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList & other) {
    // TODO: Implement and remove this comment
    _size = other._size;
    _head = other._head;
    _tail = other._tail;
}

void SinglyLinkedList::read(std::istream &input) {

    size_t index = 0;
    int data = 0;
    while (input.peek() != '\n') {
        cin >> data;
        add(index, data);
        index++;
    }
    //_size = index;
}

void SinglyLinkedList::write(std::ostream &output) const {
    // TODO: Implement and remove this comment
    for (size_t index = 0; index < _size; index++) {
        cout << get(index) << ' ';
    }
    cout << '\n';
    //return output;
}

void SinglyLinkedList::custom_upsort() {
    // TODO: Implement and remove this comment
}
