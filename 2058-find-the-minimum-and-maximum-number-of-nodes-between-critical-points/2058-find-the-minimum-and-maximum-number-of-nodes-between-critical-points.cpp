class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos = 1;

        ListNode* prevNode = head;
        ListNode* curr = head->next;

        int first = -1;
        int prev = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        while (curr->next != NULL) {

            ListNode* nextNode = curr->next;

            // Check local maxima or local minima
            if ((curr->val > prevNode->val && curr->val > nextNode->val) ||
                (curr->val < prevNode->val && curr->val < nextNode->val)) {

                if (first == -1) {
                    // First critical point
                    first = pos;
                } 
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - prev);

                    // Distance from first critical point
                    maxDist = max(maxDist, pos - first);
                }

                prev = pos;
            }

            prevNode = curr;
            curr = nextNode;
            pos++;
        }

        if (maxDist == -1) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};