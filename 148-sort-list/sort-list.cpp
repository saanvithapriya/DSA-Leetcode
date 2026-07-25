/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev = nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* lefthead, ListNode* righthead){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(lefthead!=nullptr && righthead!=nullptr){
            if(lefthead->val < righthead->val){
                temp->next = lefthead;
                temp = lefthead;
                lefthead = lefthead->next;
            }
            else{
                temp->next = righthead;
                temp = righthead;
                righthead = righthead->next;
            }
        }
        if(lefthead)
            temp->next = lefthead;
        else
            temp->next = righthead;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next == nullptr)  
            return head;
        ListNode* middle = findMiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;
        middle->next = nullptr;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return merge(lefthead,righthead);
    }
};