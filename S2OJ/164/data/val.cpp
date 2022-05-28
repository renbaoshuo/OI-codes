#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 2e5;
const int LIM = 1e9;
int n,m;

int main(int argc, char *argv[])
{
	registerValidation();

	n=inf.readInt(1,MAXN); inf.readSpace();
	m=inf.readInt(1,MAXN); inf.readEoln();

	for(int i=1; i<=n; ++i)
	{
		inf.readInt(-LIM,LIM);
		if(i!=n) inf.readSpace();
	}

	inf.readEoln();

	for(int i=1; i<=m; ++i)
	{
		int l=inf.readInt(1,n); inf.readSpace();
		int r=inf.readInt(l,n); inf.readSpace();
		inf.readInt(1,r-l+1); inf.readEoln();
	}

	inf.readEof();
	return 0;
}
