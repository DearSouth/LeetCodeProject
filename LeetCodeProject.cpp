// LeetCodeProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
#define N 4  //  数的个数
int check(vector<int>& nums, int m);

int curN = 0;
int numPos[N] = { -1 };
//  一个数组为N个数，取两数相加为M的所有可能
void allSum(vector<int> &nums,int m)
{
	int len = nums.size();
	//while (true)
	{

		for (int i=0;i<len;++i)
		{
			numPos[curN] = i;
			curN++;

			if (curN < N)//  取当前数i
			{
				if (-1 == check(nums, m))
				{
					curN--;
					i = numPos[curN];
				}
			}
			else//  不取当前数
			{
				if (1 == check(nums, m))
				{
					for (int j = 0; j < curN; ++j)
					{
						cout << numPos[j] << ":" << nums[numPos[j]] << "  ";
					}
					cout << endl;
				}
				curN--;
				i = numPos[curN];
			}
			
			while(i==len-1 && curN>0)
			{
				curN--;
				i = numPos[curN];
			}
		}
	}
	
}
// 1 找到符合条件的情况   -1 当前的数大于目标数     0 当前数小于目标数
int check(vector<int> &nums,int m)
{
	int sum = 0;
	for (int i=0;i<curN;++i)
	{
		sum += nums[numPos[i]];
	}
	if (sum == m)
		return 1;
	else
		return sum < m ? 0 : -1;

}
//int main()
//{
//	vector<int> nums = { 2,3,6,1,4,5,3,4,1 };
//	allSum(nums, 9);
//    std::cout << "Hello World!\n";
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
