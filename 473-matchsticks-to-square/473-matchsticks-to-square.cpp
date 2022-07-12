class Solution {
private: 
    int temp(vector<int> &sides,vector<int>&matchsticks,int next,int sideLength){
        if(next==matchsticks.size())
           return checkSides(sides,sideLength);
        bool square =false;
        for(int i=0;i<sides.size();i++){
            sides[i]+=matchsticks[next];
            if(sides[i]>sideLength)
                square= square || false;
            else{
                square = square || temp(sides,matchsticks,next+1,sideLength);
            }
            sides[i]-=matchsticks[next];
        }
        return square;
    }   
    bool checkSides(vector<int> &sides,int sideLength){
        for(auto side:sides)
            if(side!=sideLength)
                return false;
        return true;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(auto match:matchsticks)
            sum+=match;
        if(sum%4!=0||matchsticks.size()<4)
            return false;
        if(matchsticks[matchsticks.size()-1]>sum/4)
            return false;
        vector<int> sides(4,0); 
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return temp(sides,matchsticks,0,sum/4);;
    }
};