#include<string>
#include<iostream>
using namespace std;

struct node
{
    string s;
    struct node* next;
};

int main()
{
    string input;
    while(getline(cin,input))
    {
        int i;
        node* now = new node();
        now->s = "a";
        now->next = NULL;
        node* right = now;
        node* left = now;
        int head = 0;
        
        for(i=0;i<input.size();i++)
        {
            if(input[i] == '[')
                head = 1;
            else if(input[i] == ']')
            {
                now = right;
                head = 0;
            }
            else
            {
                string tmp = " ";
                tmp[0] = input[i];
                
                if(head==1)
                {
                    node* in = new node();
                    in->s = tmp;
                    in->next = left->next;
                    left->next = in;
                    
                    head = 0;
                    now = in;
                }
                else
                {
                    node* in = new node();
                    in->s = tmp;
                    in->next = now->next;
                    
                    if(now->next==NULL)
                        right = in;
                    now->next = in;
                    now = in;
                }
            }
        }
        left = left->next;
        while(left)
        {
            node* tmp = left;
            cout << left->s;
            left = left->next;
            delete(tmp);
        }
        cout << endl;
    }
    
    return 0;
}
