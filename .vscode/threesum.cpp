//刷题的目的：1、有解题的思路 
//2、有了思路自己还要会把它写出来，例如怎么将26个字母映射到一个数组当中，怎么遍历vector，熟悉c++语法

#include<bits/stdc++.h>
using namespace std;
//哈希法
class Solution{
    public:
     vector<vector<int>>threeSum_01(vector<int>&nums){
            int  len=nums.size();
            vector<vector<int>>ans;//

            sort(nums.begin(),nums.end());
            for(int i=0;i<len;i++){
                if(i!=0 && nums[i]==nums[i-1]) continue;//跳过i代表的元素
                    unordered_map<int,int> m;
                    for(int j=i+1;j<len;j++){
                        if(m.count(-nums[i]-nums[j])){//-nums[i]-nums[j]的值表示第三个数
                            //如果m.count(-nums[i]-nums[j])返回非0值，说明在m中找到了这个值
                            ans.push_back({nums[i],nums[j],-nums[i]-nums[j]});//vector的插入使用push_back
                            while(j+1<len && nums[j]==nums[j+1]) j++;
                        }
                        else m.insert(pair<int,int>(nums[j],j));
                    }
            }
            return ans;
    }

    /**
     * Finds all unique triplets in the given vector that sum up to zero.
     *
     * @param nums The input vector of integers.
     * @return A vector of vectors, where each inner vector represents a unique triplet that sums up to zero.
     *         If no such triplets are found, an empty vector is returned.
     */
    vector<vector<int>> threeSum_02(vector<int>& nums){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());//先对数组进行排序
        if(nums.size()<3){
            return {};
            cout<<"数组长度小于3"<<endl;
        }

        for(int i=0;i<nums.size();i++){
            //对a进行去重
            if(i>0 && nums[i]==nums[i-1]) continue;

            //从i=0开始遍历数组，另外定义两个指针left=i+1,right=nums.size()-1
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[i]>0) return {};
                //如果num[i]+nums[left]+nums[right]>0,则right--；如果nums[i]+nums[left]+nuns[right]<0,则left--
                if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                }else if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                }else{
                    //如果nums[i]+nums[left]+nums[right]==0,则将这三个数加入到ans中
                    result.push_back({nums[i],nums[left],nums[right]});
                    //当nums[left]==nums[left+1]时，跳过这个元素
                    while(left<right && nums[left]==nums[left+1]) left++;
                    //当nums[right]==nums[right-1]时，跳过这个元素
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }                        
            }
        }
        return result;   
    }
};




// int main(){
//     Solution s;
//     vector<int>nums={-1,0,1,2,-1,-4};
//     vector<vector<int>>ans=s.threeSum_01(nums);
//     for(auto v:ans){
//         for(auto i:v){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

int main(){
    Solution s;
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=s.threeSum_02(nums);
    for(auto v:ans){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}