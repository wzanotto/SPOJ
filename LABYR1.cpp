#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <iterator>
#include <stack>
#include <queue>
#include <list>
#include <cstring>

// C++ program to find longest path of the tree
using namespace std;

// This class represents a undirected graph using adjacency list
class Graph
{
    int V;              // No. of vertices
    vector<int> *adj;     // Pointer to an array containing
    // adjacency lists
public:
    Graph(int V);              // Constructor
    void addEdge(int v, int w);// function to add an edge to graph
    int longestPathLength();  // prints longest path of the tree
    pair<int, int> bfs(int u); // function returns maximum distant
    // node from u with its distance
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);    // Add w to v’s list.
    adj[w].push_back(v);    // Since the graph is undirected
}

//  method returns farthest node and its distance from node u
pair<int, int> Graph::bfs(int u)
{
    //  mark all distance with -1
    int dis[V];
    memset(dis, -1, sizeof(dis));
    
    queue<int> q;
    q.push(u);
    
    //  distance of u from u will be 0
    dis[u] = 0;
    
    while (!q.empty())
    {
        int t = q.front();       q.pop();
        
        //  loop for all adjacent nodes of node-t
        //for (auto it = adj[t].begin(); it != adj[t].end(); it++)
        for(int i = 0; i < adj[t].size(); i++)
        {
            int v = adj[t][i];
            
            // push node into queue only if
            // it is not visited already
            if (dis[v] == -1)
            {
                q.push(v);
                
                // make distance of v, one more
                // than distance of t
                dis[v] = dis[t] + 1;
            }
        }
    }
    
    int maxDis = 0;
    int nodeIdx;
    
    //  get farthest node distance and its index
    for (int i = 0; i < V; i++)
    {
        if (dis[i] > maxDis)
        {
            maxDis = dis[i];
            nodeIdx = i;
        }
    }
    return make_pair(nodeIdx, maxDis);
}

//  method prints longest path of given tree
int Graph::longestPathLength()
{
    pair<int, int> t1, t2;
    
    // first bfs to find one end point of
    // longest path
    t1 = bfs(0);
    
    //  second bfs to find actual longest path
    t2 = bfs(t1.first);
    
    return t2.second;
}

void build(int m,int n,Graph graph, int **tab){
    int v = tab[m][n];
    tab[m][n] = -1;
    if(tab[m][n-1] != -1){graph.addEdge(v,tab[m][n-1]);build(m,n-1,graph,tab);}
    if(tab[m][n+1] != -1){graph.addEdge(v,tab[m][n+1]);build(m,n+1,graph,tab);}
    if(tab[m-1][n] != -1){graph.addEdge(v, tab[m-1][n]);build(m-1,n,graph,tab);}
    if(tab[m+1][n] != -1){graph.addEdge(v, tab[m+1][n]);build(m+1,n,graph,tab);}
        return;
}

int main(){
    pair<int,int>start;
    int t,n,m,count;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> m;
        count = 0;
        int **tab = (int**)malloc(m*sizeof(int*));
        bool started = false;
        for(int m_ = 0; m_ < m; m_++){
            tab[m_] = (int*)malloc(n*sizeof(int));
            cin >> s;
            for(int n_ = 0; n_ < n; n_++){
                if(s[n_] == '.'){
                    tab[m_][n_] = count++;
                    if(!started){
                        start.first = m_;start.second = n_;
                        started = true;
                    }
                }
                else tab[m_][n_] = -1;
            }
        }
        if(count == 1) {cout <<"Maximum rope length is "<< 0 <<"."<< endl; continue;}
        Graph graph(count);
        build(start.first,start.second,graph,tab);
        cout <<"Maximum rope length is "<< graph.longestPathLength() <<"." << endl;
    }
    return 0;
}
