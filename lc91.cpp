//#include <algorithm>
//#include <iostream>
//#include<array>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    // ����ַ�����Ч��
//    bool validStr(string s)
//    {
//        int len = s.length();
//        // ������Ч
//        if (len == 0)
//            return false;
//        // ���ַ� 0 ��Ч
//        if (s.at(0) == '0')
//            return 0;
//
//        // 0�ַ�ǰ ���ַ���ϴ���26  ��Ч  ��30 40��
//        // �����ڵ� 0 ��Ч
//        bool isZero = false;
//        for (int i = 0; i < len; i++)
//        {
//            if (isZero)
//            {
//                if (s.at(i) == '0')
//                    return false;
//                isZero = false;
//            }
//            else
//            {
//                if (s.at(i) == '0')
//                {
//                    isZero = true;
//                    // 0�ַ�ǰ ���ַ���ϴ���26  ��Ч  ��30 40��
//                    int num = (s.at(i - 1) - '0') * 10;
//                    if (num > 26)
//                        return false;
//                }
//                else
//                    isZero = false;
//            }
//        }
//        return true;
//    }
//    int numDecodings(string s) {
//        int len = s.length();
//       
//        if (!validStr(s))
//        {
//            return 0;
//        }
//        if (len == 1)
//            return 1;
//        if (len == 2)
//        {
//            int num = (s.at(0) - '0') * 10 + (s.at(1) - '0');
//            if (s.at(1) == '0')//   10  20
//                return 1;
//            else if (num <= 26 && num > 10)//  11 -- 26
//                return 2;
//            else // ����26
//                return 1;
//        }
//        vector<int> countNum(len + 1, 0);
//        countNum.at(0) = 1;
//        countNum.at(1) = 1;
//        for (int i = 2; i <= len; i++)
//        {
//            int pos = i - 1;
//            if (s.at(pos) == '0')
//            {
//                countNum.at(i) += countNum.at(i - 2);
//            }
//            else
//            {
//                countNum.at(i) += countNum.at(i - 1);
//                if ((s.at(pos - 1) - '0') * 10 + (s.at(pos) - '0') <= 26 && (s.at(pos - 1) - '0') * 10 + (s.at(pos) - '0') >= 10)
//                {
//                    countNum.at(i) += countNum.at(i - 2);
//                } 
//                
//            }            
//        }
//        return countNum.at(len);
//       
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout << s.numDecodings("1010") << endl;
//	//std::cout << "Hello World!\n";
//}
//
