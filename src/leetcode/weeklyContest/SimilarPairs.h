/**
 * @file 324_1.cpp
 * @author le@hainanu.edu.cn
 * @brief  统计相似字符串对的数量
 * 解决方案：拍序+判重+字符串判等
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef MAIN_SIMILARPAIRS_H
#define MAIN_SIMILARPAIRS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class SimilarPairs
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

#endif
