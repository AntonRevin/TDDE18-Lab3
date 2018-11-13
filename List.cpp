#include "List.h"
#include <iostream>
using namespace std;

/*
    -- LIST --
*/

List::List()
    : firstNode{nullptr} {
}

// Public insert function
void List::insert(int _value) {
    insert(firstNode, _value);  // call recursive, internal, insert function
}

// Private insert function
void List::insert(Node*& node, int _value) {
    if (node == nullptr) {  // if no Nodes exist
        node = new Node(_value);
    } else if (node->value >= _value) {  // insert a new node
        Node* nextNode{node->next};
        int tmpVal = node->value;
        Node* temp{new Node(tmpVal)};
        node->value = _value;
        node->next = temp;
        temp->next = nextNode;
    } else {
        if (node->next == nullptr) {  // reached the end of the list, append a node
            node->next = new Node(_value);
        } else {  // continue searching from the next node in the list
            insert(node->next, _value);
        }
    }
}

// Remove
void List::remove(int _value) {
    Node* currentNode{firstNode};
    Node* lastNode{firstNode};
    while (currentNode != nullptr) {         // while we haven't reached the end of the list, iterate over nodes.
        if (currentNode->value == _value) {  // check if we've found the node to delete
            if (currentNode == firstNode) {
                Node* tmp{currentNode->next};
                delete firstNode;
                firstNode = tmp;
                return;
            } else {
                lastNode->next = currentNode->next;
                delete currentNode;
                return;
            }
        } else {
            lastNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

// Deep copy constructor
List::List(List const& other) {
    firstNode = nullptr;
    Node* tmp{other.firstNode};
    Node* cursor{};
    if (tmp != nullptr) {
        firstNode = new Node(tmp->value);
        cursor = firstNode;
        tmp = tmp->next;
        while (tmp != nullptr) {
            cursor->next = new Node(tmp->value);
            tmp = tmp->next;
            cursor = cursor->next;
        }
    }
}

// Deep copy "=" assignment
List& List::operator=(List const& other) {
    //clean();
    new (this) List{other};
    return *this;
}

// Quick move constructor
List::List(List&& other) {
    firstNode = other.firstNode;
    other.firstNode = nullptr;
}

List& List::operator=(List&& other) {
    clean();
    firstNode = other.firstNode;
    other.firstNode = nullptr;
    return *this;
}

// to_string
string List::to_string() {
    Node* currentNode{firstNode};
    string str{"{ "};
    while (currentNode != nullptr) {
        str += std::to_string(currentNode->value) + " ";
        currentNode = currentNode->next;
    }
    str += "}";
    return str;
}

// is_empty
bool List::is_empty() {
    return (firstNode == nullptr);
}

// size
int List::size() {
    int tmp{};
    Node* currentNode{firstNode};
    while (currentNode != nullptr) {
        tmp++;
        currentNode = currentNode->next;
    }
    return tmp;
}

// clean (deletes all the elements in the list)
void List::clean() {
    while (firstNode != nullptr) {
        remove(firstNode->value);
    }
}

// destructor
List::~List() {
    Node* currentNode{firstNode};
    while (currentNode != nullptr) {
        Node* temp{currentNode->next};
        delete currentNode;
        currentNode = temp;
    }
}

/* 
    -- NODE --
*/
// constructor
List::Node::Node(int _value)
    : value{_value}, next{nullptr} {
}
