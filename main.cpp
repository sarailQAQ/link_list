#include <iostream>
#include <ctime>
#include "link_list/link_list.h"
using namespace std;

// maintain a ordered list
void task1() {
    LinkList<int> L;
    for (int i = 0; i < 10; ++i) L.Insert(rand() % 100);
    L.PrintAll();
    int a = rand() % 100;
    cout << "insert:" << a << endl;
    L.Insert(a);
    L.PrintAll();
}

// delete the minimum element of the list
// o(n)
void task2() {
    LinkList<int> L;
    for (int i = 0; i < 10; ++i) L.Insert(rand() % 100);
    L.PrintAll();
    L.DeleteMin();
    L.PrintAll();
}

// reverse the ordered list
// o(n)
void task3() {
    LinkList<int> L;
    for (int i = 0; i < 10; ++i) L.Insert(rand() % 100);
    L.PrintAll();
    L.Reverse();
    L.PrintAll();
}

int main() {

    srand(time(0));
    task1();
    task2();
    task3();
    return 0;
}
