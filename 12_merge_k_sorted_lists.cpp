#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Custom comparator for min-heap
struct CompareNode {
    bool operator()(ListNode* const& p1, ListNode* const& p2) {
        return p1->val > p2->val;
    }
};

// Main Function: Merge k Sorted Lists (Optimal Min-Heap approach: O(N log k) time, O(k) space)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;

    // Push the head of each non-empty list into the min-heap
    for (ListNode* head : lists) {
        if (head != nullptr) pq.push(head);
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* topNode = pq.top();
        pq.pop();

        tail->next = topNode;
        tail = tail->next;

        if (topNode->next != nullptr) {
            pq.push(topNode->next);
        }
    }

    return dummy.next;
}
