#include "List.h"
#include <iostream>
using namespace std;

/*

    -- LIST --

*/

// CONSTRUCTOR
List::List() {
    firstNode = NULL;
}

void List::insert(int _value) {
    insert(firstNode, _value);
}

void List::insert(Node*& node, int _value) {
    if (node == NULL) {  // if no Nodes exist
        node = new Node(_value);
    } else if (node->value >= _value) {
        Node* nextNode = node->next;
        int tmpVal = node->value;
        Node* temp = new Node(tmpVal);
        node->value = _value;
        node->next = temp;
        temp->next = nextNode;
    } else {
        if (node->next == NULL) {
            node->next = new Node(_value);
        } else {
            insert(node->next, _value);
        }
    }
}

void List::remove(int _value) {
    Node* currentNode = firstNode;
    Node* lastNode = firstNode;
    while (currentNode != NULL) {
        if (currentNode->value == _value) {
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

// COPY CONSTRUCTOR
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

// ASSIGNMENT OPERATOR
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

// MOVE CONSTRUCTOR
List::List(List&& other) {
    firstNode = other.firstNode;
    other.firstNode = NULL;
}

// MOVE ASSIGNMENT
List& List::operator=(List&& other) {
    firstNode = other.firstNode;
    other.firstNode = NULL;
    return *this;
}

// DRAW LIST
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

// IS_EMPTY
bool List::is_empty() {
    return (firstNode == NULL);
}

// SIZE
int List::size() {
    int tmp{};
    Node* currentNode = firstNode;
    while (currentNode != NULL) {
        tmp++;
        currentNode = currentNode->next;
    }
    return tmp;
}

// DELETE LIST
void List::clean() {
    while (firstNode != NULL) {
        remove(firstNode->value);
    }
}

// DESCTRUCTOR
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
// CONSTRUCTOR
List::Node::Node(int _value) {
    value = _value;
    next = NULL;
}
