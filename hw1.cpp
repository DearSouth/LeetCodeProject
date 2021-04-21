//#include <algorithm>
//#include <iostream>
//#include<array>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> speedValue;
//	int n=0;
//	cin >> n;
//	for (int i=0;i<n;i++)
//	{
//		int temp;
//		cin >> temp;
//		speedValue.push_back(temp);
//	}
//	vector<int> report;
//	int zhoiqi = 60;
//	int begintCount = 0;
//	int AEB_prepare = 0;
//	int AEB_left = -1;
//	int AEB_right = -1;
//	bool reportAEB = false;
//	for(int i = 0;i<n;i++,begintCount++)
//	{
//		if (begintCount % zhoiqi == 0)
//			report.push_back(speedValue[i]);
//		int next = (i + 1) < n ? (i + 1) : n-1;
//		if(speedValue[i] - speedValue[next] > 9)
//		{
//			if (AEB_prepare < 3)
//				AEB_prepare ++;
//			else
//			{
//				reportAEB = true;
//				int tempLeft = (i - 6) > 0 ? (i - 6) : 0;
//				AEB_left = max(tempLeft, AEB_left);
//				for (int k = AEB_left; k < i; k++)
//				{
//					report.push_back(speedValue[k]);
//				}
//			}
//		}
//		else
//		{
//			if(reportAEB == true)
//			{
//				AEB_right = (i + 3) > (n - 1) ? (n - 1) : (i + 3);
//				for (int k = i; k <= AEB_right; k++)
//				{
//					report.push_back(speedValue[k]);
//				}
//				reportAEB = false;
//				begintCount = -1;
//			}
//			AEB_prepare = 0;
//		}
//		if(reportAEB)
//		{
//			report.push_back(speedValue[i]);
//		}
//	}
//	for(int j = 0;j<report.size();j++)
//	{
//		cout << report[j] << endl;
//	}
//
//	//std::cout << "Hello World!\n";
//}
//
////    24  2 1 5 3 4 8 3 1 60 50 40 30 20 10 45 5 4 5 6 2  45 65 36 0
