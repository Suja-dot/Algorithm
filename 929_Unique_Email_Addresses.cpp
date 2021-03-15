class Solution {
public:
    vector<string> split(string input, char delimiter){
        vector<string> answer;
        stringstream ss(input);
        string temp;

        while (getline(ss, temp, delimiter)) {
            answer.push_back(temp);
        }

        return answer;
    }
    int numUniqueEmails(vector<string>& emails) {
        int ans=0;
        set<string> names;
        // In local name
        //. -> integrate string
        //+ -> remove next string
        for(int i=0;i<emails.size();i++){
            vector<string> name = split(emails[i],'@');
            int plusIndex = name[0].find("+");
            if(plusIndex > 0) name[0] = name[0].substr(0,plusIndex);
            name[0].erase(remove(name[0].begin(),name[0].end(),'.'),name[0].end());
            names.insert(name[0]+"@"+name[1]);
            //cout << name[0] + "@" + name[1] << endl;
        }
        ans = names.size();
        return ans;
    }
};
