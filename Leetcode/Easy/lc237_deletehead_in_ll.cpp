/*
    LC237: Delete Node in a Linked List
    Difficulty: Medium, but I found it easy

    Tags: Linked List

    Here is a figure to understand what I did:
    4 -> 5 -> 1 -> 9
    I want to delete 5, but I don't have access to the head of the list
    So I copy 1 to node with value 5, and then I make the next of node with value 5 point to the next of node with value 1, which is node with value 9

    I hope that was clear enough. If not, bhai tum to tej ho na, khud samajh lo abhi :-)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;

    // hardcoded array
    int arr[] = {4, 5, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val_to_delete = 5;

    // build linked list
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    // find node to delete
    ListNode* node = head;
    while (node != nullptr && node->val != val_to_delete)
        node = node->next;

    // call function
    if (node != nullptr && node->next != nullptr)
        sol.deleteNode(node);

    // print list
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";

    // free memory
    temp = head;
    while (temp != nullptr) {
        ListNode* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}