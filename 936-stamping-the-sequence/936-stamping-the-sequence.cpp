class Solution {
private: bool check(string stamp,string trg){
    bool works= false;
    for(int i=0;i<stamp.size();i++)
        if(stamp[i]==trg[i])
            works =true;
        else if (trg[i]=='?')
            continue; // due to special case all are ?
        else return false;
    return works;
}
      void updateTarget(string &target,int start,int m){
          for(int i=start;i<start+m;i++)
              target[i] = '?';
      }
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n,m;
        n= target.size();
        m= stamp.size();
        string dis(n,'?');
        vector<int> sol;
        int maxMoves = n*10;
        int preMove;
        while(maxMoves){
            preMove = maxMoves;
            for(int i=0;i<n-m+1;i++){
                if(check(stamp,target.substr(i,m)))
                {
                    updateTarget(target,i,m);
                    maxMoves--;
                    sol.push_back(i);
                    if(target==dis){
                       reverse(sol.begin(),sol.end());
                       return sol;
                    }

                }
                
            }
            if(preMove == maxMoves)
                break;

        }
        return {};
    }
};