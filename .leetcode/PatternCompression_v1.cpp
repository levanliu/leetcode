//============================================================================
// Name        : PatternCompression.cpp
// Author      : Phill King
// Version     :
// Copyright   : PK
// Description : Pattern Compression
//============================================================================

#include <iostream>
#include <string.h>
#include <iostream>

#define DEBUG

bool bDebug = false;

using namespace std;

class Solution
{

	class RepPat
	{
	public:
		int start = -1;
		int end = -1;
		int stepSize = 0;
		int compressedSize = 0;
		int offset = 0;
		RepPat(int s, int e, int ss, int cs, int re)
		{
			start = s;
			end = e;
			stepSize = ss;
			compressedSize = cs;
			offset = re;
		}
		bool operator<(const RepPat &b) const
		{
			if (end == b.end)
			{
				return start > b.start;
			}
			return end < b.end;
		}
	};

	using Matrix = vector<vector<int>>;

private:
	vector<int> IDLines;

public:
	vector<RepPat> getRepIntervals(int start, int end)
	{
		//		cout<<"Get repeated sub from: "<<start<<" to "<<end<<endl;

		int size = end - start + 1;
		int offset = start;

		vector<int> prev(size, -1);

		unordered_map<int, int> idxMap;
		for (int i = 0; i < size; i++)
		{
			const int &cur = IDLines[i + offset];
			if (idxMap.count(cur) != 0)
			{
				prev[i] = idxMap[cur];
			}
			idxMap[cur] = i;
		}

		Matrix dpRepeated(size + 1, vector<int>(size + 1));
		vector<RepPat> intervals;

		for (int j = 0; j < size; j++)
		{
			if (IDLines[offset] == IDLines[offset + j])
			{
				dpRepeated[0][j] = 1;
			}
		}

		for (int j = 1; j < size; j++)
		{
			for (int i = prev[j]; i > 0; i--)
			{
				if (i <= 0 || ((size + i) / 2 + 1 < j))
				{
					break;
				}
				if (dpRepeated[i][j] < 0)
				{
					i = i + dpRepeated[i][j] + 1;
					continue;
				}
				if (IDLines[offset + i] == IDLines[offset + j])
				{
					dpRepeated[i][j] = dpRepeated[i - 1][j - 1] + 1;
				}
				int curSize = dpRepeated[i][j];
				int stepSize = j - i;
				if (curSize > 0)
				{
					int k = 1;
					for (; j + k < size; k++)
					{
						if (IDLines[offset + i + k] == IDLines[offset + j + k])
						{
							dpRepeated[i + k][j + k] = ++curSize;
						}
						else
						{
							break;
						}
					}

					if (curSize >= stepSize && curSize >= 3)
					{
						int s = i + k - curSize + offset;
						int e = j + k - 1 + offset;

						int totalSize = e - s + 1;
						int remain = totalSize % stepSize;
						intervals.push_back({s, e, stepSize, 0, remain});
						//					for(int x=0; x<=remain; x++)
						//						intervals.push_back({s+x , e-remain+x, stepSize, 0, 0});
						//					int times = totalSize/stepSize;
						//					if(times>=3){
						//						int ts = s+remain+1;
						//						int te = e+1-stepSize;
						//						for(int x=0; ts+x<s+stepSize; x++ ){
						//							intervals.push_back({ts+x , te+x, stepSize, 0, 0});
						//						}
						//					}

						// skip the duplicated interval

						for (int l = 0; l + stepSize < k; l++)
						{
							int next = max(dpRepeated[i + l][j + l], (int)(i + l - prev[i + l]));
							dpRepeated[i + l][j + l] = -next;
						}
						for (int l = k - stepSize; l < k; l++)
						{
							dpRepeated[i + l][j + l] = -1;
						}
						//					for(int y=s+stepSize; y<e; y+=stepSize){
						//						for(int m=0; y+m<=e; m++){
						//							dpRepeated[s+m - offset][y+m-offset] = -dpRepeated[s+m - offset][y+m-offset]-stepSize;
						//						}
						//					}
					}
					else
					{
						for (int l = 0; l < k; l++)
						{
							dpRepeated[i + l][j + l] = -1;
						}
					}
				}
				if (curSize > 0)
				{
					i = prev[i] + 1;
				}
			}
		}

		std::sort(intervals.begin(), intervals.end());
		if (bDebug)
		{

			if (!intervals.empty())
			{
				for (auto item : intervals)
				{
					int times = (item.end - item.start + 1) / item.stepSize;
					cout << "start: " << item.start << " end:" << item.end << " step size: "
						 << item.stepSize << " times: " << times << " offset: " << item.offset << endl;
				}
				cout << "interval number: " << intervals.size() << endl;
			}
		}

		return intervals;
	}

	vector<int> compressSubPat(RepPat &pat, vector<int> &res)
	{
		int start = pat.start;
		int end = pat.start + pat.stepSize - 1;
		int times = (pat.end - pat.start + 1) / pat.stepSize;
		res.push_back(-times);
		compressRange(start, end, res);
		res.push_back(-1);
		pat.compressedSize = res.size();
		return res;
	}

	vector<int> compressRangePre(int start, int end)
	{
		vector<int> res;
		vector<RepPat> pats = getRepIntervals(start, end);
		if (pats.empty())
		{

			for (int i = start; i <= end; i++)
			{
				res.push_back(i);
			}
			return res;
		}

		std::sort(pats.begin(), pats.end(), [](const RepPat &a, const RepPat &b)
				  {
			if(a.start == b.start){
				return a.end>b.end;
			}
			return a.start<b.start; });

		int left = start;
		int pSize = pats.size();
		bool overlap = false;
		for (int i = 0; i < pSize; i++)
		{
			vector<RepPat> curPats;
			RepPat &p = pats[i];
			int curStart = p.start;
			int curEnd = p.end;
			int next = i;
			curPats.push_back(p);
			for (int j = i + 1; j < pSize; j++)
			{
				if (pats[j].start > curEnd)
					break;
				next = j;
				curPats.push_back(pats[j]);
				if (pats[j].start >= curStart && (pats[j].end) <= curEnd)
				{
					continue;
				}
				if (pats[j].start <= curEnd && (pats[j].end) > curEnd)
				{
					curEnd = pats[j].end;
					overlap = true;
				}
			}

			for (int j = left; j < curStart; j++)
			{
				res.push_back(j);
			}

			if (!overlap && p.offset == 0)
			{
				compressSubPat(p, res);
			}
			else
			{
				compressRange(curStart, curEnd, curPats, res);
			}

			left = curEnd + 1;
			i = next;
			overlap = false;
		}

		for (; left <= end; left++)
		{
			res.push_back(left);
		}

		return res;
	}

	vector<int> compressRange(int first, int last, vector<int> &res)
	{
		vector<RepPat> pats = getRepIntervals(first, last);
		if (pats.empty())
		{
			for (int i = first; i <= last; i++)
			{
				res.push_back(i);
			}
			return res;
		}
		return compressRange(first, last, pats, res);
	}

	vector<int> compressRange(int first, int last, vector<RepPat> &pats, vector<int> &res)
	{

		sort(pats.begin(), pats.end());
		int offset = first;
		int size = last - first + 1;
		Matrix dpSize(size + 1, vector<int>(size + 1));
		Matrix dpStep(size + 1, vector<int>(size + 1));
		Matrix dpTimes(size + 1, vector<int>(size + 1));
		Matrix dpPath(size + 1, vector<int>(size + 1));
		Matrix rowIdx(size + 1);

		// pre-process the tables to fill the information of repeated section
		for (const auto &p : pats)
		{
			int s = p.start - offset;
			int e = p.end - offset;
			int stepSize = p.stepSize;
			for (int j = s + stepSize * 2 - 1, times = 2; j <= e; j += stepSize, times++)
			{
				if (j - s < 3)
					continue;
				for (int k = 0; k + j <= e; k += 1)
				{
					dpStep[s + k][j + k] = stepSize;
					dpTimes[s + k][j + k] = times;
				}
			}
		}

		// calculate the size for each loop section
		std::function<void(int, int)> calLoopSection;
		calLoopSection = [&](int start, int end)
		{
			for (int i = end; i >= start; i--)
			{
				if (dpSize[i][end] > 0)
				{
					if (dpStep[i][end] > 0)
					{
						dpPath[i][end] = end + 1;
					}
					continue;
				}
				int step = end - i + 1;
				dpSize[i][end] = dpSize[i + 1][end] + 1;
				dpPath[i][end] = i + 1;
				if (step <= 3)
					continue;

				for (const auto &idx : rowIdx[i])
				{
					if (idx > end)
						break;
					if (dpSize[i][end] > dpSize[i][idx] + dpSize[1 + idx][end])
					{
						dpSize[i][end] = dpSize[i][idx] + dpSize[1 + idx][end];
						dpPath[i][end] = idx + 1;
					}
				}
			}
		};

		for (auto &p : pats)
		{
			const int s = p.start - offset;
			const int e = s + p.stepSize - 1;
			const int end = p.end - offset;
			int stepSize = p.stepSize;
			for (int k = 0; /*k<stepSize &&*/ (e + k + stepSize) <= end; k++)
			{
				calLoopSection(s + k, e + k);
				int cSize = dpSize[s + k][e + k] + 2;
				for (int y = s + k + stepSize * 2 - 1; y <= end; y += stepSize)
				{
					for (int len = 0; y + len <= end && len <= 0; len += stepSize)
					{
						dpSize[s + k][y + len] = cSize;
						rowIdx[s + k].push_back(y + len);
						dpPath[s + k][y + len] = y + len + 1;
					}
				}
			}
		}

		int curEnd = last - offset;
		for (int i = curEnd; i >= 0; i--)
		{
			if (dpSize[i][curEnd] > 0)
			{
				dpPath[i][curEnd] = curEnd + 1;
				continue;
			}
			dpSize[i][curEnd] = dpSize[i + 1][curEnd] + 1;
			dpPath[i][curEnd] = i + 1;
			for (const auto &idx : rowIdx[i])
			{
				if (dpSize[i][curEnd] > dpSize[i][idx] + dpSize[idx + 1][curEnd])
				{
					dpSize[i][curEnd] = dpSize[i][idx] + dpSize[1 + idx][curEnd];
					dpPath[i][curEnd] = idx + 1;
				}
			}
			//			cout<<setw(4)<<dpPath[i][last]<<endl;;
		}

		// define the function to construct result by tracking the path
		std::function<vector<int>(int, int, vector<int> &)> constructRes;
		constructRes = [&](int start, int end, vector<int> &res)
		{
			if (end < start)
				return res;
			int cur = start;
			for (int i = start; i <= end; i++)
			{
				int next = dpPath[cur][end];
				if (next == 0)
				{
					cout << "something wrong" << endl;
					return res;
				}
				int bodySize = next - cur;
				if (bodySize == 1)
				{
					res.push_back(cur + offset);
				}
				else
				{
					int stepSize = dpStep[cur][next - 1];
					int times = dpTimes[cur][next - 1];
					if (times == 0)
					{
						cout << "something wrong" << endl;
					}
					res.push_back(-times);
					vector<int> tmp = constructRes(cur, cur + stepSize - 1, res);
					res.push_back(-1);
					i = next - 1;
				}
				cur = next;
			}

			return res;
		};

		constructRes(0, size - 1, res);
		return res;
	}

	vector<int> unCompress(const vector<int> &comp)
	{
		Matrix st;
		vector<int> cur;
		st.push_back(cur);
		stack<int> repeated;
		for (auto c : comp)
		{
			if (c == -1)
			{
				vector<int> tmp = st.back();
				st.pop_back();
				int rep = repeated.top();
				repeated.pop();
				for (int i = 0; i < rep; i++)
				{
					st.back().insert(st.back().end(), tmp.begin(), tmp.end());
				}
			}
			else if (c < -1)
			{
				repeated.push(-c);
				vector<int> tmp;
				st.push_back(tmp);
			}
			else
			{
				st.back().push_back(c);
			}
		}
		return st.back();
	}

	vector<string> compressPattern(const vector<string> &patternLines)
	{
		//		auto start = std::chrono::system_clock::now();
		// pre-process: replace the string with ID.
		int size = patternLines.size();
		unordered_map<string, int> patternIDMap;
		vector<int> cntMap(size + 1);
		vector<string> IDPatternMap;
		int id = 0;
		for (auto str : patternLines)
		{
			if (patternIDMap.count(str) == 0)
			{
				IDLines.push_back(id);
				patternIDMap.insert({str, id++});
				IDPatternMap.push_back(str);
			}
			else
			{
				IDLines.push_back(patternIDMap[str]);
			}
		}

		if (bDebug)
			cout << "Original size = " << size << endl;

		// compress the pattern
		vector<int> idResult = compressRangePre(0, size - 1);

		if (bDebug)
			cout << "Compressed Size = " << idResult.size() << endl;

		vector<string> resLines;
		for (auto id : idResult)
		{
			if (id == -1)
			{
				resLines.push_back("end");
			}
			else if (id < -1)
			{
				string loopStart = "loop ";
				loopStart += to_string(-id);
				resLines.push_back(loopStart);
			}
			else
			{
				resLines.push_back(IDPatternMap[IDLines[id]]);
			}
		}
		//
		//		auto time1 = std::chrono::system_clock::now();
		//		std::chrono::duration<double> elapsed_seconds = time1 -start;
		//		std::cout<<std::fixed<<std::setprecision(6)<<"It takes  "<<elapsed_seconds.count() <<" seconds to get the solution"<<endl;
		//

		//		vector<int> uncomp = unCompress(idResult);
		//		vector<string> unPat;
		//		for(auto id:uncomp){
		//			unPat.push_back(IDPatternMap[IDLines[id]]);
		//		}
		//
		//		if(unPat != patternLines){
		////			for(size_t i=0; i<patternLines.size(); i++){
		////				if(patternLines[i] != unPat[i]){
		////					cout<<"line: "<<i<< " "<<endl<<"Org: "<<patternLines[i]<<endl<<"New: "<<unPat[i]<<endl;
		////				}
		////			}
		//			cout<<"Incorrect compression"<<endl;
		//		}

		return resLines;
	}
};

int main(int argc, char *argv[])
{
	std::string file_name = "data.txt";
	if (argc >= 2)
	{
		file_name = argv[1];
	}

	if (argc == 3 && strcasecmp(argv[2], "debug") == 0)
	{
		bDebug = true;
	}

	size_t pos = file_name.find_last_of(".");
	std::string outputFileName = file_name.substr(0, pos);
	outputFileName += ".out";

#ifndef ONLINE_DEBUG

	freopen(file_name.c_str(), "r", stdin);
	//	freopen(outputFileName.c_str(), "w", stdout);
	FILE *outputFile = fopen(outputFileName.c_str(), "w");
#endif
	// read inputs
	char tmp[260] = {0};
	vector<string> inputs;
	while (scanf("%s", tmp) != EOF)
	{
		inputs.push_back(tmp);
	}
	Solution pc;
	vector<string> res = pc.compressPattern(inputs);

	//	for(const auto& str:res){
	//		cout<<str<<endl;
	//	}

#ifndef ONLINE_DEBUG

	for (const auto &str : res)
	{
		fprintf(outputFile, "%s\n", str.c_str());
	}

	fclose(outputFile);
#endif
	return 0;
}
