#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1,c=getchar();
	while(c<48) c=='-'&&(f=-1),c=getchar();
	while(c>47) x=x*10+c-'0',c=getchar();
	return x*f;
}

const int MAXN = 200005;
int ls[MAXN*32],rs[MAXN*32],sum[MAXN*32];
int rt[MAXN],val[MAXN],raw[MAXN];
int n,m,q,tot;

void insert(int &x,int y,int l,int r,int k)
{
	ls[x=++tot]=ls[y]; rs[x]=rs[y]; sum[x]=sum[y]+1;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(k<=mid) insert(ls[x],ls[y],l,mid,k);
	if(k>mid)  insert(rs[x],rs[y],mid+1,r,k);
}

int query(int x,int y,int l,int r,int k)
{
	if(l==r) return l;
	int mid=(l+r)>>1,s=sum[ls[y]]-sum[ls[x]];
	if(k<=s) return query(ls[x],ls[y],l,mid,k);
	return query(rs[x],rs[y],mid+1,r,k-s);
}

int main(int argc, char const *argv[])
{
	n=read(); q=read();
	for(int i=1; i<=n; ++i)
		val[i]=raw[i]=read();
	sort(val+1,val+n+1);
	m=unique(val+1,val+n+1)-val-1;
	for(int i=1,k; i<=n; ++i)
	{
		k=lower_bound(val+1,val+m+1,raw[i])-val;
		insert(rt[i],rt[i-1],1,m,k);
	}
	for(int i=1,l,r,k,x; i<=q; ++i)
	{
		l=read(); r=read(); k=read();
		x=query(rt[l-1],rt[r],1,m,k);
		printf("%d\n", val[x]);
	}
	return 0;
}
