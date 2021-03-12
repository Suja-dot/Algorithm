class Solution {

    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int l, r;
        int[] ans = new int[queries.length];
        int[] xorTotal = new int[n+1];
        l = 0;
        r = 0;
        for(int i=1;i<=n;i++){
            xorTotal[i] = xorTotal[i-1] ^ arr[i-1];
        }
        for(int i=0;i<queries.length;i++){
            l = queries[i][0];
            r = queries[i][1];
            l++;
            r++;
            ans[i] = xorTotal[r]^xorTotal[l-1];
        }
        return ans;
    }
}
