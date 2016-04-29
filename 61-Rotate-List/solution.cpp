/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// // Not Work
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head==NULL) return NULL;
        
//         ListNode* temp=head;
//         int n=0;
//         while(temp!=NULL){
//             ++n;
//             temp=temp->next;
//         }
//         k%=n;
        
//         ListNode* rotate_head=head;
        
//         for(int i=0;i<n-k-1;++i){
//             rotate_head=rotate_head->next;
//         }
        
//         //若rotate_head==NULL后，会出现BUG
        
//         temp=rotate_head;
//         rotate_head=rotate_head->next;
//         temp->next=NULL;
        
//         temp=rotate_head;
//         for(int i=0;i<k-1;++i){
//             temp=temp->next;
//         }
        
//         temp->next=head;
        
//         return rotate_head;
//     }
// };



// 思路：形成一个环，然后断开
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        ListNode* p=head;
        int len=1;
        while(p->next!=NULL){
            ++len;
            p=p->next;
        }
        k%=len;
        
        p->next=head; //首尾相连
        for(int i=0;i<len-k;++i){
            p=p->next;
        }
        head=p->next;
        p->next=NULL; //断开
        
        return head;
    }
};
