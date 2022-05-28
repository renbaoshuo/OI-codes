#include <bits/stdc++.h>
#define R register int
#define ll long long
#define db double
#define FOR(i, j, k) for (R i = j; i <= k; i++)
#define DEC(i, j, k) for (R i = j; i >= k; i--)
#define walk(i, u) for (R i = 0; i < g[u].size(); i++)
#define visch(i, u) for (R i = head[u]; i; i = edge[i].next)
using namespace std;

inline int read()
{
	int x = 0;
	bool flag = 0;
	int ch = getchar();
	while ('0' > ch || ch > '9')
	{
		if (ch == '-')
			flag = 1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return flag ? -x : x;
}

const int maxn = 2510, maxm = 6210;
int n, m, s, t;
struct E
{
	int to, nxt, w;
} edge[maxm << 1];
int head[maxn], ec;
inline void adde(int u, int v, int w)
{
	edge[++ec].to = v;
	edge[ec].nxt = head[u];
	edge[ec].w = w;
	head[u] = ec;
}

deque<int> q;
ll dis[maxn];
bool vis[maxn];
inline void spfa()
{
	FOR(i, 1, n) dis[i] = 0x3f3f3f3f3f3f3f3f;
	dis[s] = 0;
	vis[s] = 1;
	q.push_back(s);
	while (q.size())
	{
		int u = q.front();
		q.pop_front();
		vis[u] = 0;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if (dis[u] + edge[i].w < dis[v])
			{
				dis[v] = dis[u] + edge[i].w;
				if (!vis[v])
					q.push_back(v);
			}
		}
	}
}

int main()
{
	n = read(), m = read(), s = read(), t = read();
	FOR(i, 1, m)
	{
		int x = read(), y = read(), z = read();
		adde(x, y, z);
		adde(y, x, z);
	}
	spfa();
	printf("%lld", dis[t]);
	return 0;
}
