#include<bits/stdc++.h>
using namespace std;
struct node
{

    bool endmark;
    node* next[2];

    node()
    {
        endmark = false;
        next[0] = NULL;
        next[1] = NULL;
    }
};
node* root;
bool insert(char* str,int len)
{
    node* curr = root;

    for(int i=0; i<len; i++)
    {
        int id = str[i]-'0';
        if(curr->endmark)
            return false;

        if(curr->next[id]==NULL)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    if(curr->endmark)
        return false;
    else
    {
        curr->endmark = true;
    }
    if(curr->next[0]!=NULL||curr->next[1]!=NULL)
        return false;

        return true;
}

void del(node* curr)
{
    for(int i=0; i<2; i++)
    {
        if(curr->next[i])
        {
            del(curr->next[i]);
        }
    }
    delete(curr);


}
int main()
{
    char str[20],ch;

    int n,m,a,b,i,j,x,y,k=0;
    bool flag,flag2;
    flag = true;
    flag2 = false;

    root = new node();
    while(scanf("%s",&str)==1)
    {

        if(strcmp(str,"9")==0)
        {
            if(flag)
            {
                printf("Set %d is immediately decodable\n",++k);
            }
            else
            {
                printf("Set %d is not immediately decodable\n",++k);

            }
            //del(root);
            delete(root);
            root = new node();
            flag = true;
        }
        else
        {
            flag2 = insert(str,strlen(str));

            if(flag2==false)
            {
                flag = false;
            }
        }

    }

    return 0;
}
