class Solution {
public:
 
  int numIslands(vector<vector<char>>& grid) {
    //assign the number of rows to nr 
    int nr = grid.size();
    
    //This means if (!nr != 0) which we learned in descreet math means if (nr != 0)
    if (!nr) return 0;
    
    //assign the number of coulems to nc
    int nc = grid[0].size();

     //initilize the number of islands to 0
    int num_islands = 0;
    
    //loop through all of the rows
    for (int r = 0; r < nr; ++r) {
      //loop through all of the coulems
      for (int c = 0; c < nc; ++c) {
        
        //if we encounter a 1 then we 
        if (grid[r][c] == '1') {
          
          //add another island to our count
          ++num_islands;
          
          //mark it as zero just as we did with our DFS search
          grid[r][c] = '0'; // mark as visited
          
          //create a queue named neighbors that will hold a pair of integers
          queue<pair<int, int>> neighbors;
          
          //push the pair of row and coloum that the 1 was found at onto the queue
          neighbors.push({r, c});
          
          //while the queue neighbors is not empty...
          while (!neighbors.empty()) {
            //we assign the row and coloum to rc of type auto
            auto rc = neighbors.front();
            //then we remove it from the queue
            neighbors.pop();
            
            //we assign row and coloum we just popped from the queue to int row and col
            int row = rc.first, col = rc.second;
            
            //FOR ALL OF THE ROWS AND CLOUMS IN THE QUEUE WE TRIGGER A BFS SEARCH AND ASSIGN ANY 1'S WE FIND TO ZERO
            //*******************************************************************************************
            if (row - 1 >= 0 && grid[row-1][col] == '1') {
              neighbors.push({row-1, col}); grid[row-1][col] = '0';
            }
            if (row + 1 < nr && grid[row+1][col] == '1') {
              neighbors.push({row+1, col}); grid[row+1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1') {
              neighbors.push({row, col-1}); grid[row][col-1] = '0';
            }
            if (col + 1 < nc && grid[row][col+1] == '1') {
              neighbors.push({row, col+1}); grid[row][col+1] = '0';
            }
            //*********************************************************************************************
          }
        }
      }
    }

    return num_islands;
  }
};
