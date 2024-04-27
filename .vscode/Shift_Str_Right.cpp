#include<string>
#include<iostream>
using namespace std;


class Solution{
public:
//版本一：申请额外空间使用substr函数
        // string Shift_Str_Right(string s,int n){
        //     //substr(starting index, length): Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
        //     string result=s.substr(s.length()-n)+s.substr(0,s.length()-n);
        //     return result;
        // }

//版本二：不申请额外空间，直接在原字符串上操作
//思路：先将整个字符串翻转，然后将前n个字符翻转，再将后面的字符翻转
        void reverse(string &s, int start, int end) {
                        while (start < end) {
                            swap(s[start], s[end]);
                            start++;
                            end--;
                        }
                    }

        // void reverse(string &s,int start,int end){
            //     for(int i=start,j=end;i<j;i++,j--){
            //         swap(s[i],s[j]);
            //     }
            // }
        string Shift_Str_Right(string s,int n){
            reverse(s,0,s.size()-1);
            reverse(s,0,n-1);
            reverse(s,n,s.size()-1);
            return s;            
        }

        void reverse(string &s, int start, int end){
            for(int i=start, j=end;i<j;i++, j--){
                swap(s[i], s[j]);
            }
        }
};

int main(){

    string s="abcdefg";
    Solution solu;
    cout<<solu.Shift_Str_Right(s,2)<<endl;

    cout<<"hello world"<<endl;
    return 0;

}