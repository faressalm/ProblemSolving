class RandomizedSet {
private: 
    unordered_map<int,int> s;
    vector<int> indeces;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end())
            return false;
        indeces.push_back(val);
        s[val] = indeces.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end())
            return false;
        s[indeces[indeces.size()-1]] = s[val];
        swap(indeces[s[val]],indeces[indeces.size()-1]);
        indeces.pop_back();
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand()%indeces.size();
        return indeces[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */