class Solution {
public:        
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> prev;
        sort(intervals.begin(),intervals.end());
        
        prev=intervals[0];
        for(int i=1;i<intervals.size();i++){
            vector<int> cur = intervals[i];
            if(prev[1] < cur[0]){ // [ ] ( )
                ans.push_back(prev);
                prev[0] = cur[0];
                prev[1] = cur[1];          
            }else if(prev[1] == cur[0]){ //[ ]( )
                prev[1] = cur[1];
            }else{
                if(prev[1] < cur[1]) prev[1] = cur[1]; // [( ] ) 
                //else // [ () ]
            }
        }
        ans.push_back(prev);
        return ans;
    }
};
