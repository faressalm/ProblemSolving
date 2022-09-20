class Solution {
public:
    bool canReach(string arr, int minJump, int maxJump) {
        queue<int> s;
        int size = arr.size();
        vector<bool> visited(size,false);
        s.push(0);
        visited[0] = true;
        int index;
        int last = 0;
        while(!s.empty()){
            index =s.front();s.pop();
            if(index!=size-1){
                for(int j=max(index+minJump,last);j<= min(index+maxJump,size-1);j++){
                    if(arr[j]=='0'&&!visited[j]){
                        s.push(j);
                        visited[j] = true;            
                    }
                }   
                last = max(last,min(index+maxJump,size-1));
            }else 
                return true;
        }
        return false;        
    }
};