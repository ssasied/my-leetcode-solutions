class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //i didnt know u can iterate through an unrdered map. neat!
        unordered_map<string,vector<string>>words;
        for(string word : strs){
            string  hword=word;
            sort(hword.begin(),hword.end());
            words[hword].push_back(word);
        }
        vector<vector<string>>res;
        for(auto hword:words){
            res.push_back(hword.second);
        }
        return res;
    }
};