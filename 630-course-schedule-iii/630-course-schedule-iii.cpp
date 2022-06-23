class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector < int > & i1,
        const vector < int > & i2) {
            if(i1[1]==i2[1])
                return i1[0]<i2[0];
        return i1[1]<i2[1];
          });
        
        priority_queue<int> shcedule;
        int time = 0;
        for(auto course: courses){
            if(course[1]>=time+course[0])
            {
                shcedule.push({course[0]});
                time+=course[0];
            }else if(!shcedule.empty()&&shcedule.top()>course[0])
            {   
                time += -shcedule.top() +course[0];
                shcedule.pop();
                shcedule.push({course[0]});
            }
        }

        return shcedule.size();
    }
};