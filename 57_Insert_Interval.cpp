class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int> prev;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        prev = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(prev[1] < intervals[i][0]){ // () []
                ans.push_back(prev);
                prev = intervals[i];
            }else if(prev[1]==intervals[i][0]){ //( )[ ]
                prev[1] = intervals[i][1];
            }else{ //( [ ) ] || ( [ ] )
                if(prev[1]<intervals[i][1]) prev[1] = intervals[i][1];
            } 
        }
        ans.push_back(prev);
        return ans;
    }
};
