/*
    LC206: Reverse Linked List
    Difficulty: Easy

    Tags: Linked List

    Approach 1: Stack 
    ppush all the values into a stack, and then pop them out and assign to the nodes of the linked list


    Approach 2:  Pointers
    use three pointers, prev, curr and next. Initially, prev is NULL and curr is head. In each iteration 
    (i) store the next node in next
    (ii) make the next of curr point to prev
    (iii) move prev and curr one step forward
    
    Approach 3: Recursion
    Base case: if head is NULL or head->next is NULL, return head
    Recursive case: 
    (i) call the function recursively for the next node, this gives you the new head of the reversed list
    (ii) make the next of the next node point to the current node, which is head in this case, (this was NULL after calling the -1 case)
    (iii) make the next of the current node point to NULL (that's now the end of your list)

*/



#include <bits/stdc++.h>
using namespace std;

 struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}

ListNode* ap1_stack_reverse_List(ListNode* head) {
    stack<int> st;
    ListNode* p = head;
    ListNode* q = head;

    while (p != NULL){
        st.push(p->val);
        p = p->next;
    }

    while (q != NULL) {
        q->val = st.top();
        st.pop();
        q = q->next;
    }

    return head;
}

ListNode* ap2_twopointers_reverse_List(ListNode* head) {
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode* ap3_recursion(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* newHead = ap3_recursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);
    head = ap1_stack_reverse_List(head);
    printList(head);
    head = ap2_twopointers_reverse_List(head);
    printList(head);
    head = ap3_recursion(head);
    printList(head);

    return 0;
}