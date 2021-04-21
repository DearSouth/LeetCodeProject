#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> getString(vector<int>& nums, vector<int>& useable)
{
	vector<int> temp;
	for (int i=0;i<nums.size();i++)
	{
		if(useable[i])
		{
			for(int j=0;j<useable[i];j++)
				temp.push_back(nums[i]);
		}
	}
	return temp;
}

void getList(vector<int>& nums,vector<int>& useable,int target,vector<vector<int>>& resultVector,int beginPos)
{
	for(int i=0;i<nums.size();i++)
	{
		//if(useable[i])
		{
			if(nums[i] == target)
			{
				useable[i]++;
				if(!count(resultVector.begin(),resultVector.end(), getString(nums, useable)))
					resultVector.push_back(getString(nums, useable));
				useable[i]--;
				continue;
			}
			if(target - nums[i] > 0)
			{
				useable[i]++;
				getList(nums, useable, target - nums[i], resultVector,i+1);
				useable[i]--;
			}
			else
				break;
			
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

	vector<vector<int>> result;
	//unordered_map<vector<int>,bool> map;
	vector<int> useable(candidates.size(),0);// = { true };
	sort(candidates.begin(), candidates.end());
	getList(candidates, useable, target, result,0);

	return result;
	
}

//int main()
//{
//	vector<int> vec = { 2,3,6,7 };
//	vector<vector<int>> result = combinationSum(vec, 7);
//	std::cout << "Hello World!\n";
//}