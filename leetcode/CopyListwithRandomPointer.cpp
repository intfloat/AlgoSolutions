// CopyListwithRandomPointer.cpp

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        RandomListNode *copy_head, *cur, *copy_cur;
        // use a map to reserve mapping relations between nodes
        map<RandomListNode *, RandomListNode *> m;
        m.clear();      
        copy_head = new RandomListNode(head->label);
        cur = head; copy_cur = copy_head;
        m[head] = copy_head;
        while((cur->next)!=NULL){                       
            copy_cur->next = new RandomListNode(cur->next->label);
            m[cur->next] = copy_cur->next;
            copy_cur = copy_cur->next;
            cur = cur->next;
        }
        cur = head; copy_cur = copy_head;
        while(cur!=NULL){
            if((cur->random)!=NULL)
                copy_cur->random = m[cur->random];
            cur = cur->next;
            copy_cur = copy_cur->next;
        }
        return copy_head;
    }
};