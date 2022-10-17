class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        int score = 0;
        for(auto &s:operations){
            if(s=="+")
            {
                scores.push_back(scores[scores.size()-1] +scores[scores.size()-2]);
                score+=scores[scores.size()-1];
            }
            else if (s == "D")
            {
                scores.push_back(scores[scores.size()-1]*2);
                score+=scores[scores.size()-1];   
            }
            else if (s == "C")
            {   
                score -= scores[scores.size()-1];
                scores.pop_back();
            }
            else
            {
                scores.push_back(stoi(s));
                score+=scores[scores.size()-1];
            }   
        }
        return score;
    }
};