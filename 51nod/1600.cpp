#include<cstdio>
#include<cstring>
#define P 1000000007
char s[200010];
int n;
int ch[26][400010],mx[400010],par[400010],pcnt;
void build()
{
	int p=pcnt=1;
	for(int i=1;i<=n;++i)
	{
		int w=s[i]-'a';
		int np=++pcnt;
		mx[np]=mx[p]+1;
		while(p&&!ch[w][p])
		{
			ch[w][p]=np;
			p=par[p];
		}
		if(!p)
			par[np]=1;
		else
		{
			int q=ch[w][p];
			if(mx[q]==mx[p]+1)
				par[np]=q;
			else
			{
				int nq=++pcnt;
				mx[nq]=mx[p]+1;
				while(p&&ch[w][p]==q)
				{
					ch[w][p]=nq;
					p=par[p];
				}
				for(int j=0;j<26;++j)
					ch[j][nq]=ch[j][q];
				par[nq]=par[q];
				par[np]=par[q]=nq;
			}
		}
		p=np;
	}
}
#define ls (k<<1)
#define rs (k<<1|1)
#define mid ((L+R)>>1)
int v[1600100],V[1600100],lazy[1600100];
int b[400100];
void build(int k,int L,int R)
{
	if(L==R)
	{
		V[k]=b[L];
		return;
	}
	build(ls,L,mid);
	build(rs,mid+1,R);
	V[k]=(V[ls]+V[rs])%P;
}
void pushdown(int k,int L,int R)
{
	if(L==R||!lazy[k])
		return;
	long long x=lazy[k];
	lazy[k]=0;
	lazy[ls]=(lazy[ls]+x)%P;
	v[ls]=(v[ls]+x*V[ls])%P;
	lazy[rs]=(lazy[rs]+x)%P;
	v[rs]=(v[rs]+x*V[rs])%P;
}
void change(int k,int l,int r,int L,int R,int x)
{
	if(r<L||l>R)
		return;
	if(l<=L&&r>=R)
	{
		lazy[k]=(lazy[k]+x)%P;
		v[k]=(v[k]+(long long)x*V[k])%P;
		return;
	}
	pushdown(k,L,R);
	change(ls,l,r,L,mid,x);
	change(rs,l,r,mid+1,R,x);
	v[k]=(v[ls]+v[rs])%P;
}
int ask(int k,int l,int r,int L,int R)
{
	if(r<L||l>R)
		return 0;
	if(l<=L&&r>=R)
		return v[k];
	pushdown(k,L,R);
	return (ask(ls,l,r,L,mid)+ask(rs,l,r,mid+1,R))%P;
}
struct edge
{
	int n,nxt;
	edge(int n,int nxt)
	{
		this->n=n;
		this->nxt=nxt;
	}
	edge(){}
}e[400100];
int head[400100],ecnt=-1;
void add(int from,int to)
{
	e[++ecnt]=edge(to,head[from]);
	head[from]=ecnt;
}
int tp[400100],dfn[400100],sz[400100],d[400100],hs[400100],cnt=0;
void dfs(int x)
{
	sz[x]=1;
	for(int i=head[x];~i;i=e[i].nxt)
	{
		d[e[i].n]=d[x]+1;
		dfs(e[i].n);
		sz[x]+=sz[e[i].n];
		hs[x]=sz[hs[x]]>sz[e[i].n]?hs[x]:e[i].n;
	}
}
void dfs2(int x,int t)
{
	dfn[x]=++cnt;
	tp[x]=t;
	if(hs[x])
		dfs2(hs[x],t);
	for(int i=head[x];~i;i=e[i].nxt)
		if(e[i].n!=hs[x])
			dfs2(e[i].n,e[i].n);
}
void modify(int u,int v,int x)
{
	while(tp[u]!=tp[v])
	{
		if(d[tp[u]]<d[tp[v]])
		{
			int t=u;
			u=v;
			v=t;
		}
		change(1,dfn[tp[u]],dfn[u],1,pcnt,x);
		u=par[tp[u]];
	}
	if(dfn[u]<dfn[v])
		change(1,dfn[u],dfn[v],1,pcnt,x);
	else
		change(1,dfn[v],dfn[u],1,pcnt,x);
}
int Ask(int u,int v)
{
	int ans=0;
	while(tp[u]!=tp[v])
	{
		if(d[tp[u]]<d[tp[v]])
		{
			int t=u;
			u=v;
			v=t;
		}
		ans=(ans+ask(1,dfn[tp[u]],dfn[u],1,pcnt))%P;
		u=par[tp[u]];
	}
	if(dfn[u]<dfn[v])
		ans=(ans+ask(1,dfn[u],dfn[v],1,pcnt))%P;
	else
		ans=(ans+ask(1,dfn[v],dfn[u],1,pcnt))%P;
	return ans;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	scanf("%s",s+1);
	build();
	for(int i=2;i<=pcnt;++i)
		add(par[i],i);
	d[1]=1;
	dfs(1);
	dfs2(1,1);
	for(int i=1;i<=pcnt;++i)
		b[dfn[i]]=mx[i]-mx[par[i]];
	build(1,1,pcnt);
	int p=1,ans=0,sum=0;
	for(int i=1;i<=n;++i)
	{
		int w=s[i]-'a';
		while(p&&!ch[w][p])
			p=par[p];
		if(p)
			p=ch[w][p];
		else
			p=1;
		sum=(sum+Ask(1,p))%P;
		ans=(ans+sum)%P;
		printf("%d\n",ans);
		modify(1,p,1);
	}
	return 0;
}
