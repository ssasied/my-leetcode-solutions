class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<string>anagrams;
        unordered_map<string,vector<string>>words;
        for(string word : strs){
            string  hword=word;
            sort(hword.begin(),hword.end());
            anagrams.insert(hword);
            words[hword].push_back(word);
        }
        vector<vector<string>>res;
        for(string hword:anagrams){
            res.push_back(words[hword]);
        }
        return res;
    }
};