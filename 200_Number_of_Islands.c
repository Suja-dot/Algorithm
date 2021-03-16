void findIslands(char** grid, int gridSize, int* gridColSize, int r, int c){
    grid[r][c] = '0';
    if(r-1>=0 && grid[r-1][c] == '1') findIslands(grid,gridSize,gridColSize,r-1,c);
    if(r+1<gridSize && grid[r+1][c] == '1') findIslands(grid,gridSize,gridColSize,r+1,c);
    if(c-1>=0 && grid[r][c-1] == '1') findIslands(grid,gridSize,gridColSize,r,c-1);
    if(c+1<*gridColSize && grid[r][c+1] == '1') findIslands(grid,gridSize,gridColSize,r,c+1);
    return ;
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int ans = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            if(grid[i][j]=='1') {
                findIslands(grid,gridSize,gridColSize,i,j);
                ans++;
            }
        }
    }
    return ans;
}
