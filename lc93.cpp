#include <algorithm>
#include <iostream>
#include<array>
#include<vector>
using namespace std;

class Solution {
public:

    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if (len < 4 || len>12)
            return result;
        splitAddress(s,4);
        return result;
    }
	bool strMax255Min0(string s,int startPos,int count)
    {
        int len = s.length();
    	if(len<=0 || count > 3)
            return false;
        if (count > 1 && s.at(startPos) == '0')
            return false;
        int num = 0;
    	for(int i = 0;i<count;i++)
    	{
            num = num * 10 + (s.at(i + startPos) - '0');
    	}
        if (num >= 0 && num <= 255)
            return true;
        return false;
    }
	void splitAddress(string s,int leftNum)
    {
        int len = s.length();
        if (len > leftNum * 3)
            return;
    	
    	if(leftNum == 1)
    	{
    		if(strMax255Min0(s,0,len))
    		{
                string ip;
    			for(auto it:tempIpStr)
    			{
                    ip += it;
                    ip += '.';
    			}
                ip += s;
                result.push_back(ip);
    		}
    		return;
    	}
        
        string thisPosIP = "";
	    for(int i=0;i<3 && i<len;i++)
	    {
            thisPosIP += s.at(i);
	    	if(strMax255Min0(thisPosIP,0,thisPosIP.length()))
	    	{
                tempIpStr.push_back(thisPosIP);
                string temp = s.substr(i + 1, len - i - 1);
                splitAddress(temp, leftNum - 1);
                tempIpStr.pop_back();
	    	}
            
	    }
    }
    vector<string> result;
    vector<string> tempIpStr;
};


//int main()
//{
//    Solution s;
//    s.restoreIpAddresses("010010");
//    //std::cout << "Hello World!\n";
//}

