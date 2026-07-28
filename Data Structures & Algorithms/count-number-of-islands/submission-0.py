class Solution:
    def numIslands(self, grid: List[List[str]]) -> int: 
        # keep track of what was visited
        visited = set()
        # island count tracker
        islands = 0
        # double for loop to iterate on grid
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                cell = grid[i][j]
                coords = (i,j)

                # check if cell is unvisited and is land
                if cell == "1" and coords not in visited:
                    # if so, call dfs
                    self.dfs(grid, coords,visited)
                    # increment number of islands
                    islands +=1

        # return number of islands
        return islands

    # DFS
    def dfs(self, grid, coords, visited):
        # check if the cell has been visited and is in bounds and is land (is safe)
        if self.isSafe(grid, coords, visited):
            # if is safe, mark cell as visited
            visited.add(coords)

        # check surrounding neighbors (4 possible directions)
        dr = [ -1, 1, 0,0]
        dc = [0, 0, -1, 1]

        row, col = coords

        for k in range(4):
            nr = row + dr[k]
            nc = col + dc[k]
            neighbor = (nr,nc)
            # if neighbor is safe and no visited call dfs on neighbor
            if self.isSafe(grid, neighbor, visited):
                self.dfs(grid, neighbor, visited)

     

    def isSafe(self, grid, coords, visited):
        # get bounds of grid
        row_bound = len(grid)
        col_bound = len(grid[0])
        row, column = coords

        # in bounds, not visited, and is land
        return (0 <= row < row_bound and 0 <= column < col_bound and grid[row][column] == "1" and (row,column) not in visited)


