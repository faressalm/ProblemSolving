class Solution {
private: 
    bool checkOneZero(int byte){
       return (byte&(3<<6)) == (1<<7); 
    }
    bool isOneByte(vector<int>& data,int byteIndex){
        return (data[byteIndex]&(1<<7)) == 0;
    }
    bool isTwoByte(vector<int>& data,int byteIndex){
        if(data.size() - byteIndex < 2)
            return false;
        return ((data[byteIndex]&(7<<5)) == (3<<6)) && checkOneZero(data[byteIndex+1]);
    }
    bool isThreeByte(vector<int>& data,int byteIndex){
        if(data.size() - byteIndex < 3)
            return false;
        bool found = ((data[byteIndex]&(15<<4) )== (7<<5));
        for(auto i:{1,2}){
            found=found&&checkOneZero(data[byteIndex+i]);
        }
        return  found;
    }
    bool isFourByte(vector<int>& data,int byteIndex){
        if(data.size() - byteIndex < 4)
            return false;
        bool found = ((data[byteIndex]&(31<<3)) == (15<<4));
        for(auto i:{1,2,3}){
            found=found&&checkOneZero(data[byteIndex+i]);
        }
        return  found;
    }    
    pair<int,bool> checkSeq(vector<int>& data,int index){
        if(isOneByte(data,index))
            return {index,true};
        else if(isTwoByte(data,index))
            return {index+1,true};
        else if(isThreeByte(data,index))
            return {index+2,true};
        else if(isFourByte(data,index))
            return {index+3,true};
        else return {0,false};
    }
public:
    bool validUtf8(vector<int>& data) {
        for(int i=0;i<data.size();i++){
            pair<int,bool> sol  = checkSeq(data,i);
            if(sol.second)
                i=sol.first;
            else return false;
        }
        return true;
    }
};