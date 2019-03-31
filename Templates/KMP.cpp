#include<cstdio>
#include<cstring>
char s[1000100],t[1000100];
int nxt[1000100];
int main()
{
    scanf("%s",s+1);
    scanf("%s",t+1);
    int n;
    for(int i=2,j=0;t[i]!='\0';++i)
    {
        while(j&&t[j+1]!=t[i])
            j=nxt[j];
        if(t[j+1]==t[i])
            ++j;
        nxt[i]=j;
        n=i;
    }
    for(int i=1,j=0;s[i]!='\0';++i)
    {
        while(j==n||(j&&t[j+1]!=s[i]))
            j=nxt[j];
        if(t[j+1]==s[i])
            ++j;
        if(j==n)
            printf("%d\n",i-n+1);
    }
    for(int i=1;i<=n;++i)
        printf("%d ",nxt[i]);
    return 0;
}