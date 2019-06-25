#include <iostream>
#include <map>

#include <queue>
#include <set>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        
        RandomListNode* ans = new RandomListNode(-1);
        RandomListNode* head = ans;
        RandomListNode* op = pHead;
        
        map<RandomListNode*,RandomListNode*> dict;

        while(op)
        {
            head->next = new RandomListNode(op->label);
            dict[op] = head->next;
            head = head->next;
            op = op->next;
        }

        op = pHead;
        head = ans->next;

        while(op != NULL)
        {
            if(op->random != NULL)
            {
                head->random = dict[op->random];
            }
            head = head->next;
            op = op->next;
        }
        return ans->next;
    }

    RandomListNode* Clone1(RandomListNode* pHead)
    {
        queue<RandomListNode*> que;
        map<RandomListNode*,RandomListNode*> seen;
        que.push(pHead);        
        RandomListNode * head = new RandomListNode(pHead->label);
        RandomListNode * ans = head;
        while(que.size())
        {
            RandomListNode * v = que.front();
            que.pop();
            for(RandomListNode * u = v->next; u!=v->random; u = v->random)
            {
                // if( not seen u )
                // {
                //     que.push(u);
                //     head->next = new RandomListNode(u->label);
                //     head = head->next;
                // }
                // else
                // {

                // }                
            }
        }
    }
};

void print(RandomListNode * op)
{
    while(op){
        cout << op->label << ' ';
        if( op->random )
            cout << " (" << op->random->label << ") ";

        op = op->next;
    }
    cout << endl;
}

int main()
{
    RandomListNode * head1 = new RandomListNode(0);
    head1->next = new RandomListNode(1);
    head1->next->next = new RandomListNode(2);
    head1->next->next->next = new RandomListNode(3);
    head1->next->next->next->next = new RandomListNode(4);
    head1->random = head1->next;
    head1->next->random = head1->next->next;
    head1->next->next->random = head1->next;
    head1->next->next->next->random = head1->next;

    RandomListNode * op = head1;

    print(op);

    Solution sol;

    RandomListNode * ans = sol.Clone(head1);
    print(ans);

    return 0;
}