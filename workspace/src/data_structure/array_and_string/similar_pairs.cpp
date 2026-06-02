#include <algorithm>
#include <string>
#include <vector>

namespace ns_array_similar_pairs {

class Solution
{
public:
	int similarPairs(std::vector<std::string> &words)
	{
		for (auto &word : words)
		{
			std::sort(word.begin(), word.end());
			word.erase(std::unique(word.begin(), word.end()), word.end());
		}

		int res = 0;
		for (int i = 0; i < words.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (words[i] == words[j])
				{
					res++;
				}
			}
		}
		return res;
	}
};
} // namespace ns_array_similar_pairs
