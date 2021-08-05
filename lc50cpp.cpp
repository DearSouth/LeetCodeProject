#include<iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;
        if (n == 0)
            return 1;
        powValue[1] = x;
        if (n > 0)
            return getPow(x, n);
        else {
        	
			return 1.0 / getPow(x, -(long long)n);
		}
       // return n > 0 ? getPow(x, n) : (1.0 / getPow(x, 0 - n));
    }
	double getPow(double x, long long n)
    {
        cout << n << endl;
    	if(powValue.find(n) != powValue.end())
    	{
            return powValue[n];
    	}
    	else
    	{
            int halfN = n / 2;
            if (n % 2 == 0)//  偶数就返回 半数值和
            {
                powValue[n] = getPow(x, halfN) * getPow(x, halfN);
                return powValue[n];
            }
            else//   奇数返回 半数值和 * x
            {
                powValue[n] = getPow(x, halfN) * getPow(x, halfN) * x;
                return powValue[n];
            }
    	}
    }
    unordered_map<int, double> powValue;// <n,powV>
};

//int main()
//{
//    //vector<int> value = { 1, 3, 2, 8, 4, 9 };2.00000
//    
//    Solution so;
//    int result = so.myPow(2, -2147483648);
//    std::cout << result << endl;
//    return 0;
//}