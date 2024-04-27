#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @class Soution
 * @brief Represents a solution for finding the count of quadruplets whose sum is zero.
 */
class Soution{
    public:
    /**
     * @brief Calculates the count of quadruplets whose sum is zero.
     * @param A The first vector of integers.
     * @param B The second vector of integers.
     * @param C The third vector of integers.
     * @param D The fourth vector of integers.
     * @return The count of quadruplets whose sum is zero.
     */
    int fourSumCount(vector<int>&A,vector<int>&B,vector<int>&C,vector<int>&D){
        // Implementation code...
    }
};
/**
 * @class Soution
 * @brief 解决方案类，用于计算四个数组的和为零的组合数量
 */
class Soution{
    public:
    /**
     * @brief 计算四个数组的和为零的组合数量
     * @param A 第一个数组
     * @param B 第二个数组
     * @param C 第三个数组
     * @param D 第四个数组
     * @return 和为零的组合数量
     */
    int fourSumCount(vector<int>&A,vector<int>&B,vector<int>&C,vector<int>&D){
        // 首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
        unordered_map<int,int> map;
        // 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
        for(int a:A){
            for(int b:B){
                map[a+b]++;
            }
        }
        // 定义int变量count，用来统计 a+b+c+d = 0 出现的次数。
        int count=0;
        // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
        for(int c:C){
            for(int d:D){
                if(map.find(0-c-d)!=map.end())
                count+=map[0-c-d];
                //因为a+b的值可能有多个，所以出现多少次就加上多少次。不能够使用count++。            
            }
        }
        return count;
        // 最后返回统计值 count 就可以了
    }
};
int main(){
    vector<int> A={0,0,0,0};
    vector<int> B={0,0,0,0};
    vector<int> C={0,0,0,0};
    vector<int> D={0,0,0,0};
    Soution s;
    cout<<s.fourSumCount(A,B,C,D)<<endl;
    return 0;

}