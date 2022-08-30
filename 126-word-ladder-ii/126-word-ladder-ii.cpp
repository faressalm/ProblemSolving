class Solution {
    bool distance(string &a, string &b) {
        if (a.length() != b.length()) {
            return false;
        }
        
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                count++;
            }
        }
        return count == 1;
    }
    
    void dfs(vector<vector<string>> &answer, vector<int> &sequence, string &beginWord,
             vector<string>& wordList, vector<int> &distance_arr, unordered_map<int, vector<int>> &graph) {
        int n = sequence.size();
        if (distance_arr[sequence[n-1]] == 1) {
            vector<string> sequence_str = {beginWord};
            for (int i = n-1; i >= 0; i--) {
                sequence_str.push_back(wordList[sequence[i]]);
            }
            answer.push_back(sequence_str);
            return;
        }
        for (auto neigh: graph[sequence[n-1]]) {
            if (distance_arr[neigh] == distance_arr[sequence[n-1]] - 1) {
                sequence.push_back(neigh);
                dfs(answer, sequence, beginWord, wordList, distance_arr, graph);
                sequence.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<int, vector<int>> graph;
        unordered_map<string, int> strmap;
        for (int i = 0; i < wordList.size(); i++) {
            strmap[wordList[i]] = i;
            for (int j = i+1; j < wordList.size(); j++) {
                if (distance(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        if (strmap.find(endWord) == strmap.end()) {
            return {};
        }
        
        int endIndex = strmap[endWord];
        queue<int> to_visit;
        vector<int> distance_arr(wordList.size(), 100000);
        unordered_set<int> visited;
        if (strmap.find(beginWord) == strmap.end()) {
            for (int i = 0; i < wordList.size(); i++) {
                if (distance(beginWord, wordList[i])) {
                    distance_arr[i] = 1;
                    to_visit.push(i);
                }
            }
        } else {
            distance_arr[strmap[beginWord]] = 0;
            to_visit.push(strmap[beginWord]);
        }
        
        while (to_visit.size() != 0) {
            int current = to_visit.front();
            to_visit.pop();
            
            if (current == endIndex) {
                break;
            }
            
            visited.insert(current);
            for (auto neigh: graph[current]) {
                if (visited.find(neigh) == visited.end() && distance_arr[current] + 1 < distance_arr[neigh]) {
                    distance_arr[neigh] = distance_arr[current] + 1;
                    to_visit.push(neigh);
                }
            }
        }
        
        vector<vector<string>> answer;
        vector<int> sequence;
        sequence.push_back(endIndex);
        dfs(answer, sequence, beginWord, wordList, distance_arr, graph);
        
        return answer;
    }
};