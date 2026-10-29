#include <unordered_map>
using namespace std;

// Definition for a Node with a next and random pointer
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// ============================================================================
// Approach 1: Hash Map (O(N) Time, O(N) Space)
// ============================================================================
// Store mapping from original node pointer -> clone node pointer.
Node* copyRandomListHashMap(Node* head) {
    if (!head) return nullptr;

    unordered_map<Node*, Node*> cloneMap;

    // Step 1: Create all copy nodes
    Node* curr = head;
    while (curr) {
        cloneMap[curr] = new Node(curr->val);
        curr = curr->next;
    }

    // Step 2: Assign next and random pointers
    curr = head;
    while (curr) {
        cloneMap[curr]->next = cloneMap[curr->next];
        cloneMap[curr]->random = cloneMap[curr->random];
        curr = curr->next;
    }

    return cloneMap[head];
}

// ============================================================================
// Approach 2: In-Place 3-Step Pointer Manipulation (Optimal: O(N) Time, O(1) Space)
// ============================================================================
// Step 1: Create copy nodes and weave them into the original list:
//         Original: A -> B -> C
//         Weaved:   A -> A' -> B -> B' -> C -> C'
// Step 2: Set random pointers for copy nodes:
//         A'->random = A->random ? A->random->next : nullptr
// Step 3: Separate the original and copied lists:
//         Original: A -> B -> C
//         Copied:   A' -> B' -> C'
Node* copyRandomListOptimal(Node* head) {
    if (!head) return nullptr;

    // Step 1: Insert cloned nodes right after each original node
    Node* curr = head;
    while (curr) {
        Node* copyNode = new Node(curr->val);
        copyNode->next = curr->next;
        curr->next = copyNode;
        curr = copyNode->next;
    }

    // Step 2: Connect the random pointers for the copied nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Detach the copied list and restore the original list
    Node dummy(0);
    Node* copyTail = &dummy;
    curr = head;

    while (curr) {
        Node* copyNode = curr->next;
        curr->next = copyNode->next;

        copyTail->next = copyNode;
        copyTail = copyTail->next;

        curr = curr->next;
    }

    return dummy.next;
}

// Main Function: Clone Linked List with Random Pointer (LeetCode 138)
Node* copyRandomList(Node* head) {
    return copyRandomListOptimal(head);
}
