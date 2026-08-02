class Solution {
public:
    bool isCycleDFS(int src, 
                    vector<bool>& vis, 
                    vector<bool>& recPath,
                    vector<vector<int>>& edges,
                    vector<int>& order) {

        vis[src] = true;
        recPath[src] = true;

        // Traverse all edges
        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            // Edge: u -> v
            if (u == src) {

                if (!vis[v]) {
                    if (isCycleDFS(v, vis, recPath, edges, order)) {
                        return true;
                    }
                }
                else if (recPath[v]) {
                    // Cycle detected
                    return true;
                }
            }
        }

        // Current node is finished
        recPath[src] = false;

        // Add after processing all neighbors
        order.push_back(src);

        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {

        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        vector<int> order;

        // Check every disconnected component
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {

                if (isCycleDFS(i, vis, recPath, edges, order)) {
                    return {};
                }
            }
        }

        // DFS gives reverse topological order
        reverse(order.begin(), order.end());

        return order;
    }
};