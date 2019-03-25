#include<cstdio>
#include<algorithm>
#include<queue>
using std::priority_queue;
using std::sort;
priority_queue<int> q;
struct song
{
    int l,b;
    friend bool operator <(song A,song B)
    {
        return A.b>B.b;
    }
}a[300100];
int main()
{
    long long ans=0;
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d%d",&a[i].l,&a[i].b);
    sort(a+1,a+1+n);
    long long len=0;
    for(int i=1;i<=n;++i)
    {
        len+=a[i].l;
        q.push(-a[i].l);
        if(q.size()>k)
        {
            len+=q.top();
            q.pop();
        }
        ans=ans>len*a[i].b?ans:len*a[i].b;
    }
    printf("%I64d\n",ans);
    return 0;
}