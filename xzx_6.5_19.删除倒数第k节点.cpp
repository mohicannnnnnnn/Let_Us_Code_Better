给定一个链表，删除链表的倒数第n个节点，并且返回链表的头结点。
示例：
给定一个链表：1->2->3->4->5，和n=2.
当删除了倒数第二个节点后，链表变为1->2->3->5.

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
    //总结：一般自己的链表都会有头结点便于操作，但对于没有头结点的题目来说
    //不要强行写代码，因为测试用例可能会刁难你。所以我们可以使用补头节点的方式
    //降低代码复杂程度。
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n <= 0)
            return head;
        
        //主要错误原因，没有头结点，操作不方便。解决：补头节点。
        ListNode *node = new ListNode(0);
        node->next = head;
        
        //定义快慢指针
        ListNode *pslow = node;
        ListNode *pfast = node;
        
        while(n-- > 0)
        {
            pfast = pfast->next;
        }
        while(pfast->next != nullptr)
        {
            pslow = pslow->next;
            pfast = pfast->next;
        }
        pslow->next = pslow->next->next;

        return node->next;
    }
};