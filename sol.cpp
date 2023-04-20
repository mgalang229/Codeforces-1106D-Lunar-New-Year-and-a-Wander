#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool vis[n];
	memset(vis, false, sizeof(vis));
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);
	vis[0] = true;
	while (!pq.empty()) {
		int u = pq.top();
		pq.pop();
		cout << u + 1 << " ";
		for (int& v : adj[u]) {
			if (!vis[v]) {
				pq.push(v);
				vis[v] = true;
			}
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	// cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
