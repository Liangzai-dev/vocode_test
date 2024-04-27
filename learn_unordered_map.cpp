
// #include<iostream>
// #include<unordered_map>
// using namespace std;

// //创建一个unordered_map，然后插入一些元素，然后遍历这个unordered_map
// int main(){
//     unordered_map<int,int>record;
//     record.insert(pair<int,int>(1,2));
//     record.insert(pair<int,int>(3,4));
//     record.insert(pair<int,int>(5,6));
//     record.insert(pair<int,int>(7,8));
//     record.insert(pair<int,int>(9,10));
   
//     //遍历unordered_map
//      for(auto itor=record.begin();itor!=record.end();itor++){
//         //first是key，second是value
//         cout<<itor->first<<" "<<itor->second<<endl;//
        
//      }
//     return 0;
// }

#include <iostream>
#include <string>
#include <unordered_map>
 
int main ()
{
    std::unordered_map<int, std::string> dict = {{1, "one"}, {2, "two"}};
    dict.insert({3, "three"});
    dict.insert(std::make_pair(4, "four"));
    dict.insert({{4, "another four"}, {5, "five"}});
 
    const bool ok = dict.insert({1, "another one"}).second;
    std::cout << "插入 1 => \"another one\" " 
              << (ok ? "成功" : "失败") << '\n';
 
    std::cout << "内容：\n";
    for (auto& p : dict)
        std::cout << ' ' << p.first << " => " << p.second << '\n';
}