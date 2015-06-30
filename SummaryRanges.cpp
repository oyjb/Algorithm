#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> summaryRanges(vector<int> &nums)
	{
		vector<string> vec_str;
		if (nums.size() == 0)
			return vec_str;
		if (nums.size() == 1)
		{
			vec_str.push_back(std::to_string(nums[0]));
			return vec_str;
		}

		vector<int>::const_iterator start,it1,it2;
		for (start = it1 = nums.cbegin(),it2 = it1 + 1; it2 != nums.cend(); ++it1, ++it2)
		{
			if ( (*it1)+1 != (*it2))//间隔了
			{
			    string str = "";
				if (it1 != start)
					str = std::to_string(*start) + "->" + std::to_string(*it1);
				else
				    str = std::to_string(*start);
				vec_str.push_back(str);
				start = it2;
			}
		}
		string str = "";
		if (it1 != start)
			str = std::to_string(*start) + "->" + std::to_string(*it1);
		else
			str = std::to_string(*start);
			
		vec_str.push_back(str);
		
		return vec_str;
	}
};

int main()
{
	vector<int> vec = {0,1,2,4,5,7};
	
	Solution solution;
	vector<string> str_vec = solution.summaryRanges(vec);

	for(auto it : str_vec)
		cout << it << "   ";
	cout << endl;

	return 0;
}
