#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
// Define the Solution class here
class Solution{
    public:
    vector<vector<int>> foursum(vector<int>&nums,int target){
        vector<vector<int>>result;
        #include<algorithm> // Include the <algorithm> header for the sort function

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            //剪枝处理
            if(nums[i]>target && nums[i]>0) break;;
            //对nums[i]去重
            if(i>0 && nums[i]==nums[i-1] ) continue;
            for(int j=i+1;j<nums.size();j++){
                //二级剪枝处理
                if(nums[i]+nums[j]>target && nums[i]+nums[j]>0) break;
                int left=j+1;
                int right=nums.size()-1;
                if(j>i+1 && nums[j]==nums[j-1]) continue;//对nums[j]去重
                while(left<right){
                    
                    if((long)nums[i]+nums[j]+nums[left]+nums[right]>target){
                        right--;
                    }else if((long)nums[i]+nums[j]+nums[left]+nums[right]<target){
                        left++;
                    }else{
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        //对nums[left]和nums[right]去重
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};
int main() {
    Solution solution;

    // Test Case 1
    std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    std::vector<std::vector<int>> result1 = solution.foursum(nums1, target1);
    std::cout << "Test Case 1: ";
    for (const auto& quad : result1) {
        std::cout << "[";
        for (const auto& num : quad) {
            std::cout << num << " ";
        }
        std::cout << "]";
    }
    std::cout << std::endl;

    // Test Case 2
    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    std::vector<std::vector<int>> result2 = solution.foursum(nums2, target2);
    std::cout << "Test Case 2: ";
    for (const auto& quad : result2) {
        std::cout << "[";
        for (const auto& num : quad) {
            std::cout << num << " ";
        }
        std::cout << "]";
    }
    std::cout << std::endl;

    // Test Case 3
    std::vector<int> nums3 = {-1, 0, 1, 2, -1, -4};
    int target3 = -1;
    std::vector<std::vector<int>> result3 = solution.foursum(nums3, target3);
    std::cout << "Test Case 3: ";
    for (const auto& quad : result3) {
        std::cout << "[";
        for (const auto& num : quad) {
            std::cout << num << " ";
        }
        std::cout << "]";
    }
    std::cout << std::endl;

    return 0;
}// Test Case 1
std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
int target1 = 0;
std::vector<std::vector<int>> result1 = solution.foursum(nums1, target1);
std::cout << "Test Case 1: ";
for (const auto& quad : result1) {
    std::cout << "[";
    for (const auto& num : quad) {
        std::cout << num << " ";
    }
    std::cout << "]";
}
std::cout << std::endl;

// Test Case 2
std::vector<int> nums2 = {2, 2, 2, 2, 2};
int target2 = 8;
std::vector<std::vector<int>> result2 = solution.foursum(nums2, target2);
std::cout << "Test Case 2: ";
for (const auto& quad : result2) {
    std::cout << "[";
    for (const auto& num : quad) {
        std::cout << num << " ";
    }
    std::cout << "]";
}
std::cout << std::endl;

// Test Case 3
std::vector<int> nums3 = {-1, 0, 1, 2, -1, -4};
int target3 = -1;
std::vector<std::vector<int>> result3 = solution.foursum(nums3, target3);
std::cout << "Test Case 3: ";
for (const auto& quad : result3) {
    std::cout << "[";
    for (const auto& num : quad) {
        std::cout << num << " ";
    }
    std::cout << "]";
}
std::cout << std::endl;