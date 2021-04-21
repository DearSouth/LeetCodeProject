//#include <algorithm>
//#include <iostream>
//#include<array>
//#include<vector>
//using namespace std;
//
//void find()
//{
//	
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> value;
//	for (int i=0;i<n;i++)
//	{
//		int tValue;
//		cin >> tValue;
//		value.push_back(tValue);
//	}
//	vector<int> stepFlag(n, -1);
//	stepFlag[n - 1] = 0;
//	for (int i=n-1;i>=0;i--)
//	{
//		int pos = i;
//		int left = (i - value[i]) > 0 ? (i - value[i]) : 0;
//		int right = (i + value[i]) > (n - 1) ? (n - 1) : (i + value[i]);
//		int min = INT_MAX;
//
//		for(int j=right;j>=left;j--)
//		{
//			if(stepFlag[j]==-1)
//			{
//				stepFlag[j] = min+1;
//			}
//			else
//			{
//				if (stepFlag[j] < min)
//					min = stepFlag[j];
//			}
//			
//		}
//	}
//	if ((stepFlag[0] + 1) > -1)
//		cout << (stepFlag[0] + 1) << endl;
//	else
//		cout << 0;
//	//std::cout << "Hello World!\n";
//}
//
