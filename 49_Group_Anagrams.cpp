class Solution {
public:  
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> map;
        string key;
        
        for(int i=0;i<strs.size();i++){
            key = strs[i];
            sort(key.begin(),key.end());
            auto findRes = map.find(key);
            if(findRes != map.end()){ // already exist
                findRes->second.push_back(strs[i]);
            }else{
                map[key].push_back(strs[i]);
            }
        }
        for(auto i=map.begin();i!=map.end();i++){
            ans.push_back(i->second);
        }
        return ans;
    }
};
