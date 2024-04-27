//创建一个长度为26的数组，用来存放26个字母出现的次数，
//然后遍历字符串，统计每个字母出现的次数，最后遍历数组，输出次数不为0的字母及其次数。
#include<string>
#include<iostream>
using namespace std;

class Solution{
public:

    bool isAnagram(string s,string t){
        int record[26]={0};
        for(int i=0;i<s.size();i++){
            //s[i]-'a'是为了记录s中每个字母在record中的位置
            record[s[i]-'a']++;
        }

        for(int j=0;j<t.size();j++){
            record[t[j]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(record[i]!=0){
                return false;
            }
        }

        return true;
    }
 };

 int main(){
        string s="anagram";
        string t="nbgaram";
        Solution sol;
        cout<<sol.isAnagram(s,t)<<endl;
        return 0;
 }
 
 
 
 
 
 