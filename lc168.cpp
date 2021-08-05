#include<iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
	    while (columnNumber>26)
	    {
            int yu = columnNumber % 26;
	    	if(!yu)
	    	{
                result.insert(result.begin(), 'Z');
                columnNumber = columnNumber / 26 - 1;
	    	}else
	    	{
                result.insert(result.begin(), ('A' + yu - 1));
                columnNumber = columnNumber / 26;
	    	}
            
	    }
        result.insert(result.begin(), ('A' + columnNumber - 1));
        return result;
    }
};
//int main()
//{
//
//    Solution so;
//    cout << so.convertToTitle(52) << endl;
//
//    return 0;
//}