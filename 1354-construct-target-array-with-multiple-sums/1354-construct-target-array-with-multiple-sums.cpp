class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum= 0;
        priority_queue<int> q;
        for(auto t:target){
            if(t!=1){
                q.push(t);
            }
            sum+=t;
        }
        int next=1;
        while(!q.empty()){
            int largest = q.top();q.pop();
            if(sum - largest >= largest || sum - largest == 0)
                return false;
            int rest = sum - largest;
            int frac =(largest/rest);
            // cout<<"sum: "<<sum<<" frac: "<<frac<<" rest:"<<rest<<" largest: "<<largest<<endl;
            if(rest==1)
                return true;
            largest -=frac * rest;
            sum -= frac * rest ;
            if(largest<1||frac==0)
                return false;
            if(largest!=1)
               q.push(largest);
        }
        return true;
    }
};