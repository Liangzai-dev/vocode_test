#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//暴力解法
// class Solution{
// public:
//      vector<int> sortedSquares(vector<int> &A){

//         for(int i=0;i<A.size();i++){
//             A[i]=A[i]*A[i];
//         }
//         sort(A.begin(),A.end());//快速排序
//         return A;
//     }
// };

//双指针解法
/*核心思想在于：数组A已经排好序，那么A中最大的数一定是在数组的两端，
所以我们可以使用双指针，分别指向数组的两端，
然后比较两个指针指向的数的平方的大小，将较大的数的平方放到结果数组的最后面
然后将较大的数的指针向中间移动，直到两个指针相遇*/

class Solution{
    public:
    vector<int> sortedSquares(vector<int> &A){
        vector<int> res(A.size());        
        for(int i=0, j=A.size()-1,k=A.size()-1; i<=j;k-- ){
            if(A[i]*A[i]>A[j]*A[j]){
                res[k]=A[i]*A[i];
                i++;
            }else{
                res[k]=A[j]*A[j];
                j--;
            }
        }
        return res;
    }
};

int main(){
    vector<int> A={-4,-3,-2,-1,0,1,2,5};
    Solution s;
    vector<int> res=s.sortedSquares(A);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"\n";
    }
}