class Solution {
    int m,n;
    private boolean ans = false;
    
    private void findString(char[][] board, String word, int r, int c, int depth){
        char ch;
        if(ans) return ;
        if(r<0 || c<0 || r>=m || c>=n) return ;       
        if(board[r][c]=='*') return ;
        if(word.charAt(depth) == board[r][c] && depth == word.length()-1) {
            ans = true;
            return ;
        }
        if(board[r][c] != word.charAt(depth)) return;
        
        ch = board[r][c];
        board[r][c] = '*';
        findString(board,word,r-1,c,depth+1);
        findString(board,word,r+1,c,depth+1);
        findString(board,word,r,c-1,depth+1);
        findString(board,word,r,c+1,depth+1);
        board[r][c] = ch;
    }
    
    public boolean exist(char[][] board, String word) {
        this.m = board.length;
        this.n = board[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                this.findString(board,word,i,j,0);
                if(ans) return ans;
            }
        } 
        return ans;
    }
}
