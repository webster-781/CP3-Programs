#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

pair<ListNode*,ListNode*> rev(ListNode* head, int cnt, ListNode* set)    //     revereses cnt nodes after head and returns the last vertex
{
    cout<<"Reversing from "<<head->val<<endl;
    ListNode* n1 = head;
    ListNode* n2 = set;
    while(cnt--)
    {
        ListNode* temp = n1->next;
        n1->next = n2;
        n2 = n1;
        n1 = temp;
    }
    return make_pair(n1,n2);
}

int cntNext(ListNode* head)
{
    if(head == nullptr)
            return 0;
    if(head->next == nullptr)
            return 1;
    return 1 + cntNext(head);
}
    
ListNode* reverseKGroup(ListNode* head, int k) {
    int tcnt = cntNext(head);
    if(tcnt < k)
        return head;
    pair<ListNode*, ListNode*> p = rev(head,k,nullptr);
    ListNode* cur = p.first;
    ListNode* ret = cur;
    ListNode* setN = p.second;
    tcnt -= k;
    while(tcnt>=k)
    {
        p = rev(cur,k,setN);
        cur = p.first;
        setN = p.second;
        tcnt -= k;
    }
    return ret;
}

int main()
{
    ListNode* x = new ListNode(1);
    ListNode* head = x;
    for(int t = 2; t < 10; t++)
    {
        x->next = new ListNode(t);
        x = x->next;
    }
    int k = 3;
    ListNode* ans = reverseKGroup(ans,k);
    ans = head;
    while(ans!=nullptr)
    {
        cout<<ans->val<<" ";
        ans = ans -> next;
    }
    cout<<endl;
}