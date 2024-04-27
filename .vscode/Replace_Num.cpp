//遍历字符串的方法，可以直接像数组一样通过下标访问字符串中的元素
#include <iostream>
#include <string>
using namespace std;
class Solution{
public:

    string Replace_Num(string s){
        //1、先将数组扩充到number之后的大小,指针i指向原数组的最后一个元素，
        //指针j指向扩充后的数组的最后一个元素
        int sOldIndex=s.size()-1;
        int count=0;

        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){//如果是数字
                count++;
            }
        }
        //扩充字符串的大小,count*5是因为本身数字就占用了一个字符，因此只需要新增加5*count个字符即可
        
        s.resize(s.size()+5*count);
        int sNewIndex=s.size()-1;
        //2、从后往前遍历，如果是字符，直接复制，如果是数字，替换为number

        while(sOldIndex>=0){
            if(s[sOldIndex]>='0'&&s[sOldIndex]<='9'){
                s[sNewIndex--]='r';
                s[sNewIndex--]='e';
                s[sNewIndex--]='b';
                s[sNewIndex--]='m';
                s[sNewIndex--]='u';
                s[sNewIndex--]='n';
            }
            else{
                s[sNewIndex--]=s[sOldIndex];
            }
            sOldIndex--;
        }
        return s;
    }
};

int main(){
    string s="a1b2c325b";
    Solution solu;
    string newString=solu.Replace_Num(s);
    cout<<newString<<endl;
}

// int main(){
//     string s="a1b2c325bzyxhgo";
// //打印a的ascii码
//     for(int i=0;i<s.size();i++){
//         if(s[i]-'a'>=0&&s[i]-'a'<=25){
//             cout<<s[i]<<endl;
//         }
//         //cout<<s[i]<<endl;
        
//     }

//     return 0;
// }


