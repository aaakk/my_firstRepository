#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class QuickSort
{
public:
    QuickSort(vector<int>& arr):arr(arr)
    {
        sort();
    }

private:
    void sort()
    {
        int left = 0, right = arr.size() - 1;
        quickSort(left, right);
    }

    void quickSort(int left, int right)
    {
        if(left >= right) return;
        int standard = arr[left];
        int i = right;
        for(int j = right; j >= left + 1; j--)
        {
            if(arr[j] > standard)
            {
                if(i != j)
                {
                    std::swap(arr[j], arr[i]);
                }
                i--;
            }
        }
        //i指向的位置的值一定小于等于left的值
        std::swap(arr[left], arr[i]);
        quickSort(i+1, right);
        quickSort(left, i-1);
        // while(i < j)
        // {
        //     while(i < j && arr[j] >= standard)
        //     {
        //         j--;
        //     }
        //     while(i < j && arr[i] <= standard)
        //     {
        //         i++;
        //     }
        //     if(i < j)
        //     {
        //         swap(arr[i], arr[j]); i++; j--;
        //     }
        // }
        // if(i == j && standard < arr[j])
        // {
        //     j--;
        // }
        // swap(arr[left], arr[j]);
        // quickSort(j+1, right);
        // quickSort(left, j-1);
    }

private:
    vector<int>& arr; 
};

class QuickSortList
{

};