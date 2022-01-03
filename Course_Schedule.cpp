/*
    link to the problem: https://leetcode.com/problems/course-schedule/
    Basically we have to find whether there is a cycle in DAG. If  yes then return false;
*/

// Approach 1: using DFS
class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<int>& visited, int node) {
        visited[node] = 1; // processing
        for (auto& it: adj[node]) {
            if (visited[it] == 1 or (visited[it] == 0 and dfs(adj, visited, it))) {
                return true;
            }
        }
        visited[node] = 2; //processed;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        //first make the graph
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < (int) pre.size(); i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        
        vector<int> visited(numCourses);
//       visited[i] == 0 means not visited
//       visited[i] == 1 means processing in this recursion call only
//       visited[i] == 2 means processed already in prev calls.
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(adj, visited, i)) 
                    return false;
            }
        }
        return true;
    }
};

// Approach 2: Using Topological sort
class Solution
{
    public:
    vector<int> getTopo(unordered_map<int,vector<int>>& graph, vector<int>& indegree)
    {
        queue<int>Q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                Q.push(i);
        }
        vector<int>topo;
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            topo.push_back(u);
            for(auto v:graph[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    Q.push(v);
            }
        }
        return topo;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int,vector<int>>graph;
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        vector<int>order=getTopo(graph,indegree);
        return order.size()==numCourses;
    }
};
