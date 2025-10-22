class Solution:
    def isSafe(self, node, color, graph, v, col):
        # Check adjacent vertices only
        for k in range(v):
            if graph[node][k] == 1 and color[k] == col:
                return False
        return True
    
    def solve(self, node, color, v, graph, m):
        if node == v:
            return True
        
        for i in range(1, m + 1):
            if self.isSafe(node, color, graph, v, i):
                color[node] = i
                if self.solve(node + 1, color, v, graph, m):
                    return True
                color[node] = 0
        
        return False
    
    def graphColoring(self, v, edges, m):
        # Convert edge list to adjacency matrix
        graph = [[0] * v for _ in range(v)]
        
        for edge in edges:
            u, w = edge[0], edge[1]
            graph[u][w] = 1
            graph[w][u] = 1  # Undirected graph
        
        color = [0] * v
        return self.solve(0, color, v, graph, m)
