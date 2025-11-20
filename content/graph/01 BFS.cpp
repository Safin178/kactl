/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: 0-1 BFS
 * Description: Finds shortest paths from source $s$ in a graph with edge weights 0 or 1 using a deque.
 * Usage: Initialize distances `d`, push source `s` to deque, and run the BFS loop.
 * Time: $O(n + m)$
 * Memory: $O(n + m)$
 * Status: 
 */
#pragma once

vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (d[v] + w < d[u]) {
            d[u] = d[v] + w;
            if (w == 1)
                q.push_back(u);
            else
                q.push_front(u); // 0 gets priorty
        }
    }
}