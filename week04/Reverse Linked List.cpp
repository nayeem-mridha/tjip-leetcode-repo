// TC: O(N)
// SC: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto currNode = head;
        ListNode* prvNode = NULL;
        while (currNode) {
            auto nextNode = currNode -> next;
            currNode -> next = prevNode;
            prvNode = currNode;
            currNode = nextNode;
        }
        return prvNode;
    }
};