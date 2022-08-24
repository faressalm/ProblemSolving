class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        wordList.push_back(beginWord);
        unordered_map<string,vector<string>> patterns;
        for(auto & word:wordList)
            for(int i=0;i<word.size();i++)
            {
                string pattern = word;
                pattern[i]='*';
                patterns[pattern].push_back(word);
            }
        unordered_map<string,vector<string>> edges;
        unordered_set<string> visited;
        for(auto &pattern:patterns)
            for(int i=0;i<pattern.second.size();i++)
                for(int j=i+1;j<pattern.second.size();j++){
                    edges[pattern.second[i]].push_back(pattern.second[j]);
                    edges[pattern.second[j]].push_back(pattern.second[i]);
                }
        queue<string> q;
        int pathLen = 1;
        q.push(beginWord);
        int size=0;
        string top;
        while(!q.empty()){
            size = q.size();
            for(int i=0;i<size;i++){
                top = q.front();q.pop();
                if(top == endWord)
                    return pathLen;
                for(auto &edge: edges[top])
                    if(visited.find(edge) == visited.end()){
                        q.push(edge);
                        visited.insert(edge);
                    }
            }
            pathLen++;
        }
        return 0;
    }
};