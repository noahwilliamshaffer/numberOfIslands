public int numIslands(char[][] grid) {

//initilize integer isands to zero
    int islands = 0;
    
    //if the grid is not at the end, and the grid[i] and grid[i][j] are not zero
    if (grid != null && grid.length != 0 && grid[0].length != 0) {
    
        //loop from the beggining of the grid[i] to the end
        for (int i = 0; i < grid.length; i++) {
        
            //loop from grid[i][j] from beggining to the end
            for (int j = 0; j < grid[0].length; j++) {
                
                //finding a 1 triggers DFS 
                if (grid[i][j] == '1') {
                
                    //send the grid cordininates to a private DFS function
                    dfs(grid, i, j);
                    
                    //Entering this if statement adds an island to the list 
                    islands++;
                }
            }
        }
    }
    return islands;
}

//Private Helper Function passed in a character matrix and i and j 
private void dfs(char[][] grid, int x, int y) {
   
    if (x < 0 || grid.length <= x || y < 0 || grid[0].length <= y || grid[x][y] != '1') {
        return;
    }
    
    //we set this spot int the grid to x so it doesn't get called again
    grid[x][y] = 'x';
    
    //This is where we recursivley call DFS 
    //********************************
    dfs(grid, x + 1, y);
    dfs(grid, x - 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1);
    //*********************************
}
