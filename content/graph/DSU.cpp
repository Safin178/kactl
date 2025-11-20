/**
 * Author: 
 * Date: 2025-11-20
 * License: CC0
 * Source: Standard DSU / Union-Find algorithm
 * Description: Implements Disjoint Set Union (DSU) with path compression and union by size.
 *              - Initializing a node $u$ as its own set: $makeset(u)$
 *              - Finding the representative (root) of a set containing $u$: $fnd(u)$
 *              - Uniting sets containing $u$ and $v$: $unite(u, v)$
 *              The main function demonstrates reading $m$ edges and reporting whether each edge
 *              connects nodes in the same component or different components.
 * Time: $O(\alpha(n))$ amortized per operation
 * Memory: $O(n)$
 * Status: 
 */
// upobir
const int nmax = 1e5+10;

int master[nmax], sz[nmax];
void makeset(int u){
    master[u] = u;
    sz[u] = 1;
}
int fnd(int u){
    if(master[u] == u) return u;
    return master[u] = fnd(master[u]);
}
bool unite(int u, int v){
    u = fnd(u);
    v = fnd(v);
    if(u == v) return false;
    if(sz[u] < sz[v]){
        master[u] = v;
        sz[v] += sz[u];
    }
    else{
        master[v] = u;
        sz[u] += sz[v];
    }
    return true;
}

int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) makeset(i);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        bool res = unite(u, v);
        if(res){
            cout<<"edge was between two different components"<<endl;
        }
        else{
            cout<<"edge was between same component"<<endl;
        }
    }
}


