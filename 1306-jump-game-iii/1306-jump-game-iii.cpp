class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        stack<int> s;
        int size = arr.size();
        vector<bool> visited(size,false);
        s.push(start);
        visited[start] = true;
        int index;
        while(!s.empty()){
            index =s.top();s.pop();
            if(arr[index]!=0){
                if(arr[index]+index<size&&!visited[arr[index]+index])
                {
                    s.push(arr[index]+index);
                    visited[arr[index]+index] = true;
                }
                if(index-arr[index]>=0&&!visited[index-arr[index]]){
                    s.push(index-arr[index]);
                    visited[index-arr[index]] = true;    
                }
            }else 
                return true;
        }
        return false;
    }
};