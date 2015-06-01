#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution
{
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		//初始化numCourse个list<int>
		vector<list<int> > g(numCourses, list<int>());

		for (int i = 0; i< prerequisites.size(); i++)
			g[prerequisites[i].first].push_back(prerequisites[i].second);

		//存储已访问节点
		vector<bool> visited(prerequisites.size(), false);

		//
		vector<bool> rec(prerequisites.size(), false);

		for (int i = 0; i < g.size(); i++)
		if (isCycle(g, visited, rec, i))
			return false;

		return true;
	}


	bool isCycle(vector<list<int>>& g, vector<bool>& visited, vector<bool>& rec, int n)
	{
		if (visited[n] == false)
		{
			visited[n] = true;
			rec[n] = true;

			for (auto iter = g[n].begin(); iter != g[n].end(); ++iter)
			{
				if (isCycle(g, visited, rec, *iter))
					return true;
				if (rec[*iter])
					return true;
			}

			rec[n] = false;
		}

		return false;
	}
};