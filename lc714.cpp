#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        
        //vector<vector<int>> dp(len, vector<int>(2));
        //dp[0][0] = 0;
        //dp[0][1] = -prices[0];
        vector<int> dpnew(2);
        dpnew[0] = 0;
        dpnew[1] = -prices[0];
        for (int i = 1; i < len; i++)
        {
            dpnew[0] = max(dpnew[1] + prices[i] - fee, dpnew[0]);
            dpnew[1] = max(dpnew[1], dpnew[0] - prices[i]);
            //dp[i][0] = max(dp[i - 1][1] + prices[i] - 2, dp[i - 1][0]);
            //dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return max(dpnew[0], dpnew[1]);
    }
};

//int main()
//{
//    vector<int> value = { 1, 3, 2, 8, 4, 9 };
//    Solution so;
//    int result = so.maxProfit(value, 2);
//    std::cout << result << endl;
//	return 0;
//}