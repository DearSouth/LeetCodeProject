//#include <algorithm>
//#include <iostream>
//#include<array>
//#include<vector>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
// 
//class Solution {
//public:
//	//  中序遍历 取出树种的值
//	void makeVector(TreeNode* root)
//	{
//		if (root->left != NULL)
//			makeVector(root->left);
//		nodeVec.push_back(root->val);
//		if (root->right != NULL)
//			makeVector(root->right);
//	}
//	int minDiffInBST(TreeNode* root) {
//		if (!root)
//		{
//			return -1;
//		}
//		makeVector(root);
//		if (nodeVec.size() < 2)
//			return -1;
//		sort(nodeVec.begin(), nodeVec.end());
//		int minDiff = INT_MAX;
//		for(int i=1;i<nodeVec.size();i++)
//		{
//			int temp = nodeVec[i] - nodeVec[i - 1];
//			minDiff = minDiff > temp ? temp : minDiff;
//		}
//		return minDiff;
//	}
//private:
//	vector<int> nodeVec;
//};
//
//int main()
//{
//    Solution so;
//    TreeNode* root = NULL;
//    so.minDiffInBST(root);
//	
//	std::cout << "Hello World!\n";
//}
//
