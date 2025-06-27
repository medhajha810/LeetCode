int numIslands(char** grid, int gridSize, int* gridColSize) {  
    if (gridSize == 0) {  
        return 0;  
    }  

    int rows = gridSize;  
    int cols = gridColSize[0];  
    int num_islands = 0;  

    void dfs(char** grid, int row, int col, int rows, int cols) {  
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') {  
            return;  
        }  

        grid[row][col] = '0'; 

        dfs(grid, row + 1, col, rows, cols);  
        dfs(grid, row - 1, col, rows, cols);   
        dfs(grid, row, col + 1, rows, cols);   
        dfs(grid, row, col - 1, rows, cols); 
    }  

    for (int i = 0; i < rows; i++) {  
        for (int j = 0; j < cols; j++) {  
            if (grid[i][j] == '1') {  
                num_islands++;  
                dfs(grid, i, j, rows, cols);  
            }  
        }  
    }  

    return num_islands;  
}  