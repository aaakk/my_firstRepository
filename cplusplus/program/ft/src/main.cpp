#include "gtest/gtest.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// vector<int> preHandle(string& pattern)
// {
//     vector<int> arr(pattern.size(), 0);
//     arr[0] = -1;
//     for(int i = 1; i < pattern.size(); i++)
//     {
//         int j = arr[i - 1] + 1;
//         while(j > 0 && pattern[i - 1] != pattern[j - 1])
//         {
//             j = arr[j - 1] + 1;
//         }
//         arr[i] = j;
//     }
//     return arr;
// }

vector<int> preHandle(string& array)
{
    vector<int> next(array.size());
    next[0] = -1;
    int i = 0, j = -1;
    while(i < array.size() - 1)
    {
        if(j == -1 || array[i] == array[j])
        {
             i++; j++;
             next[i] = j;
        }
        else j = next[j];
    }
    for(auto n : next)
    {
        cout << n << ", ";
    }
    cout << endl;
    return next;
}

vector<int> findSubStr(string text, string pattern)
{
    vector<int> result;
    if(pattern == "" || text == "" || pattern.size() > text.size()) return result;
    vector<int> lpsArray = preHandle(pattern);

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
        }
    }

    return result;
}

void quickSort(vector<int>& arr, int left, int right)
{
    if(left >= right) return;
    int standard = arr[left];
    int i = left + 1, j = right;
    while(i < j)
    {
        while(i < j && arr[j] >= standard)
        {
             j--;
        }
        while(i < j && arr[i] <= standard)
        {
             i++;
        }
        if(i < j)
        {
            swap(arr[i], arr[j]); i++; j--;
        }
     }
     if(i == j && standard < arr[j])
     {
         j--;
     }
     swap(arr[left], arr[j]);
     quickSort(arr, j+1, right);
     quickSort(arr, left, j-1);
}

vector<int> sort(vector<int> arr)
{
    int left = 0, right = arr.size() - 1;
    quickSort(arr, left, right);
    return arr;
} 

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    // vector<int> a = findSubStr("mississiadgasdissippi", "issip");

    //     for(auto n : a)
    // {
    //     cout << n << ", ";
    // }

    // vector<int> m = {0};
    // vector<int> result = sort(m);
    // for(int i = 0; i < m.size(); i++)
    // {
    //     cout << result[i] << ", ";
    // } 
    // cout << endl;
    
}

