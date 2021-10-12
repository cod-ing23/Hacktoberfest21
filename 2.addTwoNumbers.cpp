/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> u,v;
        while(l1->next != NULL){
            u.push_back(l1->val);
            l1 = l1->next;
        }
        u.push_back(l1->val);
        while(l2->next != NULL){
            v.push_back(l2->val);
            l2 = l2->next;
        }
        v.push_back(l2->val);
        vector<int> w;
        int carry = 0 ;
        for(int i=0,j=0;i<max(v.size(),u.size()),j<max(v.size(),u.size());i++,j++){
            int val;
            if(i>=u.size()){
                val = carry + v[j];
            }
            else if(j>=v.size()){
                val = carry + u[i];
            }
            else{
                val = carry+u[i]+v[j];
            }
            if(val>=10){
                w.push_back(val%10);
                carry = val/10;
            }
            else{
                w.push_back(val);
                carry = 0;
            }
        }
        if(carry > 0){
            w.push_back(carry);
        }
        ListNode* temp = new ListNode(w[0]);
        ListNode* ptr = temp;
        for(int i=1;i<w.size();i++){
            ptr->next = new ListNode(w[i]);
            ptr = ptr->next;
        }
        return temp;
    }
};
