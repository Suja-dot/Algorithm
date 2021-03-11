struct Position{
    int row, col;
};

class Solution {
private:
    vector<Position> posList[2];    
    vector<vector<int>> ans;
    vector<vector<bool>> visit;
public:
    void initResult(int row, int col){
        for(int i=0;i<row;i++){
            vector<int> ans_col;
            vector<bool> visit_col;
            for(int j=0;j<col;j++) {ans_col.push_back(100000); visit_col.push_back(false);}
            ans.push_back(ans_col);
            visit.push_back(visit_col);
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int idx = 0;
        Position matrix_size,pos;
        matrix_size.row = matrix.size();
        matrix_size.col = matrix[0].size();
        for(int i=0;i<matrix_size.row;i++){
            for(int j=0;j<matrix_size.col;j++){
                if(matrix[i][j]==0){
                    pos.row = i;
                    pos.col = j;
                    posList[idx].push_back(pos);
                }
            }
        }
        //printf("First position list set Success\n");
        initResult(matrix_size.row,matrix_size.col);
        //printf("Init Success\n");
        while(1){
            //printf("%d-th position list set Start : %d\n",idx,posList[idx%2].size());
            if(posList[idx%2].size() == 0) break;
            Position current_pos,next_pos;
            for(int i=0;i<posList[idx%2].size();i++){
                current_pos = posList[idx%2][i];
                visit[current_pos.row][current_pos.col] = true;
                ans[current_pos.row][current_pos.col] = min(ans[current_pos.row][current_pos.col],idx);
                if(current_pos.row-1 >= 0 && visit[current_pos.row-1][current_pos.col] == false) { next_pos.row = current_pos.row-1; next_pos.col = current_pos.col; posList[(idx+1)%2].push_back(next_pos); }
                if(current_pos.col-1 >= 0 && visit[current_pos.row][current_pos.col-1] == false) { next_pos.row = current_pos.row; next_pos.col = current_pos.col-1; posList[(idx+1)%2].push_back(next_pos); }
                if(current_pos.row+1 < matrix_size.row && visit[current_pos.row+1][current_pos.col] == false) { next_pos.row = current_pos.row+1; next_pos.col = current_pos.col; posList[(idx+1)%2].push_back(next_pos); }
                if(current_pos.col+1 < matrix_size.col && visit[current_pos.row][current_pos.col+1] == false) { next_pos.row = current_pos.row; next_pos.col = current_pos.col+1; posList[(idx+1)%2].push_back(next_pos); }
            }
            posList[idx%2].resize(0);
            idx++;
        }
        return ans;
    }
};
