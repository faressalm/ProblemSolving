class Solution {
public:
    string longestPalindrome(string str){
    string newStr = "#";
    for(auto s:str){
         newStr+=s;
        newStr+='#';
    }
    int size=newStr.size();
    vector<int> LPS (size,0); // Longest Palindrom Substring
    int range =0;
    int center=0;
    
    for(int i=0;i<size;i++){
        int indexMirror = 2*center-i;
        if(range>i) // current index with the range 
            LPS[i] = min(range-i,LPS[indexMirror]); 
        // else LPS[i] = 0
        bool outOfBoundries =(i+1+LPS[i])!=size&&(i-1-LPS[i])!=-1;
        while(outOfBoundries&& newStr[i+1+LPS[i]] == newStr[i-1-LPS[i]])
        {   
           LPS[i]++;
           outOfBoundries =(i+1+LPS[i])!=size&&(i-1-LPS[i])!=-1;
        }
        
        if(i+LPS[i]>range) // center changed 
        {
            center=i;
            range=i+LPS[i];
        }
    }
    int maxRange=0;
    for(int i=0;i<size;i++){
        if(maxRange<LPS[i]){
            center=i;
            maxRange= LPS[i];
        }
    }  
    string lps = newStr.substr(center-maxRange,2*maxRange);
    lps.erase(remove(lps.begin(), lps.end(), '#'),lps.end());
    return lps;
}
};