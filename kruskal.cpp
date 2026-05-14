#include <bits/stdc++.h>
using namespace std;
// struct Edge{
//     int src  , dest , wt;
// };
// bool compare(Edge a , Edge b){return a.wt < b.wt;}
// class DisjointSet {
//     vector<int> parent, rank;
//     public:
//     DisjointSet(int n){
//         parent.resize(n);
//         rank.resize(n,0);
//         for(int i  =0 ;  i < n;i++)parent[i] = i;

//     }
//     int find(int x){
//         if(parent[x] != x){
//             parent[x]  = find(parent[x]);
//         }
//         return parent[x];
//     }
//     void unite(int  u, int v){
//         int uu = find(u);
//         int uv = find(v);
//         if(uu == uv)return ;
//         if(rank[uu ] < rank[uv] )
//         {
//             parent[uu] = uv;
//         }
//         else if(rank[uu] > rank[uv]){
//             parent[uv]= uu;

//         }
//         else{
//                 parent[uv] = uu;
//                 rank[uu]++;
//         }
//     }
// };
// void solve(vector<Edge>& edges , int n){
//     DisjointSet d(n);
//     sort(edges.begin() , edges.end() , compare);
//     vector<Edge> mst;
//     int totalwt = 0;
//     for(Edge e : edges){
//         int u  =  e.src;
//         int v = e.dest;
//         if(d.find(u) != d.find(v)){
//             mst.push_back(e);
//             totalwt+= e.wt;
//             d.unite(u,v);
//         }
//         if(mst.size() == n-1)break;
//     }
//     cout << "\nEdges in the Minimum Spanning Tree:\n";
//     for (Edge edge : mst) {
//         cout << edge.src << " -- " << edge.dest
//              << " == " << edge.wt << endl;
//     }

//     cout << "\nTotal weight of MST = " << totalwt << endl;
// }

// int main(){
//     int v,e;
    
//     cout << "Enter number of vertices: ";
//     cin >> v;

//     cout << "Enter number of edges: ";
//     cin >> e;
//     vector<Edge> edges(e);

//     cout << "Enter each edge in the format: source destination weight\n";
//     cout << "(Vertices should be numbered from 0 to " << v - 1 << ")\n";

//     for (int i = 0; i < e; i++) {
//         cin >> edges[i].src >> edges[i].dest >> edges[i].wt;
//     }
//     solve(edges , v);


// }
//=================================================================================

//selection
// int main(){
//     int n ;
//     cout<<"Enter the size of array"<<endl;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i = 0 ; i < n;i++)cin>>arr[i];
//     for(int i = 0 ; i  < n-1; i++){
//         int mindind = i;
//         for(int j = i+1 ; j < n ;j++){
//             if(arr[j] < arr[i]){
//                 mindind = j;
//             }
//         }
//         swap(arr[mindind ] , arr[i]);
//     }
//         for(int i = 0 ; i < n;i++)cout<<arr[i];
// }



// ======================================================================================
// dijkstra
void dijkstra(int V ,vector<vector<pair<int, int>>> adj , int src ){
    vector<int> dist(V,1e9 );
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(d > dist[node])continue;
        for(auto it : adj[node])
        {
            int v = it.first;
            int wt= it.second;
            if(dist[node] + wt  < dist[v]){
                dist[v] = dist[node] + wt;
                pq.push({dist[v] ,v});
            }
        }
    }
    for(int i  =0  ; i < V ; i++){
        cout<<"Vertext "<<i << " "<<dist[i]<<endl;
    }
}
int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    // Adjacency list: adj[u] = {{v, weight}, ...}
    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter each edge in the format: source destination weight\n";
    cout << "(Vertices should be numbered from 0 to " << V - 1 << ")\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // For an undirected graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(V, adj, source);
}