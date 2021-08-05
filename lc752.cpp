#include<iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
	vector<string> getNext(string S)
	{
        vector<string> ret;
		for(int i=0;i<4;i++)
		{
            string temps(S);
            temps[i] = (S[i] == '9' ? '0' : (S[i] + 1));
            ret.push_back(temps);
            temps = S;
            temps[i] = (S[i] == '0' ? '9' : (S[i] - 1));
            ret.push_back(temps);
		}
        return ret;
	}
	
    int openLock(vector<string>& deadends, string target) {
        // BFS
        if (target == "0000")
            return 0;
        unordered_set<string> seen;
        unordered_set<string> dead(deadends.begin(),deadends.end());

        if (dead.count("0000"))
            return -1;
        queue<string> que;
        que.push("0000");
        int step = 0;
        while (!que.empty())
        {
            int len = que.size();
        	for (int i=0;i<len;i++)
        	{
                string temps = que.front();
                que.pop();
                for (auto re : getNext(temps))
                {
                	if(re == target)
                        return step + 1;
                	
                	if(seen.count(re) == 0 && dead.count(re) == 0)
                	{
                        que.push(re);
                        seen.insert(re);
                	}  
                }
        	}
            step++;
        }
        return -1;
    }
};
//int main()
//{
//    //vector<int> value = { 1, 3, 2, 8, 4, 9 };2.00000
//    string ss = "0234";
//    string ss2 = "0234";
//    //ss2 = ss;
//    //queue<string> que;
//    //que.push("000");
//    //que.push("111");
//    //que.push("222");
//
//    //cout << ((ss == ss2) ? 1 : 2) << endl;
//    Solution so;
//    vector<string> deads = { "8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888" };
//    string target = "8888";
//    cout << so.openLock(deads, target);
//
//	//for(auto re:so.getNext(ss))
//	{
//   //     cout << re << endl;
//	}
// /*   ["8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"]
//    "8888"*/
//
//    return 0;
//}