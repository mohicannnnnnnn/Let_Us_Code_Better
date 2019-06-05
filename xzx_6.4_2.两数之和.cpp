给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
	输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
	输出：7 -> 0 -> 8
	原因：342 + 465 = 807

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
        if(l1 == nullptr && l2 != nullptr)
            return l2;
        if(l1 != nullptr && l2 == nullptr)
            return l1;
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        
        ListNode *node = new ListNode(0);
        int carry = 0;//进位
        int a,b;
        ListNode *tmp1 = node;
        while(l1 != nullptr || l2 != nullptr)
        {
            l1 == nullptr?a=0:a=l1->val;
            l2 == nullptr?b=0:b=l2->val;
            
            int tmp = a+b+carry;
            carry = 0;
            if(tmp >= 10)
            {
                carry = 1;
                tmp %= 10;
            }
            tmp1->next = new ListNode(tmp);
            tmp1 = tmp1->next;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        if(carry != 0)
        {
            tmp1->next = new ListNode(carry);
            tmp1 = tmp1->next;
        }
        return node->next;
    }
};