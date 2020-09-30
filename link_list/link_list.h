//
// Created by sarail on 2020/9/22.
//

#ifndef LINKLIST_LINK_LIST_H
#define LINKLIST_LINK_LIST_H
#include <cstdio>
#include <iostream>

// as a habit of Go,the private object is in lowercase letter
// and the public is in uppercase letter
template <typename T> class LinkList {
private:
    struct node{
        T data;
        node* next;
        node() : next(nullptr) {}
    }*head = nullptr;
    int size;

public:
    LinkList():head(nullptr), size(0) {}

    void Insert(const T& val) {
        // empty list
        size++;
        auto p = new node;
        p->data = val;
        if (head == nullptr) {
            head = p;
            return;
        }

        // find the position of val
        auto n = head;
        if (n->data > val) {
            p->next = n;
            head = p;
            return;
        }

        while (n != nullptr) {
            if (n->next == nullptr || n->next->data > val) break;
            n = n->next;
        }
        p->next = n->next;
        n->next = p;

        // magic bug
        // without this return,the void function in class will not return and continue to run
        return;
    }

    bool Delete(T val) {
        if (head == nullptr) return false;
        if (head->data == val) {
            head = head->next;
            size--;
            return true;
        }

        auto n = head;
        while (n->next != nullptr && n->next->data < val) n = n->next;
        if (n->next == nullptr || n->next->data != val) return false;
        auto p = n->next;
        n->next = p->next;
        delete p;
        size--;
    }

    T DeleteMin() {
        if (head == nullptr) {
            // I have not learned how to through a panic in c++ yet
            // maybe return NULL would cause an error
            printf("error:delete on empty link-list");
            return NULL;
        }

        // head is the minimum element
        auto p = head;
        head = head->next;
        size--;
        delete head;
        return head->data;
    }

    // just reverse all next points and update head
    void Reverse() {
        if (size < 2) return;
        auto pre = head;
        auto n = pre->next;

        while (n != nullptr) {
            auto nxt = n->next;
            n->next = pre;
            pre = n;
            n = nxt;
        }
        head->next = nullptr;
        head = pre;
    }

    void PrintAll() {
        auto n = head;
        while (n != nullptr) {
            std::cout << n->data << " ";
            n = n->next;
        }
        std::cout << "\n";
        return;
    }

    int Size() {
        return size;
    }
};

#endif //LINKLIST_LINK_LIST_H
