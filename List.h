#ifndef _LIST_H_
#define _LIST_H_

#include <string>



class List {
    private:
        class Node {
            public:
                Node(int _value);
                int value;
                Node* next;

            private:
        };
        void insert(Node*& node, int _value);
        
    public:
        List();
        Node* firstNode;

        void insert(int _value);
        void remove(int _value);
        std::string to_string();

        bool is_empty();
        int size();

        List(List const& other);
        List& operator=(List const& other);

        ~List();
};

#endif