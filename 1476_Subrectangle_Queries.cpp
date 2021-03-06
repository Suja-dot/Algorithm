class SubrectangleQueries {
private:
    vector<vector<int>> rec;   
    
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                //printf("Replace value (%d, %d) %d -> %d\n",i,j,rec[i][j],newValue);
                rec[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        /*
        for(int i=0;i<rec.size();i++){
            for(int j=0;j<rec[i].size();j++) printf("%d ",rec[i][j]);
            printf("\n");
        }
        printf("getValue (%d, %d) : %d\n",row,col,rec[row][col]);*/
        return rec[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
