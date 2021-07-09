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
4. We can use unordered_map<int, vector<int>> to represent the graph.

**Dijkstra's algorithm:**
is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks.
```
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using ip = pair<int, int>;
        vector<vector<ip>> adj(n + 1);
        for (auto& t : times)
            adj[t[0]].push_back({t[1], t[2]});
        priority_queue<ip> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> vis(n + 1, false);
        pq.push({0, k});
        dist[k] = 0;
        vis[k] = true;
        while (!pq.empty()) {
            auto [n_cost, node] = pq.top();
            pq.pop();
            if (n_cost > dist[node]) continue;
            for (auto& [next, cost] : adj[node]) {
                if (vis[next] == true) continue;
                if (dist[next] > dist[node] + cost) {
                    dist[next] = dist[node] + cost;
                    pq.push({dist[next], next});
                }
            }
        }
        int res = 0;
        for_each(dist.begin() + 1, dist.end(), [&](int d) {
            res = max(res, d);
        });
        return res == INT_MAX ? -1 : res;
    }
};
```
Notes:
1. We will have a set to track visited nodes.
2. We will create a distance array to track the distance to each node. Initial node will have 0, others maximum.
3. We will use min priority_queue to get the node with the minimum distance from current node.
4. If we are only interested in shortes distance till some END node, we can terminate the search earlier: if (node == dst) return cost;
5. If we already find a better path we shouldnt explore it further: if (dist[node] < stops) continue;

**Union Find:**
union–find data structure or disjoint-set data structure or merge–find set, is a data structure that stores a collection of disjoint (non-overlapping) sets. Equivalently, it stores a partition of a set into disjoint subsets. It provides operations for adding new sets, merging sets
(replacing them by their union), and finding a representative member of a set.
Helps to find number of connected components, and can help to find MST.

```
class UnionFind {
    public:
    UnionFind(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int Find(int x) {
        int temp = x;
        while (temp != parent[temp]) {
            temp = parent[temp];
        }
        while (x != temp) {
            int next = parent[x];
            parent[x] = temp;
            x = next;
        }
        return x;
    }

    void Union(int x, int y) {
        int xx = Find(x);
        int yy = Find(y);
        if (xx != yy) {
            parent[xx] = yy;
        }
    }

    private:
           vector<int> parent;
};
```
Notes:
    1. We can use vector<int> to hold the set of nodes or unordered_map<int, int> if we don't know the amount of nodes.
    2. If the parent[id] == id, we know that id is the root node.
    3. The data structure using two methods Union() - union to nodes/components, and Find() - find the root node.

**Minimum Spanning Tree:**
A minimum spanning tree (MST) is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices
together, without any cycles and with the minimum possible total edge weight.

```
    sort(connections.begin(), connections.end(), [](const auto& lhs, const auto& rhs) {
        return lhs[2] < rhs[2];
    });
    int res = 0, count = 0;
    UnionFind uf(n + 1);
    for (auto& c : connections) {
        int x = uf.Find(c[0]);
        int y = uf.Find(c[1]);
        if (x != y) {
            uf.Union(x, y);
            res += c[2];
            count++;
        }
    }
    return count == n - 1 ? res : -1;
```
Notes:
    1. One of the implementaion of MST algorithm use Union Find algorithm (Kruskal's Algorithm).
    2. We need to sort elements by the weight before appying the algorithm, or we can use min priority_queue.

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
    
## Connected components problems
<details><summary>Number of Provinces: https://leetcode.com/problems/number-of-provinces/</summary><p>
</p></details>
<details><summary>Number of Connected Components in an Undirected Graph: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/</summary><p>
</p></details>
<details><summary>Number of Operations to Make Network Connected: https://leetcode.com/problems/number-of-operations-to-make-network-connected/</summary><p>
</p></details>
<details><summary>Accounts Merge: https://leetcode.com/problems/accounts-merge/</summary><p>
</p></details>
<details><summary>Critical Connections in a Network: https://leetcode.com/problems/critical-connections-in-a-network/</summary><p>
</p></details>

## Dijkstra's problems
<details><summary>Path With Maximum Minimum Valued: https://leetcode.com/problems/path-with-maximum-minimum-value/</summary><p>
</p></details>
<details><summary>Network delay time: https://leetcode.com/problems/network-delay-time/</summary><p>
</p></details>
<details><summary>Path with Maximum Probability: https://leetcode.com/problems/path-with-maximum-probability/</summary><p>
</p></details>
<details><summary>Path With Minimum Effort: https://leetcode.com/problems/path-with-minimum-effort/submissions/</summary><p>
</p></details>
<details><summary>Cheapest Flights Within K Stops: https://leetcode.com/problems/cheapest-flights-within-k-stops/</summary><p>
</p></details>

## Union Find problems
<details><summary>Number of Islands: https://leetcode.com/problems/number-of-islands/submissions/</summary><p>
</p></details>
<details><summary>Largest Component Size by Common Factor: https://leetcode.com/problems/largest-component-size-by-common-factor/submissions/</summary><p>
</p></details>
<details><summary>Most Stones Removed with Same Row or Column: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/</summary><p>
</p></details>
<details><summary>Number of Connected Components in an Undirected Graph: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/</summary><p>
</p></details>

## Minimum Spanning Tree
<details><summary>Connecting Cities With Minimum Cost: https://leetcode.com/problems/connecting-cities-with-minimum-cost/</summary><p>
</p></details>
<details><summary>Min Cost to Connect All Points: https://leetcode.com/problems/min-cost-to-connect-all-points/</summary><p>
</p></details>

