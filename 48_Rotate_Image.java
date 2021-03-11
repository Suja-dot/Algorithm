class Solution {
    public void rotateFrame(int[][] matrix, int start, int end){
        int temp = 0;   
        for (int i = start; i < end; i++) {
            temp = matrix[start][i];
            matrix[start][i] = matrix[end - (i - start)][start];
            matrix[end - (i - start)][start] = matrix[end][end - (i - start)];
            matrix[end][end - (i - start)] = matrix[i][end];
            matrix[i][end] = temp;
        }
    }
    
    public void rotate(int[][] matrix) {
        int start = 0;
        int end = matrix.length-1;
        while(start<end){
            rotateFrame(matrix,start,end);
            start++;
            end--;
        }
    }
}
