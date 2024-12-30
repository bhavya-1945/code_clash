#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;


bool isOneLetterDifferent(const string& word1, const string& word2) {
    int diffCount = 0;
    for (int i = 0; i < word1.size(); ++i) {
        if (word1[i] != word2[i]) {
            ++diffCount;
        }
        if (diffCount > 1) return false;
    }
    return diffCount == 1;
}

int minTransformations(const vector<string>& wordList, const string& beginWord, const string& endWord) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    

    if (dict.find(endWord) == dict.end()) return -1;
    

    queue<pair<string, int>> q;
    q.push({beginWord, 1});  
    unordered_set<string> visited;
    visited.insert(beginWord);
    
    while (!q.empty()) {
        auto [currentWord, steps] = q.front();
        q.pop();
        
        
        if (currentWord == endWord) {
            return steps;
        }
        
        
        for (const string& word : dict) {
            if (visited.find(word) == visited.end() && isOneLetterDifferent(currentWord, word)) {
                visited.insert(word);
                q.push({word, steps + 1});
            }
        }
    }
    
    
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m; 
    
    vector<string> wordList(n);
    for (int i = 0; i < n; ++i) {
        cin >> wordList[i];  
    }
    
    string beginWord, endWord;
    cin >> beginWord >> endWord;  
    
    
    int result = minTransformations(wordList, beginWord, endWord);
    cout << result << endl;  
    
    return 0;
}
