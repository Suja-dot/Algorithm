class Solution {
    private int[][] visit;
    private int m;
    private int n;
    private boolean isExist;
    private List<String> ans;
    
    public void findWord(char[][] board, String word, int r, int c, int depth){
        if(isExist) return ;
        if(r<0 || c<0 || r>=m || c>=n) return ;
        if(board[r][c] == '*') return ;
        if(depth == word.length()) return ;
        if(depth == word.length()-1 && board[r][c] == word.charAt(depth)){
            isExist = true;
            return ;
        }
        if(board[r][c] != word.charAt(depth)) return ;
        
        char ch = board[r][c];
        board[r][c] = '*';
        findWord(board,word,r-1,c,depth+1);
        findWord(board,word,r+1,c,depth+1);
        findWord(board,word,r,c-1,depth+1);
        findWord(board,word,r,c+1,depth+1);
        board[r][c] = ch;
    }
    
    public List<String> findWords(char[][] board, String[] words) {
        m = board.length;
        n = board[0].length;
        visit = new int[m][n];
        ans = new ArrayList<>();
        
        for(int i=0;i<words.length;i++){
            isExist = false;
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    findWord(board,words[i],j,k,0);
                    if(isExist){
                        ans.add(words[i]);
                        break;
                    }
                }
                if(isExist) break;
            }
        }
        return ans;
    }
}
