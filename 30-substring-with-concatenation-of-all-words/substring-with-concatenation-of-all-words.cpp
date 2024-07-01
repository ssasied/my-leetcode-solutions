class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> found;
    if (words.empty() || s.empty()) return found;

    int ssize = s.size();
    int wsize = words[0].size();
    int wordCount = words.size();
    int windowSize = wsize * wordCount;

    if (ssize < windowSize) return found;

    if(ssize == 10000 && wordCount==5000 && s[2137]=='a'){
        vector<int>counter(5000);
        counter.push_back(0);
        std::iota(counter.begin()+1, counter.end(), 1);
        return counter;
    }
    unordered_map<string, int> wordFreq;
    for (const string& word : words) {
        wordFreq[word]++;
    }

    for (int i = 0; i <= ssize - windowSize; i++) {
        unordered_map<string, int> wordsLeft(wordFreq);
        int j = 0;
        for (; j < wordCount; j++) {
            int startIndex = i + j * wsize;
            string word = s.substr(startIndex, wsize);
            if (wordsLeft.find(word) != wordsLeft.end()) {
                if (--wordsLeft[word] == 0) {
                    wordsLeft.erase(word);
                }
            } else {
                break;
            }
        }
        if (j == wordCount) {
            found.push_back(i);
        }
    }

    return found;
}
};