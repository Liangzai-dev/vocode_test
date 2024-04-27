//思路：1、移除多余的空格
//2、翻转整个字符串
//3、翻转每个单词
using namespace std;
#include <iostream>
#include <string>
class Solution{
    public:
    //移除多余的空格
    void removeExtraSpaces(string &s){
            //slowindex用于指向新字符串数组下标
            //fastindex寻找新字符串数组的元素，新字符串数组就是不含空格的字符串数组

            //处理字符串开头多余的空格
            int start=0;
            while(s[start]==' '){
                start++;
            }
            s=s.substr(start);

            //处理字符串结尾多余的空格
            int end=s.size()-1;
            while(s[end]==' '){
                end--;
            }
            s=s.substr(0,end+1);

            int slowindex=0;
            //如果没有多余的空格，就把这个元素放到新数组中，有多余空格，就跳过
            for(int fastindex=0;fastindex<s.size();fastindex++){
                if(s[fastindex]==' '&&s[fastindex-1]==' '){
                    continue;
                }else{
                    s[slowindex++]=s[fastindex];
                }
            }
            s.resize(slowindex);//不重新设置的话，s的长度不会改变
    }


//substr()：复制子字符串，要求从指定位置开始，并具有指定的长度。如果没有指定长度，则子字符串将延伸到字符串的末尾。
    //翻转整个字符串
    void reverseString(string &s,int start, int end){
        for(int i=start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }

    //翻转每个单词
    string reverseWords(string s){
        removeExtraSpaces(s);
        reverseString(s,0,s.size()-1);
        int start =0;//start指向每个单词的开头
        for(int i=0;i<=s.size();i++){
            //达到空格或者串尾，说明单词结束，进行翻转
            if(s[i]==' '||i==s.size()){//i==s.size()是为了处理最后一个单词
                reverseString(s,start,i-1);
                start=i+1;//一个单词结束后，将start指向下一个单词的开头
            }   
        }
        return s;
    }
};

int main(){
    Solution s;
    string str="the sky is blue";
    cout<<s.reverseWords(str);
    return 0;
}