#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
using namespace std ;  
  
struct DicTree  
{  
    struct DicTree * next[26] ;  
    int cnt ;  
}*a;  
  
void init()  
{  
    a = new DicTree ;  
    for(int i = 0 ;i<26 ;i++)  
    {  
        a->next[i] = NULL ;  
    }  
}  
  
int insert(char str[])  
{  
    int len = strlen(str) ;  
    DicTree * head = a ;  
    for(int i = 0 ;i<len ;i++)  
    {  
        int res =  (int)(str[i]-97) ;  
        if(head->next[res] == NULL)  
        {  
            head->next[res] = new DicTree ;  
            head = head->next[res] ;  
            head->cnt = 0 ;  
            for(int j = 0 ;j<26 ;j++)  
            {  
                head->next[i] = NULL ;  
            }  
        }  
        else  
        {  
            head = head->next[res] ;  
        }  
    }  
    head->cnt++ ;  
    return head->cnt ;  
}  
  
int main()  
{  
    int num ;  
    int maxNum ;  
    int tmp ;  
    char str[100],ans[100] ;  
    scanf("%d",&num) ;  
    init() ;  
    maxNum = 0 ;  
    for(int i = 0 ;i<num ;i++)  
    {  
        scanf("%s",str) ;  
        tmp = insert(str) ;  
        if(tmp > maxNum)  
        {  
            maxNum = tmp ;  
            strcpy(ans,str) ;  
        }  
    }  
    printf("the max num is %d   the word is %s\n",maxNum,ans) ;  
    return 0 ;  
}  