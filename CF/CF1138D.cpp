#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
char s[500100],t[500100];
int nxt[500100];
int main()
{
    int a=0,n=0;
    scanf("%s",s+1);
    for(int i=1;s[i]!='\0';++i)
    {
        a+=(s[i]-'0');
        n=i;
    }
    int b=n-a;
    int m=1;
    scanf("%s",t+1);
    for(int i=2,j=0;t[i]!='\0';++i)
    {
        while(j&&t[i]!=t[j+1])
            j=nxt[j];
        if(t[i]==t[j+1])
            ++j;
        nxt[i]=j;
        m=i;
    }
    int k=m-nxt[m],p=0;
    //p表示前缀中出现的1的次数
    for(int i=1;i<=k;++i)
        p+=(t[i]-'0');
    int tmp=min((!p)?a:a/p,(!(k-p))?b:b/(k-p));
    for(int i=1;i<=tmp;++i)
        for(int j=1;j<=k;++j)
            printf("%c",t[j]);
    a-=tmp*p,b-=tmp*(k-p);
    int g=1;
    while(a||b)
    {
        if(!b)
        {
            printf("1");
            --a;
        }
        else if(!a)
        {
            printf("0");
            --b;
        }
        else
        {
            if(t[g]=='0')
            {
                printf("0");
                --b;
            }
            else
            {
                printf("1");
                --a;
            }
        }
        g=g%k+1;
    }
    return 0;
}#include<cstdio>
#include<cstring>
int a[100100];
int main()
{
    int n,lst=0,cnt=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if(a[i]==a[i-1])
            ++cnt;
        else
        {
            lst=cnt;
            cnt=1;
        }
        if(cnt<=lst)
            ans=ans>cnt*2?ans:cnt*2;
    }
    printf("%d\n",ans);
    return 0;
}
