#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0) return ans;
        sort(strs.begin(), strs.end());
        for(int i=0;i<strs[0].size();i++)//遍历第一个字符串的所有字符
        {
            char temp = strs[0][i];
            printf("strs[0]: %c\n", strs[0][0]);
            int j;
            for(j=1;j<strs.size();j++)//遍历所有的字符串,看看第i个字符是否相等，如果相等，继续遍历下一个字符串，否则退出循环
            {
                if(temp != strs[j][i]) //如果不相等，直接退出循环;否则继续遍历下一个字符串
                    break;
            }
            if(j >= strs.size()) {//说明所有的字符串的第i个字符都是一样的，将其加入到ans中
                ans += temp;
                }
            else break;
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<string> strs1 = {"flower", "flow", "flightd"};
    cout << "Test Case 1: " << solution.longestCommonPrefix(strs1) << endl;
    
    // Test Case 2
    printf("我运行到这里了\n");
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Test Case 2: " << solution.longestCommonPrefix(strs2) << endl;
    
    // Test Case 3
    vector<string> strs3 = {"apple", "ape", "app"};
    cout << "Test Case 3: " << solution.longestCommonPrefix(strs3) << endl;
    
    return 0;
}


// class Solution {
//     public:
//     string longestCommonPrefix(vector<string>& strs){
//         string ans="";
//         if(strs.size()==0) return ans;

//         sort(strs.begin(),strs.end());
//         for(int i=0;i<strs[0].size();i++){
//             char temp=strs[0][i];

//             int j;
//             for(j=1;j<strs.size();j++){
//                 if(temp!=strs[j][i]) break;
//             }
//             if(j>strs.size()){
//                 ans+=temp;  
//             }
//             else break;
//         }
//         return ans;
//     }
// };