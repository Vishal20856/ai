#include<bits/stdc++.h>
using namespace std;

class DSU{
   int* parent;
   int* rank;
public:
   DSU(int n){
      parent=new int[n];
      rank=new int[n];
      for(int i=0;i<n;i++){
         parent[i]=-1;
         rank[i]=1;
      }
   }
   int find(int i){
      if(parent[i]==-1)
         return i;
      return parent[i] = find(parent[i]);
   }
   void unite(int x, int y){
      int s1=find(x);
      int s2=find(y);
      if(s1!=s2){
         if(rank[s1]<rank[s2]){
            parent[s1]=s2;
         }
         else if(rank[s1]>rank[s2]){
            parent[s2]=s1;
         }
         else{
            parent[s2]=s1;
            rank[s1]+=1;
         }
      }
   }
};


//SELECTION SORT
void selection_sort(){
   cout<<"Enter size of Array : ";
   int n;cin>>n;
   cout<<"Enter the Elements of Array : ";
   vector<int> v(n);
   for(auto &x:v) cin>>x;
   for(int i=0;i<n-1;i++){
      int mx=i;
      for(int j=i;j<n;j++){
         if(v[j]<v[mx]) mx=j;
      }
      swap(v[i],v[mx]);
   }
   cout<<endl;
   cout<<"Array after Selection Sorting is : "<<endl;
   for(auto &x:v) cout<<x<<" ";
   cout<<endl;
}


//PRIM'S ALGO
int minKey(int key[], bool mstSet[],int V){
   int min=INT_MAX,min_index;
   for(int v=0;v<V;v++)
      if(mstSet[v]==false && key[v]<min)
         min=key[v],min_index=v;
   return min_index;
}

void primMST(){
   cout<<"Enter number of Vertices : ";
   int V;cin>>V;
   cout<<"Enter number of Edges : ";
   int E;cin>>E;
   vector<vector<int>> graph(V,vector<int> (V,0));
   cout<<"\nEnter v1 -> v2 with weight : ";
   cout<<endl;
   vector<vector<int>> kgraph;
   for(int i=0;i<E;i++){
      int x,y,z;
      cin>>x>>y>>z;
      graph[x][y]=z;
      graph[y][x]=z;
   }
   int parent[V];
   int key[V];
   bool mstSet[V];
   for (int i = 0; i < V; i++) key[i] = INT_MAX, mstSet[i] = false;
   key[0] = 0;
   parent[0] = -1;
   for (int count = 0; count < V - 1; count++) {
      int u = minKey(key, mstSet,V);
      mstSet[u] = true;
      for (int v = 0; v < V; v++)
         if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            parent[v] = u, key[v] = graph[u][v];
   }
   cout << "\nEdge \tWeight\n";
   for (int i = 1; i < V; i++)
      cout << parent[i] << " - " << i << " \t"<< graph[i][parent[i]] << " \n";
}


//DIJKSTRA'S ALGO
int minDistance(int dist[], bool sptSet[],int V){
   int min=INT_MAX,min_index;
   for(int v=0;v<V;v++)
      if(sptSet[v]==false && dist[v]<=min)
         min=dist[v],min_index=v;
   return min_index;
}

void dijkstra(){
   cout<<"Enter number of Vertices : ";
   int V;cin>>V;
   cout<<"Enter number of Edges : ";
   int E;cin>>E;
   vector<vector<int>> graph(V,vector<int> (V,0));
   cout<<"\nEnter v1 -> v2 with weight : ";
   cout<<endl;
   vector<vector<int>> kgraph;
   for(int i=0;i<E;i++){
      int x,y,z;
      cin>>x>>y>>z;
      graph[x][y]=z;
      graph[y][x]=z;
   }
   int src=0;
   int dist[V];
   bool sptSet[V];
   for (int i = 0; i < V; i++) dist[i] = INT_MAX, sptSet[i] = false;
   dist[src] = 0;
   for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, sptSet,V);
      sptSet[u] = true;
      for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
   }
   cout << "\nVertex \t Distance from Source" << endl;
   for (int i = 0; i < V; i++)
      cout << i << " \t" << dist[i] << endl;
}


//KRUSKAL'S ALGO
void kruskal_MST(){
   cout<<"Enter number of Vertices : ";
   int V;cin>>V;
   cout<<"Enter number of Edges : ";
   int E;cin>>E;
   vector<vector<int>> graph(V,vector<int> (V,0));
   cout<<"\nEnter v1 -> v2 with weight : ";
   cout<<endl;
   vector<vector<int>> kgraph;
   for(int i=0;i<E;i++){
      int x,y,z;
      cin>>x>>y>>z;
      kgraph.push_back({z,x,y});
   }
   sort(kgraph.begin(), kgraph.end());
   DSU ss(V);
   int ans = 0;
   cout << "\nFollowing are the edges in the constructed MST"<< endl;
   for (auto edge : kgraph) {
      int w = edge[0];
      int x = edge[1];
      int y = edge[2];
      if (ss.find(x) != ss.find(y)) {
         ss.unite(x, y);
         ans += w;
         cout << x << " -- " << y << " == " << w<< endl;
      }
   }
   cout << "\nMinimum Cost Spanning Tree: " << ans<<"\n\n";
}


signed main(){
   while(1){
      cout << "\nMENU\n";
      cout << "1. Selection Sort\n";
      cout << "2. Prim's Minimal Spanning Tree Algorithm\n";
      cout << "3. Kruskal's Minimal Spanning Tree Algorithm\n";
      cout << "4. Dijkstra's Minimal Spanning Tree Algorithm\n";
      cout << "5. Exit\n";
      cout << "\nEnter your choice: ";
      int n;cin>>n;
      cout<<endl;
      if(n==1) selection_sort();
      else if(n==2) primMST();
      else if(n==3) kruskal_MST();
      else if(n==4) dijkstra();
      else break;
   }
}


/* 
ARRAY :

5
64 25 12 22 11
_________________________________
GRAPH :

9
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7


4
5
0 1 10
1 3 15
2 3 4
2 0 6
0 3 5
_________________________________
*/