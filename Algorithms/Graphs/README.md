# Graph problems

**Description:**
In computer science, graphs are used to represent networks of communication, data organization, computational devices,
the flow of computation, etc. For instance, the link structure of a website can be represented by a directed graph,
in which the vertices represent web pages and directed edges represent links from one page to another. 

# Common algorithms
**BFS:**
Breadth-first search (BFS) is an algorithm for searching a tree data structure for a node that satisfies a given property.
It starts at the tree root and explores all nodes at the present depth prior to moving on to the nodes at the next depth level.
Extra memory, usually a queue, is needed to keep track of the child nodes that were encountered but not yet explored.

```
double bfs(unordered_map<string, vector<ip>>& adj, vector<string>& query) {
    unordered_set<string> visited;
    string start = query[0];
    string end = query[1];
    queue<ip> q;
    q.push({start, 1.0});
    visited.insert(start);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [node, cost] = q.front(); q.pop();
            if (!adj.count(node)) continue;
            if (node == end) return cost;
            for (auto& a : adj[node]) {
                if (!visited.count(a.first)) {
                    q.push({a.first, cost * a.second});
                    visited.insert(node);
                }
            }
        }
    }
    return -1.0;
}
```
Notes:
1. Algorithm uses queue for implementation.
2. It checks whether a vertex has been explored before enqueueing the vertex.
3. We can track if the node was already explored by modifying the original matrix.
4. BFS algorithm can be instructed with addiitional array dist which can help to
   track the parent node of the next node. This will help to reconstruct the path
   by looping backward from end node.

**DFS:**
is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node
(selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along
each branch before backtracking.
```
void dfs(unordered_map<int, vector<int>>& graph, int node, unordered_set<int>& visited) {
    visited.insert(node);
    for (auto& n : graph[node]) {
        if (!visited.count(n)) {
            dfs(graph, n, visited);
        }
    }
}
// Find connected components.
for (int i = 0; i < n; i++) {
    if (!visited.count(i)) {
        dfs(graph, i, visited);
    }
}
```
Notes:
1. Algorithm usually use recursion implementaiton.
2. We mark the node as visited and will keep explore it's neighbors if there are not yet explored.
3. DFS can be useful to find connected components. We can iterate through the nodes and call dfs() 
   to find all nodes which belongs to component. 


## BFS problems
<details><summary>Flood Fill: https://leetcode.com/problems/flood-fill/</summary><p>
</p></details>
<details><summary>Number of Islands: https://leetcode.com/problems/number-of-islands/</summary><p>
</p></details>
<details><summary>Word Ladder I: https://leetcode.com/problems/word-ladder/</summary><p>
</p></details>
<details><summary>Word Ladder II: https://leetcode.com/problems/word-ladder-ii/</summary><p>
</p></details>
<details><summary>Evaluate Division: https://leetcode.com/problems/evaluate-division/</summary><p>
</p></details>
<details><summary>Get Watched Videos by Your Friends: https://leetcode.com/problems/get-watched-videos-by-your-friends/</summary><p>
</p></details>
<details><summary>Cut Off Trees for Golf Event: https://leetcode.com/problems/cut-off-trees-for-golf-event/</summary><p>
</p></details>

## DFS problems
<details><summary>Number of Islands: https://leetcode.com/problems/number-of-islands/</summary><p>
</p></details>
<details><summary>Flood Fill: https://leetcode.com/problems/flood-fill/</summary><p>
</p></details>
<details><summary>Longest Increasing Path in a Matrix: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/</summary><p>
</p></details>
<details><summary>Evaluate Division: https://leetcode.com/problems/evaluate-division/</summary><p>
</p></details>
<details><summary>Robot Room Cleaner: https://leetcode.com/problems/robot-room-cleaner/</summary><p>
</p></details>
<details><summary>Most Stones Removed with Same Row or Column: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/</summary><p>
</p></details>
<details><summary>Reconstruct Itinerary: https://leetcode.com/problems/reconstruct-itinerary/</summary><p>
</p></details>
<details><summary>Tree Diameter: https://leetcode.com/problems/tree-diameter/</summary><p>
</p></details>
<details><summary>Accounts Merge: https://leetcode.com/problems/accounts-merge/</summary><p>
</p></details>







