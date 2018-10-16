#include "List.h"
#include <iostream>
using namespace std;

/*

    -- LIST --

*/

// Constructor
List::List() {
    firstNode = NULL;
}

// Public insert function
void List::insert(int _value) {
    insert(firstNode, _value);  // call recursive, internal, insert function
}

// Private insert function
void List::insert(Node*& node, int _value) {
    if (node == NULL) {  // if no Nodes exist
        node = new Node(_value);
    } else if (node->value >= _value) {  // insert a new node
        Node* nextNode = node->next;
        int tmpVal = node->value;
        Node* temp = new Node(tmpVal);
        node->value = _value;
        node->next = temp;
        temp->next = nextNode;
    } else {
        if (node->next == NULL) {  // reached the end of the list, append a node
            node->next = new Node(_value);
        } else {  // continue searching from the next node in the list
            insert(node->next, _value);
        }
    }
}

// Remove
void List::remove(int _value) {
    Node* currentNode = firstNode;
    Node* lastNode = firstNode;
    while (currentNode != NULL) {            // while we haven't reached the end of the list, iterate over nodes.
        if (currentNode->value == _value) {  // check if we've found the node to delete
            if (currentNode == firstNode) {
                Node* tmp = currentNode->next;
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
    firstNode = NULL;
    Node* tmp = other.firstNode;
    Node* cursor;
    if (tmp != NULL) {
        firstNode = new Node(tmp->value);
        cursor = firstNode;
        tmp = tmp->next;
        while (tmp != NULL) {
            cursor->next = new Node(tmp->value);
            tmp = tmp->next;
            cursor = cursor->next;
        }
    }
}

// Deep copy "=" assignment
List& List::operator=(List const& other) {
    clean();  // Remove any old data first.
    Node* tmp = other.firstNode;
    Node* cursor;
    if (tmp != NULL) {
        firstNode = new Node(tmp->value);
        cursor = firstNode;
        tmp = tmp->next;
        while (tmp != NULL) {
            cursor->next = new Node(tmp->value);
            tmp = tmp->next;
            cursor = cursor->next;
        }
    }
    return *this;
}

// Quick move constructor
List::List(List&& other) {
    firstNode = other.firstNode;
    other.firstNode = NULL;
}

// Quick move "=" assignment
List& List::operator=(List&& other) {
    firstNode = other.firstNode;
    other.firstNode = NULL;
    return *this;
}

// to_string
string List::to_string() {
    Node* currentNode = firstNode;
    string str{"{ "};
    while (currentNode != NULL) {
        str += std::to_string(currentNode->value) + " ";
        currentNode = currentNode->next;
    }
    str += "}";
    return str;
}

// is_empty
bool List::is_empty() {
    return (firstNode == NULL);
}

// size
int List::size() {
    int tmp{};
    Node* currentNode = firstNode;
    while (currentNode != NULL) {
        tmp++;
        currentNode = currentNode->next;
    }
    return tmp;
}

// clean (deletes all the elements in the list)
void List::clean() {
    while (firstNode != NULL) {
        remove(firstNode->value);
    }
}

// destructor
List::~List() {
    Node* currentNode = firstNode;
    while (currentNode != NULL) {
        Node* temp = currentNode->next;
        delete currentNode;
        currentNode = temp;
    }
}

/* 

    -- NODE --

*/
// constructor
List::Node::Node(int _value) {
    value = _value;
    next = NULL;
}
