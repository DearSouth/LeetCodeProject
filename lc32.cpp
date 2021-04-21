#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int max = 0;
		int len = s.length();
		int dp[100][100] = { 0 };
		for(int sLen=1;sLen<len;sLen+=2)
		{
			for(int i = 0;i < len-sLen; ++i)
			{
				int j = i + sLen;
				if(sLen == 1)
				{
					if(s.at(i) == '(' && s.at(j)==')')
					{
						dp[i][j] = 2;
						if (max < 2)
							max = 2;
					}
				}
				else
				{
					if (s.at(i) == '(' && s.at(j) == ')')
					{
						if(dp[i + 1][j - 1]!=0)
						{
							dp[i][j] = dp[i + 1][j - 1] + 2;
							if (max < dp[i][j])
								max = dp[i][j];
						}
						
					}
					else
						dp[i][j] = dp[i + 1][j - 1];
				}
				
			}
		}
		return max;
	}
};
//   ´íÎóË¼Â·
//int main()
//{
//	Solution* so = new Solution();
//	string s = "((())()";
//	int res = so->longestValidParentheses(s);
//	cout << res << endl;
//	std::cout << "Hello World!\n";
//}
