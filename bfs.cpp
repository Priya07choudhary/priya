#include <iostream>
#include <queue>
using namespace std;
#define N 5

void BFS(int graph[N][N], int start) {
    bool visited[N] = {false};  // Array to keep track of visited nodes
    queue<int> q;  // Queue for BFS

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout <<node << " ";

        // Visit all the adjacent nodes
        for (int i = 0; i < N; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
  
    int graph[N][N],i,j;
    cout<<"Enter the Adjacency Matrix";
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin>>graph[i][j];
        }
        cout<<"\n";
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        { cout<<graph[i][j]<<" ";
 
        }
        cout<<"\n";
    }
    int start = 0;  // Starting node for BFS
    cout << "BFS traversal starting from node " << start << ": ";
    BFS(graph, start);

    return 0;
}
