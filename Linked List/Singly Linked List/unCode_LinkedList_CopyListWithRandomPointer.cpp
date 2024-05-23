//Program for copyinh list with random pointer

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if (!head) return nullptr;

        Node* current = head;
        while (current) 
        {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        current = head;
        while (current) 
        {
            if (current->random) 
            {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        Node* copyHead = head->next;
        Node* copyCurrent = copyHead;
        current = head;

        while (current) 
        {
            current->next = current->next->next;
            if (copyCurrent->next) 
            {
                copyCurrent->next = copyCurrent->next->next;
            }
            current = current->next;
            copyCurrent = copyCurrent->next;
        }

        return copyHead;
    }
};

void printList(Node* head) 
{
    Node* temp = head;
    while (temp) 
    {
        cout << "Node value: " << temp->val;
        if (temp->random) 
        {
            cout << ", Random points to: " << temp->random->val << endl;
        } 
        else 
        {
            cout << ", Random points to: null" << endl;
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{
    // Create list: 1 -> 2 -> 3 with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next; // 1's random points to 3
    head->next->random = head; // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2

    cout << "Original list:" << endl;
    printList(head);

    Solution sol;
    Node* copiedList = sol.copyRandomList(head);

    cout << "Copied list:" << endl;
    printList(copiedList);

    return 0;
}
