class Solution:

    # Function to check if the cell is within maze and valid to move
    def isSafe(self, x, y, n, maze, visited):
        return (0 <= x < n and 0 <= y < n and 
                maze[x][y] == 1 and visited[x][y] == 0)

    def solve(self, x, y, n, maze, visited, path, res):
        # Direction arrays
        di = [1, 0, 0, -1]      # Down, Left, Right, Up (row changes)
        dj = [0, -1, 1, 0]      # Down, Left, Right, Up (column changes)
        directions = "DLRU"
        
        # Base case: reached destination
        if x == n - 1 and y == n - 1:
            res.append(path)
            return
        
        # Mark as visited
        visited[x][y] = 1
        
        # Try all 4 directions
        for k in range(4):
            newX = x + di[k]
            newY = y + dj[k]
            
            if self.isSafe(newX, newY, n, maze, visited):
                self.solve(newX, newY, n, maze, visited, path + directions[k], res)
                
    #     # Try moving Down
    #     if self.isSafe(x + 1, y, n, maze, visited):
    #         self.solve(x + 1, y, n, maze, visited, path + "D", res)
    #     # Try moving Left
    #     if self.isSafe(x, y - 1, n, maze, visited):
    #         self.solve(x, y - 1, n, maze, visited, path + "L", res)
    #     # Try moving Right
    #     if self.isSafe(x, y + 1, n, maze, visited):
    #         self.solve(x, y + 1, n, maze, visited, path + "R", res)
    #     # Try moving Up
    #     if self.isSafe(x - 1, y, n, maze, visited):
    #         self.solve(x - 1, y, n, maze, visited, path + "U", res)
        
        # Backtrack
        visited[x][y] = 0
        
    def ratInMaze(self, maze):
        # code here
        res = []
        n = len(maze)
        vis = [[0]*n for _ in range(n)]
        if maze[0][0] == 1:
            self.solve(0, 0, n, maze, vis, "", res)
        return res
        