vector <int> Kahn (vector <int> *Graph, int *indegree) {
        vector <int> res;
        priority_queue <int, vector <int>, greater <int>> Q;
        for (int i = 1; i <= n; ++i)
                if (!indegree[i])
                        Q.push (i);

        bool visited[n + 2] = {0};
        while (!Q.empty()) {
                int v = Q.top(), s = Graph[v].size();
                Q.pop();
                res.push_back (v);
                visited[v] = true;
                for (int i = 0; i < s; ++i)
                        if (!visited[Graph[v][i]])
                                if (!(--indegree[Graph[v][i]]))
                                        Q.push (Graph[v][i]);
        }
        return res;
}
