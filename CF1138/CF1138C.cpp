#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using std::max;
using std::pair;
using std::sort;
using std::make_pair;
pair<int,int> p[1010];
int a[1010][1010];
int r[1010][1010],c[1010][1010];
int N[1010],M[1010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            p[j]=make_pair(a[i][j],j);
        sort(p+1,p+1+m);
        int cnt=0;
        for(int j=1;j<=m;++j)
        {
            if(p[j].first!=p[j-1].first)
                ++cnt;
            r[i][p[j].second]=cnt;
        }
        N[i]=cnt;
    }

    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
            p[j]=make_pair(a[j][i],j);
        sort(p+1,p+1+n);
        int cnt=0;
        for(int j=1;j<=n;++j)
        {
            if(p[j].first!=p[j-1].first)
                ++cnt;
            c[p[j].second][i]=cnt;
        }
        M[i]=cnt;
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            printf("%d ",max(r[i][j],c[i][j])+max(N[i]-r[i][j],M[j]-c[i][j]));
        puts("");
    }
    return 0;
}
