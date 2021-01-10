#include <iostream>
#include <cstddef>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <string>

using namespace std;

#if 0
https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
#endif

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class SolutionBasic
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<ListNode *> num;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            num.push_back(temp);
            temp = temp->next;
        }

        swap(num[k - 1]->val, num[num.size() - k]->val);

        return head;
    }
};

class SolutionBasic1
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = head;
        ListNode *last = head;
        ListNode *temp = head;
        int size = 0;

        while (temp != nullptr)
        {
            size++;

            if (size == k)
            {
                first = temp;
            }

            temp = temp->next;
        }

        int cur = 0;
        temp = head;
        while (cur++ != size - k)
        {
            temp = temp->next;
        }
        last = temp;

        swap(first->val, last->val);

        return head;
    }
};

class SolutionImproved
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = head;
        ListNode *last = head;
        ListNode *temp = head;
        int size = 0;

        while (temp != nullptr)
        {
            size++;

            if (last != nullptr)
            {
                last = last->next;
            }

            if (size == k)
            {
                first = temp;
                last = head;
            }

            temp = temp->next;
        }

        swap(first->val, last->val);

        return head;
    }
};

int main()
{
}