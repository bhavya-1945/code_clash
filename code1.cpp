#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;


bool isOneLetterDifferent(const string& word1, const string& word2) {
    int diffCount = 0;
    for (int i = 0; i < word1.size(); ++i) {
        if (word1[i] != word2[i]) {
            ++diffCount;
            if (diffCount > 1) return false;
        }
    }
    return diffCount == 1;
}


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    sort(wordList.begin(), wordList.end());
    vector<string> filteredList;
    for (int i = 0; i < wordList.size(); ++i) {
        if (i % 2 == 0) filteredList.push_back(wordList[i]);
    }


    unordered_set<string> wordSet(filteredList.begin(), filteredList.end());
    

    if (wordSet.find(endWord) == wordSet.end()) return 0;


    queue<pair<string, int>> bfsQueue; 
    unordered_set<string> visited;
    
    
    bfsQueue.push({beginWord, 1});
    visited.insert(beginWord);

    
    while (!bfsQueue.empty()) {
        auto [currentWord, steps] = bfsQueue.front();
        bfsQueue.pop();

    
        for (const string& nextWord : filteredList) {
            if (visited.find(nextWord) == visited.end() && isOneLetterDifferent(currentWord, nextWord)) {
                if (nextWord == endWord) return steps + 1; // Found the endWord
                bfsQueue.push({nextWord, steps + 1});
                visited.insert(nextWord);
            }
        }
    }

    
    return 0;
}

int main() {
    int n;
    cin >> n;
    string beginWord, endWord;
    cin >> beginWord >> endWord;

    vector<string> wordList(n);
    for (int i = 0; i < n; ++i) {
        cin >> wordList[i];
    }

    int result = ladderLength(beginWord, endWord, wordList);
    cout << result << endl;

    return 0;
}