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
    void clean();

   public:
    List();
    Node* firstNode;

    void insert(int _value);
    void remove(int _value);
    std::string to_string();

    bool is_empty();
    int size();

    // COPY
    List(List const& other);
    List& operator=(List const& other);

    //MOVE
    List(List&& other);
    List& operator=(List&& other);

    ~List();
};

#endif