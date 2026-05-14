#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph {
    public:
    int V;
    vector<vector<int>> adj;
    Graph(int ver){
        V = ver;
        adj.resize(V);
    }
    void addEdge(int u  ,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);

    }
    void dfsutil(vector<int>& vis , int node){
        vis[node] =1;
        cout<<node<<endl;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfsutil(vis , it);
            }
        }
    }
    void dfs(int start){
        vector<int> vis(V,0);
        cout<<"dfs:";
        dfsutil(vis , start);
        cout<<endl;
    }
    void bfs(int node){
        vector<int> vis(V,0);
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int n = q.front();
            cout<<q.front()<<endl;
            q.pop();
            for(auto it : adj[n]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        cout<<endl;
    }

};
int main(){
    int v ,edges;

    cout << "Enter number of vertices: ";
    cin >> v;
     cout << "Enter number of edges: ";
    cin >> edges;
    Graph g(v);

    cout << "Enter the edges (u v):\n";

    for(int i  =0 ; i  < edges ;i++){
        int u,vv;
        cin>>u>>vv;
         if (u >= 0 && u < v && vv >= 0 && vv < v) {
            g.addEdge(u, vv);
        } else {
            cout << "Invalid edge! Please enter vertices between 0 and "
                 << v - 1 << endl;
            i--; // Retry this edge
        }
    }
    int start ;
    cout<<"Enter the start node"<<endl;
    cin>>start;
     if (start < 0 || start >= v) {
        cout << "Invalid starting vertex!" << endl;
        return 0;
    }
    cout<<endl;
    g.dfs(start);
    g.bfs(start);

    
}