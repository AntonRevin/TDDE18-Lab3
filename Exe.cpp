#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List l{};
    l.insert(1);
    l.insert(5);
    l.insert(2);
    l.remove(5);
    l.insert(50);
    List l2{l};
    l.insert(3);
    l2.insert(1);
    List l3{};
    l3 = l2;
    l2.insert(99);
    l3.insert(100);
    cout << l3.to_string() << endl;
    cout << l.to_string() << endl;
    l3.remove(1);
    cout << l3.to_string() << endl;
}