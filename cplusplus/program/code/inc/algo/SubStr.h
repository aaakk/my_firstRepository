#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

class KMP
{
public:
    KMP(const string& text, const string& pattern):text(text), pattern(pattern)
    {}

    vector<int> findAllSubStr(int nums = -1)
    {
        vector<int> result;
        if(pattern == "" || text == "" || pattern.size() > text.size()) return result;
        vector<int> lpsArray = preHandle();

        int findNum = 0;
        int j = 0;
        for(int i = 0; i < text.size(); i++)
        {
            while(j > 0 && text[i] != pattern[j])
            {
                j = lpsArray[j];
            }
            if(text[i] == pattern[j])
            {
                j++;
            }
            if(j == pattern.size())
            {
                result.push_back(i+1-j);
                if(nums > 0 && ++findNum >= nums)
                {
                    break;
                }
            }
        }
        return result;
    }

    vector<int> preHandle()
    {
        vector<int> next(pattern.size());
        next[0] = -1;
        int i = 0, j = -1;
        while(i < pattern.size() - 1)
        {
            if(j == -1 || pattern[i] == pattern[j])
            {
                i++; j++;
                next[i] = j;
            }
            else j = next[j];
        }
        return next;
    }

private:
    const string& pattern;
    const string& text;
};
