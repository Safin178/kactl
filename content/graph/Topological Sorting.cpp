/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Standard DFS-based Topological Sort youknowwho Problem Reference: https://cses.fi/problemset/task/1679
 * Description: Computes a topological ordering of a directed graph with $n$ vertices.
 *              - `g[u]` stores all outgoing edges from vertex $u$.
 *              - `vis[u]` marks whether vertex $u$ has been visited during DFS.
 *              - `ord` stores the vertices in reverse postorder, giving the topological order after reversing.
 *              The code also checks for cycles: if a cycle exists, outputs "IMPOSSIBLE".
 *  
 * Time: $O(n + m)$
 * Memory: $O(n + m)$
 */
#pragma once

const int N = 1e5 + 9; 
vector<int> g[N];
bool vis[N];
vector<int> ord;
void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
  ord.push_back(u);
}
int32_t main() {
  
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  reverse(ord.begin(), ord.end());

  // check is feasible
  vector<int> pos(n + 1);
  for (int i = 0; i < (int) ord.size(); i++) {
    pos[ord[i]] = i;
  }
  for (int u = 1; u <= n; u++) {
    for (auto v: g[u]) {
      // We need to consider self loops too!
      if (pos[u] >= pos[v]) { 
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
  }

  // print the order
  for (auto u: ord) cout << u << ' ';
  cout << '\n';
  return 0;
}

