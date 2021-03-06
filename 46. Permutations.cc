/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include <iostream>
#include <algorithm>

using namespace std;

/*
next-permutation 
	模板函数， 功能是按照默认 operator< 生成指向容器的下一个词典排列，即 全排列中的下一个词典序列
	
	这个 如果 是有下一个 词典排序 则 返回true 并且将 序列变成下一个词典排序， 如果没有下一个 则 返回true 并将其 按照 < 排好序

*/

class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
    	vector<vector<int>> mul;

    	do
    	{
    		mul.push_back(nums);
    	}while(next_permutation(nums.begin(), nums.end()));

    	return mul;
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		
		vector<vector<int>> re;
		if(nums.empty())
			return re;
		
		permutation(re, nums, 0);

		return re;
    }
	
	void  permutation(vector<vector<int>>& re, vector<int>& nums, int pos)
	{
		if(pos == nums.size())
		{
			re.push_back(nums);
		}

		for(int i=pos; i<nums.size(); ++i)
		{
			swap(nums[i], nums[pos]);
			permutation(re, nums, pos+1);
			swap(nums[i], nums[pos]);
		}
	}
};

int main()
{
	vector<int> nums{1,2,3};
	Solution a;
	auto re  = a.permute(nums);

	for(const auto& i: re)
	{
		for(const auto& j : i)
			cout<<j<<" ";
		cout<<endl;
	}
}