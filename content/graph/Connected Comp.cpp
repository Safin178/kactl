/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Standard DFS for connected components
 * Description: Finds all connected components in an undirected graph with $n$ vertices.
 *              Uses DFS to explore unvisited vertices and collects each component in $\text{comp}$.
 * Usage: Initialize $\text{adj}$ and $\text{used}$, then call $\text{find\_comps}()$ to print components.
 * Time: $O(n + m)$
 * Memory: $O(n + m)$
 * Status: 
 */
#pragma once

int n;
vector<vector<int>> adj;
vector<bool> used;
vector<int> comp;

void dfs(int v) {
    used[v] = true ;
    comp.push_back(v);
    for (int u : adj[v]) {
        if (!used[u])
            dfs(u);
    }
}

void find_comps() {
    fill(used.begin(), used.end(), 0);
    for (int v = 0; v < n; ++v) {
        if (!used[v]) {
            comp.clear();
            dfs(v);
            cout << "Component:" ;
            for (int u : comp)
                cout << ' ' << u;
            cout << endl ;
        }
    }
}