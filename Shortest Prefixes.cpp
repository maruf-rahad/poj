#include<iostream>
#include<stdio.h>
#include<string.h>

struct node{

    int num;
    int endmark;
    node* next[27];
    node()
    {
        num = 0;
        endmark = 0;
        for(int i=0;i<=26;i++)
        {
            next[i] = NULL;
        }
    }

};

node* root;

void insert(char* str,int len)
{
    node* curr = root;

    for(int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if(curr->next[id]==NULL)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
        curr->num++;
    }
    curr->endmark = true;
}
int search(char* str,int len)
{
    node* curr = root;
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        curr = curr->next[id];
        if(curr->num==1)
        {
            return i+1;
        }
    }
    return len;
}

int main()
{
    char str[1005][30];
    int n = 0;

    root = new node();
    while(scanf("%s",&str[n])==1)
    {
        insert(str[n],strlen(str[n]));
        n++;
    }
        for(int i=0;i<n;i++)
        {
            int a = search(str[i],strlen(str[i]));
            printf("%s ",str[i]);
            for(int j=0;j<a;j++)
            {
                printf("%c",str[i][j]);
            }
            printf("\n");

        }

return 0;
}
