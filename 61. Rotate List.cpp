// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
class Solution
{
    int l(ListNode *head)
    {
        ListNode *temp = head;
        int len = 0;

        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        int len = l(head);
        k = k % len;

        ListNode *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = head;

        temp = head;

        int to_rotate = len - k, cnt = 0;

        while (temp != NULL)
        {
            cnt++;
            if (cnt == to_rotate)
            {
                ListNode *ans = temp->next;
                temp->next = NULL;
                return ans;
            }
            temp = temp->next;
        }
        return head;
    }
};