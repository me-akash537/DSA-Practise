#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

Node* insert_at_head(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

Node* insert_at_tail(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;

    // mention that you didn't set newNode->next to nullptr because in the constructor of Node, we already set it to nullptr
}

void print_ll(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Node* head = nullptr;

    head = insert_at_head(head, 3);
    head = insert_at_head(head, 2);
    head = insert_at_head(head, 1);
    print_ll(head);

    head = insert_at_tail(head, 4);
    head = insert_at_tail(head, 5);
    print_ll(head);

    return 0;
}
