/*
    we will use the BFS approach of finding topological sort aka Kahn's Algorithm.
    This approach adds element to the queue iff indegree of some vertex is 0. But if the graph has cycle, 
    indegree of vertices inside the cycle won't be zero and thus the count of vertices we get in toposort 
    will be less than V. 
    
    Here is only the function of finding cycle in a Directed Acyclic Graph.
*/

bool isCyclic(int V, vector<int> adj[]) {
      vector<int> indegree(V);
      for (int i = 0; i < V; i++) {
          for (auto it: adj[i]) {
              indegree[it]++;
          }
      }

      queue<int> q;
      for (int i = 0; i < V; i++) {
          if (indegree[i] == 0) {
              q.push(i);
          }
      }
    
      int cnt = 0;
      //vector<int> toposort; //to get one of the toposort of the graph.
      while (!q.empty()) {
          int rem = q.front();
          q.pop();
          cnt++;
          //toposort.push_back(rem);
          for (auto it: adj[rem]) {
              indegree[it]--;
              if (indegree[it] == 0) {
                  q.push(it);
              }
          }
      }
      return cnt != V;
  }
