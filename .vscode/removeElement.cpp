#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

/**
    * Removes all occurrences of a specified value from the given vector.
    * 
    * @param nums The vector of integers from which to remove elements.
    * @param val The value to be removed from the vector.
    * @return The number of elements remaining in the vector after removal.
    */
class Solution{
    public:
    int removeElement(vector<int>&nums,int val){
         //slowindex用于指向新数组下标
         //fastindex寻找新数组的元素，新数组就是不含目标元素的数组
        int slowindex=0;
        for(int fastindex=0;fastindex<nums.size();fastindex++){
        //如果不等于目标元素，就把这个元素放到新数组中，找到目标元素，就跳过
            if(nums[fastindex]!=val){     
                nums[slowindex]=nums[fastindex];
                slowindex++;
            }
        }
        return slowindex;
    }
};

int main(){
    Solution s;
    vector<int>nums={0,1,2,2,3,0,4,2};
    int val=2;

    int ans=s.removeElement(nums,val);
    for(int i=0;i<ans;i++){
        cout<<nums[i]<<" ";
    }
}