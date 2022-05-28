#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int LIM = 1e6;
string s,t;
int n,m;

int main(int argc, char *argv[])
{
	registerValidation();

	s=inf.readWord(); inf.readEoln();
	t=inf.readWord(); inf.readEoln();

	inf.readEof();

	n=s.length(); m=t.length();

	ensuref(n<=LIM&&m<=LIM, "The string is too long!");
	ensuref(n>=m, "The second string shouldn't be longer than the first one!");

	return 0;
}
