//长度最小的子数组
#include<iostream>
#include<vector>
using namespace std;
//双指针法
// class Solution{
// public:
//     int minSubArrayLen(int s,vector<int>&nums){
//         int i=0;//滑动窗口的左边界
//         int sum=0;//滑动窗口的和
//         int subLength=INT_MAX;
//         for(int j=0;j<nums.size();j++){
//             sum+=nums[j];

//             while(sum>s){
//                 subLength=j-i+1;
//                 int result=0;
//                 result=result<subLength ? result:subLength;
//                 sum=sum-nums[i++];//这里体现出滑动窗口的精髓之处，
//                                 //不断变更i（子序列的起始位置）
//             }
//         }
//         return subLength==INT_MAX?0:subLength;
//     }
// };

//暴力解法
class Solution{
    public:
    int minSubArrayLen(int s,vector<int>&nums){
        int result=INT_MAX;
        int strLength=0;
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>=s){
                    strLength=j-i+1;
                    result=result<strLength ? result:strLength;
                    break;
                }
            }
        }
        return result==INT_MAX ? 0:result;
    }
};

//暴力解法和双指针解法的区别在于，暴力解法是两层循环，遍历每一个元素时，sum归0，遍历一遍数组，时间复杂度为O(n^2)
//双指针解法是一层循环，遍历每一个数组时，sum值不归0，sum的更新方式为sum-=nums[i++]双指针解法的时间复杂度为O(n)

int main(){
    vector<int> nums={2,3,1,2,4,3};
    int s=5;
    Solution solution;
    int res=solution.minSubArrayLen(s,nums);
    cout<<"数组最小长度为："<<res<<"\n";
}