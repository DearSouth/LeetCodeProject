#include<iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include "structDefine.h"
using namespace std;

/*////////  726题
class Solution {
public:
    string countOfAtoms(string formula) {
        formula.insert(formula.length(), ")");
        formula.insert(0, "(");
        stack<int> pos;
        string fullStr = "";
        map<string, int> Automs;
        for (int i = 0; i < formula.length(); i++)
        {
            switch (formula[i])
            {
            case '(':
                pos.push(i);
                break;
            case ')':
                getAutomNum(formula, pos.top() + 1, i - 1, Automs);
                int centNum = findFollowNum(formula, ++i);
                i--;
                pos.pop();
            	if(centNum>1)
            	{
                    for (auto it = Automs.begin(); it != Automs.end(); it++)
                    {
                        it->second *= centNum;
                    }
            	}
                    
                break;
            }

        }
        string result = "";
    	for(auto it:Automs)
    	{
            result += it.first;
    		if(it.second>1)
    		{
                result += to_string(it.second);
    		}
    	}
        return  result;
    }
	void getAutomNum(string formula,int start,int end,map<string,int> &Automs)
    {
    	
    //	Mg(OH)2
      //  K4(ON(SO3)2)2
    	//H2O
    	//N
    	
        //if (start == end)
        //{
        //    addAtoms(Automs, ""+formula[start], 1);
        //    return;
        //}
        bool newAutom = true;
        string thisAutom = "";
        int thisAutomNum = 1;
	    for(int i=start;i<=end;i++)
	    {
	    	if(formula[i] == '(')
	    	{
	    		newAutom = false;
		        while (formula[i]!=')')
		        {
                    i++;
		        }
                i++;
	    	}
	    	if(formula[i]>='A' && formula[i]<='Z')
	    	{
                newAutom = true;
	    		if(thisAutom.length()>0)
	    		{
                    addAtoms(Automs, thisAutom, thisAutomNum);
                    thisAutomNum = 1;
	    		}
                thisAutom = "";
                thisAutom += formula[i];
	    	}
            else if(formula[i] >= 'a' && formula[i] <= 'z')
            {
                thisAutom += formula[i];
            }
	    	else
	    	{
	    		if(newAutom)
                    thisAutomNum = findFollowNum(formula, i);
                newAutom = false;
	    	}
	    }
        if (thisAutom.length() > 0)
        {
            addAtoms(Automs, thisAutom, thisAutomNum);
        }
    }
	int findFollowNum(string formula,int &pos)
    {
        int tempN = 0;
        while (formula[pos] >= '0' && formula[pos] <= '9' && pos < formula.length())
        {
            tempN = tempN * 10 + formula[pos] - '0';
            pos++;
        }
        return tempN == 0 ? 1 : tempN;
    }
	void addAtoms(map<string, int>& Automs,string atom,int num)
    {
	    if(Automs.count(atom) == 0)
            Automs.insert(make_pair(atom, num));
        else
            Automs.at(atom) += num;
    }
};

int reverse(int x) {
    if (!x)
        return 0;
    bool fu = (x < 0);
    long long dx = x;
    dx = abs(dx);
    while (dx%10 == 0)
    {
        dx = dx / 10;
    }
    string ss = to_string(dx);
    int len = ss.length();
	for(int i=0;i<len/2;i++)
	{
        swap(ss[i], ss[len - i - 1]);
	}
    dx = atof(ss.c_str());
    dx = fu ? (-dx) : dx;
    if (dx > INT32_MAX || dx<INT32_MIN)
        return 0;
    return (int)dx;
}
*/

/*
class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int totalNum = 0;
        int onceNum = 0;
        for (int i = 0; i < len; i++)
        {
            switch (s[i])
            {
            case 'I':
                if ((i + 1) < len && s[i + 1] == 'V')
                {
                    onceNum = 4;
                    i++;
                }
                else if ((i + 1) < len && s[i + 1] == 'X')
                {
                    onceNum = 9;
                    i++;
                }
                else
                    onceNum = 1;
                break;
            case 'V': onceNum = 5; break;
            case 'X':
                if ((i + 1) < len && s[i + 1] == 'L')
                {
                    onceNum = 40;
                    i++;
                }
                else if ((i + 1) < len && s[i + 1] == 'C')
                {
                    onceNum = 90;
                    i++;
                }
                else
                    onceNum = 10;
                break;
            case 'L': onceNum = 50; break;
            case 'C':
                if ((i + 1) < len && s[i + 1] == 'D')
                {
                    onceNum = 400;
                    i++;
                }
                else if ((i + 1) < len && s[i + 1] == 'M')
                {
                    onceNum = 900;
                    i++;
                }
                else
                    onceNum = 100;
                break;
            case 'D': onceNum = 500; break;
            case 'M': onceNum = 1000; break;
            }
            totalNum += onceNum;
            onceNum = 0;
        }
        return totalNum;
    }
};
*/

/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	
        vector<int>::iterator it;
        int before ;
        bool over = true;
        while (over)
        {
            if (nums.size() <= 1)
                return nums.size();
            it = nums.begin();
            before = *it;
            it++;
            for (; it != nums.end(); )
            {
                cout << "," << *it << endl;
                if (*it == before)
                {
                    nums.erase(it);
                    break;
                }
                before = *it;
                it++;
            	if(it == nums.end())
            	{
                    over = false;
            	}
            }
        }
    	
        return nums.size();
    }
};
*/

/*
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int len = arr.size();
        if (len == 1)
            return 1;
        sort(arr.begin(), arr.end());
        int maxN = arr[len - 1];
        arr[0] = 1;
        int repeatNum = 0;
    	for(int i = len-1;i>0;i--)
    	{
    		if(arr[i] - arr[i - 1] == 0)
    		{
                repeatNum++;
                continue;
    		}
    		if(arr[i] - arr[i-1] > 1)
    		{
                maxN -= (arr[i] - arr[i - 1]) > repeatNum ? (arr[i]-repeatNum - arr[i - 1] - 1) : 0 ;
                repeatNum = 0;
    		}
    	}
        return  maxN;
    }
};*/

/* 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.size() == 1)
            return strs[0];
        bool keep = true;
        int len = 0;
        while (keep)
        {
	        for(int j = 0;j<strs.size();j++)
	        {
		        if(strs[j].length()<=len)
		        {
                    keep = false;
		        	break;
		        }
	        	if(j<=0)
                    continue;
	        	if(strs[j][len]!=strs[j-1][len])
	        	{
                    keep = false;
	        		break;
	        	}
	        	
	        }
        	if(keep)
                result += strs[0][len++];
        }
        return result;
    }
};*/

/*  
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int count = 0;
        int findvalue = findPos(nums, 0, nums.size() - 1, target);
        if (findvalue != -1)
    	{
            int pcount = findvalue;
	        while (pcount>=0 && nums[pcount--] == target)
	        {
                count++;
	        }
            pcount = findvalue;
            while (pcount < nums.size()&&nums[pcount++] == target)
            {
                count++;
            }
    	}
        return count == 0 ? 0 : (count - 1);
    }
    int findPos(const vector<int>& nums, int start, int end,int target)
    {
        if (start > end)
	        	return -1;
        int temp = (start + end) / 2;
        if (nums[temp] == target)
            return temp;
        else if (nums[temp] >= target)
            return findPos(nums, start, temp - 1, target);
        else
            return findPos(nums, temp + 1, end, target);
    }
};*/

/*   
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        if (s.length() <= 1 || s.length() %2 == 1)
            return false;
    	for(char c:s)
    	{
	        switch (c)
	        {
            case '(':sta.push(')');       break;
            case '[':sta.push(']');       break;
            case '{':sta.push('}');       break;
            default:
                if (sta.empty() || sta.top() != c)
                    return false;
                sta.pop();
                break;
	        }
    	}
        if (sta.empty())
            return true;
        return false;
    }
};*/

/* 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* tail = result;
        while (l1!=nullptr && l2!=nullptr)
        {
	        if(l1->val>l2->val)
	        {
                tail->next = l2;
                l2 = l2->next;
	        }
        	else
	        {
                tail->next = l1;
                l1 = l1->next;
	        }
            tail = tail->next;
        }
    	if(!l1)
            tail->next = l2;
        else
            tail->next = l1;
        return result->next;
    }
};*/

/*  
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if(q == nullptr || p == nullptr)
    	{
            if (!p && !q)
                return true;
            return false;
    	}
        if(p->val == q->val)
        {
            return isSameTree(p->left, q->left) & isSameTree(p->right,q->right);
        }
        return false;
    }
};*/

/*
//class Solution {
//public:
//    //vector<vector<string>> groupAnagrams(vector<string>& strs) {
//    //    
//    //    //unordered_map <string, vector<map<string, map<char, int>>>> resultmp;
//    //    map <string, vector<string>> resultmp;
//    //    vector<vector<string>> result;
//    //	for(string s:strs)
//    //	{
//    //        map<char, int> mp;
//    //		for(char c:s)
//    //		{
//    //            if (mp.count(c) == 0)
//    //                mp[c] = 1;
//    //            else
//    //                mp[c]++;
//    //		}
//    //        string convStr = "";
//    //		for(auto va:mp)
//    //		{
//    //            convStr += va.first;
//    //            convStr += (to_string(va.second));
//    //		}
//    //        resultmp[convStr].push_back(s);
//    //	}
//    //	for(auto val:resultmp)
//    //	{
//    //        vector<string> tempvec;
//    //        tempvec.clear();
//    //		for(string s:val.second)
//    //		{
//    //            tempvec.push_back(s);
//    //		}
//    //        result.push_back(tempvec);
//    //	}
//    //    return result;
//    //}
//
//    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
//
//        //unordered_map <string, vector<map<string, map<char, int>>>> resultmp;
//        map <string, vector<string>> resultmp;
//        vector<vector<string>> result;
//        for (string s : strs)
//        {
//        	string convStr(s);
//            sort(s.begin(),s.end());
//            resultmp[s].push_back(convStr);
//        }
//        for (auto val : resultmp)
//        {
//            result.push_back(val.second);
//        }
//        return result;
//    }
//};
*/

/*    
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int len = nums.size();
        int maxNum = nums[0];
    	for(int i = 0;i<len ;i++)
    	{
            int tempMax = 0;
    		for(int j = (i);j<len ;j++)
    		{
                tempMax += nums[j];
                if (maxNum < tempMax)
                    maxNum = tempMax;
    		}
    	}
        return maxNum;
    }
};*/

/*  
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        int len = nums.size();
    	for (int i=0;i<len;i++)
    	{
            result = max(result, (nums[i] + nums[len - i - 1]));
    	}
        return result;
    }
};*/

/* 
class Solution {
public:

    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        if (n == 0)
            return 1;
        if (x == 1)
            return 1;
        bool flag = n > 0 ? true : false;
        long nd = abs((long)n);
        double res = 1.0;
        while (nd > 0)
        {
            if (n % 2 == 1)
            {
                res *= x;
            }
            x *= x;
            nd = nd / 2;
        }
        return flag ? res : (1.0 / res);
    }
};*/

/*  
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        return dfs(matrix, target, 0, 0);
    }
    bool dfs(vector<vector<int>>& matrix, int target, int x, int y)
    {
        cout << x << " " << y << endl;
        if(matrix[x][y] == target)
            return true;
        if (matrix[x][y] > target)
            return false;
        else
        {
            bool res = false;
            if (x < (matrix.size() - 1))
                res = dfs(matrix, target, x + 1, y);
            if (!res && y < (matrix[0].size() - 1))
                res = dfs(matrix, target, x, y + 1);
            return res;
        }
    }
};*/

/*
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> base2;
        for (int i = 0; i < 20; i++)
        {
            base2.push_back(1 << i);
            cout << base2[i] << endl;
        }
        cout << endl;

        vector<int> res;
        int cen = 0;
        for (int i = 0; i < 20; i++)
        {
            if (label < base2[i])
            {
                cen = i;
                break;
            }
        }
        cout << cen << endl;
        while (label > 1 && cen >= 1)
        {
            res.push_back(label);
            cout << label << endl;
            label = (base2[cen] - label - 1 + base2[cen - 1]);
            label /= 2;
            cen--;
        }
    	
        res.push_back(label);
        reverse(res.begin(), res.end());
        return res;
    }
};*/

/*
class Solution {
public:
    int mfind(vector<int>& arr, int left, int right, int target)
    {
        unsigned int mid = (left + right) >> 1;
        while (left < right)
        {
            mid = (left + right) >> 1;
            if (arr[mid] > target)
                right = mid - 1;
            else if (arr[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++)
        {
            int n1 = mfind(numbers, 0, numbers.size() - 1, target - numbers[i]);
            if (n1 != -1)
            {
                if (n1 == i)
                {
                    int n2 = mfind(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
                    if (n2 != -1)
                    {
                        res.push_back(n1 + 1);
                        res.push_back(n2 + 1);
                        return res;
                    }
                }
                else {
                    res.push_back(i + 1);
                    res.push_back(n1 + 1);
                    return res;
                }

            }
        }
        return res;
    }
};*/

/*  class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums,int target) {
	    vector<vector<int>> res;
	    int len = nums.size();
	    if (len < 4)
		    return res;
	    sort(nums.begin(), nums.end());
        for(int first = 0;first < len-2;first++)
        {
	        if (first > 0 && nums[first] == nums[first - 1])
		        continue;
	        int tar = target - nums[first];
            for (int basei = first+1; basei < len - 1; basei++)
            {
                if (basei > first + 1 && nums[basei - 1] == nums[basei])
                    continue;
                int left = basei + 1;
                int right = len - 1;
                while (left < right)
                {
                    int tempSum = nums[basei] + nums[left] + nums[right];
                    if (tempSum > tar)
                        right -= 1;
                    else if (tempSum < tar)
                        left += 1;
                    else
                    {
                        res.push_back(vector<int> { nums[first], nums[basei], nums[left], nums[right] });
                        while (left < right && nums[++left] == nums[left - 1]);
                        while (left < right && nums[--right] == nums[right + 1]);
                    }
                }
            }
        }
        return res;
    }
};*/

/*
long long calBoxNum(string &str,int begin,int end)
{
    if (begin >= end)
        return 0;
    stack<int> lpos;
    int n = 0;
	
	for(int i = begin;i<=end;i++)
	{
        if (str[i] == '[')
            lpos.push(i);
        else if(str[i] == ']')
        {
            int tempbeg = lpos.top();
            lpos.pop();
        	if(lpos.empty())
        	{
                long long tempn = 1;
                if (i + 1 <= end && str[i + 1] != '[' && str[i + 1] != ']')
                    tempn = str[i + 1] - '0';
                tempn = calBoxNum(str, tempbeg + 1, i - 1) * tempn + tempn;
                n += (tempn);
        	}
            
        }
	}
    return n;
}

vector<int> jiNums;
vector<int> ouNums;
int m, k, x;
int ncount = 0;
void calNumCount(string &str,bool jiouFlag)
{
    int res;
    if (str.length() > m)    return ;
	if(str.length() == m)
	{
        long long num = atoll(str.c_str());
		if(num%x == k)
		{
            ncount++;
            if (ncount > 10000019)
                ncount -= 10000019;
		}
		return;
	}
    vector<int>* tempvector;
	if(jiouFlag)
        tempvector = &jiNums;
	else
        tempvector = &ouNums;
    for (int num : *tempvector)
    {
        str = str + char(num + '0');//  str 补一位
        calNumCount(str, !jiouFlag);
        str.erase(str.length() - 1);//str[str.length() - 1] = '\0';//  str 删除最后一位
    }
}
int n;
cin >> n >> m >> k >> x;
int inNum;
while (n--)
{
    cin >> inNum;
    if (inNum % 2)
        jiNums.push_back(inNum);
    else
        ouNums.push_back(inNum);
}
if (jiNums.empty() || ouNums.empty())
return 0;
string str = "";
calNumCount(str, true);
calNumCount(str, false);
cout << ncount << endl;
*/

              
/*class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0, maxNum = nums[0];
        for (int val : nums)
        {
            sum += val;
            if (val > maxNum)
                maxNum = val;
        }
        if (sum & 1) {// 判断奇数偶数
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            for (int j = 1; j <= target; j++)
            {
                if (j >= num)
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n - 1][target];
    }
};*/

//   
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        /*if (coins.empty())
//            return -1;
//        sort(coins.begin(), coins.end());
//        if (amount == 0)
//            return 0;
//        if (amount < coins[0])
//            return -1;
//        set<long long> que;
//        int res = 0;
//    	for(int coin:coins)
//    	{
//            que.insert(coin);
//    	}
//        res = 1;
//        while (!que.empty())
//        {
//            vector<long long> tempV;
//        	for(long long  val:que)
//        	{
//                cout << val << "  ";
//                if (val == amount)
//                    return res;
//                else if (val > amount)
//                    que.erase(val);
//                else
//                {
//                    for (int coin : coins)
//                    {
//                        tempV.push_back(val + coin);
//                    }
//                }
//        	}
//            que.clear();
//            que.insert(tempV.begin(), tempV.end());
//            tempV.clear();
//            cout << endl;
//            res++;
//        }
//        return -1;*/
//
//        if (coins.empty())
//            return -1;
//    	
//        vector<int> dp(amount + 1, INT_MAX);// dp为当前金额，所需的最小步骤
//        dp[0] = 0;
//    	for(int i=1;i<=amount;i++)
//    	{
//    		for(int coin:coins)
//    		{
//    			if(i>=coin && dp[i-coin]!= INT_MAX)
//    			{
//                    dp[i] = min(dp[i], dp[i - coin] + 1);
//    			}
//    		}
//    	}
//        return dp[amount];
//    	
//    }
//};

  /*   
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> n2RMaxPos(nums2.size(), -1);
        stack<int> st;
        int i = 0;
        for (int val : nums2)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && val > nums2[st.top()])
                {
                    n2RMaxPos[st.top()] = val;
                    st.pop();
                }
                st.push(i);
            }
            i++;
        }
        vector<int> res(nums1.size(), -1);
        i = 0;
        for (int val : nums1)
        {
            res[i] = n2RMaxPos[find(nums2.begin(), nums2.end(), val) - nums2.begin()];
            i++;
        }
        return res;
    }
};*/

/*   
class Solution {
public:
    int count = 0;
    int numSquares(int n) {
        vector<int> fangNums;
        for (int i = 1; ; i++)
        {
            if (i * i <= n)
                fangNums.push_back(i * i);
            else
                break;
        }
        for (int val : fangNums)
            cout << val << " ";
        cout << endl;
        vector<int> dp(n + 1, INT_MAX);
        for (int val : fangNums)
        {
            dp[val] = 1;
        }
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 0; j < fangNums.size(); j++)
            {
                if (i - fangNums[j] > 0)
                    dp[i] = min(dp[i], dp[i - fangNums[j]]);
                else
                    break;
            }
        }

        return dp[n];
    }
};*/

////  反转链表   从head节点到end的前一个节点   返回值head为第一个节点，end为最后一个节点
//void nodeRever(ListNode* &head,ListNode* &end)
//{
//    ListNode* node = nullptr;
//    ListNode* newend = head;
//    while (head->next != end)
//    {
//        ListNode* temp = head->next;
//        head->next = node;
//        node = head;
//        head = temp;
//    }
//    head->next = node;
//    end = newend;
//}
//ListNode* k_nodeReverse(ListNode* nodes,int k)
//{
//    ListNode head;
//    head.next = nodes;
//    ListNode* first = nodes;
//	ListNode* second = nodes;
//    int coun = k;
//    ListNode* phead = &head;
//	while(second !=nullptr)
//	{
//        second = second->next;
//		if(--coun <= 0)
//		{
//            ListNode* temp = second;
//            coun = k;
//            nodeRever(first, second);
//            phead->next = first;
//            phead = second;
//            second = temp;
//            first = temp;
//		}
//	}
//	if(coun != k)
//	{
//        nodeRever(first, second);
//        phead->next = first;
//	}
//    return head.next;
//}
void showList(ListNode* head)
{
	while (head!=nullptr)
	{
        cout << head->val << " ";
        head = head->next;
	}
    cout << endl;
}

//    
//class Solution {
//public:
//    string longestWord(vector<string>& words) {
//        if (words.empty())
//            return "";
//        sort(words.begin(), words.end());
//    	string res = "";
//        int maxSize = 0;
//        string tempstr = "";
//        for(string str:words)
//        {
//            if(str.length() > tempstr.length())
//            {
//                string newstr = str;
//                newstr.erase(newstr.length() - 1);
//                if (newstr == tempstr) 
//                {
//                    tempstr = str;
//                    if (tempstr.size() > maxSize)
//                    {
//                        maxSize = tempstr.size();
//                        res = tempstr;
//                    }
//                }
//            }
//            else// if(str.length() < tempstr.length())
//            {
//                string newstr = str;
//                tempstr.erase(tempstr.end() - (tempstr.length() - str.length() + 1), tempstr.end());
//                newstr.erase(newstr.length() - 1);
//                if (newstr == tempstr)
//                {
//                    tempstr = str;
//                    if (tempstr.size() > maxSize)
//                    {
//                        maxSize = tempstr.size();
//                        res = tempstr;
//                    }
//                }
//            }
//        }
//        return res;
//    }
//};

void showdp(vector<vector<bool>> &dp,int dpi,int dpj)
{
	for(auto nums:dp)
	{
		for(bool val:nums)
		{
            cout << (val == true)<<" ";
		}
        cout << endl;
	}
    cout <<"--------------------------------------------------------------"<< endl;
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len3 != len1 + len2)
            return false;
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        int n = 0;
        dp[0][0] = true;
        showdp(dp, len1, len2);
        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {
            	if(!i&&!j)
                    continue;;
                cout << i << "  " << j << endl;
                dp[i][j] = (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (j > 0 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                showdp(dp, len1, len2);
            }
        }
        return dp[len1][len2];
    }
};

int main()
{
    vector<string> nums{"aabcc","dbbca","aadbbcbcac" };
	
    Solution s;
    cout << s.isInterleave(nums[0],nums[1],nums[2]) << endl;
    
	//for(auto val:)
        //cout << s.numSquares(3) << endl;

    set<int> st;
    st.insert(3);
    std::max(2, 1);
    //cout << "Hello World" << endl;
	return 0;
}
