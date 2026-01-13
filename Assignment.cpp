#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverseList(Node* head) {
    Node* curr1 = head;
    Node* temp1 = NULL;

    while (curr1) {
        Node* temp2 = curr1->next;
        curr1->next = temp1;
        temp1 = curr1;
        curr1 = temp2;
    }
    return temp1;
}

Node* addTwoLists(Node* head1, Node* head2) {
    Node* test1 = reverseList(head1);
    Node* test2 = reverseList(head2);

    int carry = 0;
    Node* temp1 = new Node(0);
    Node* curr1 = temp1;

    while (test1 || test2 || carry) {
        int sum = carry;

        if (test1) {
            sum += test1->data;
            test1 = test1->next;
        }
        if (test2) {
            sum += test2->data;
            test2 = test2->next;
        }

        carry = sum / 10;
        curr1->next = new Node(sum % 10);
        curr1 = curr1->next;
    }

    Node* result = reverseList(temp1->next);
    return result;
}
