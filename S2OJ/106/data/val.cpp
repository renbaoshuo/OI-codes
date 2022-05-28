#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 5005;
const int LIM = 3e5;
int f[MAXN];
int n,m,s,t;

inline int find(int x)
{
	return f[x]!=x?f[x]=find(f[x]):x;
}

inline void merge(int x,int y)
{
	x=find(x); y=find(y);
	if(x^y) f[x]=y;
}

int main(int argc, char *argv[])
{
	registerValidation();

	n=inf.readInt(1,2500); inf.readSpace();
	m=inf.readInt(1,min(n*(n-1)/2,6200)); inf.readSpace();
	s=inf.readInt(1,n); inf.readSpace();
	t=inf.readInt(1,n); inf.readEoln();

	for(int i=1; i<=n; ++i) f[i]=i;

	for(int i=1,u,v; i<=m; ++i)
	{
		u=inf.readInt(1,n); inf.readSpace();
		v=inf.readInt(1,n); inf.readSpace();
		inf.readInt(1,LIM); inf.readEoln();

		ensuref(u!=v,"Self loop found!");
		merge(u,v);
	}

	inf.readEof();

	ensuref(find(s)==find(t),"The graph is not connected!");

	return 0;
}
