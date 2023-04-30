#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

static int	max_len_of_elements(vector<int> &arr)
{
	string cmp_str = "";
	int max_len = 0;
	for(int i = 0; i < arr.size(); ++i)
	{
		cmp_str = to_string(arr[i]);
		if (cmp_str.length() > max_len)
			max_len = cmp_str.length();
	}
	return max_len;
}

void	print(vector<int> &arr)
{
	for(int i = 0; i < arr.size(); ++i)
		cout << arr.at(i) << ' ';
	cout << endl;
}

void    radix_sort(vector<int> &arr) // O(Max len of elements * n)
{
	vector< vector<int> > buckets(10);
	int	power_of_ten = 1;
	int max_len = max_len_of_elements(arr);
	for(int pow = 0; pow <= max_len; ++pow)
	{
		// for(int elem : arr.size()) // if you won't use compilators lower than C++ 11
		// {
		// 	buckets[elem / power_of_ten % 10].push_back(elem);
		// }
		for(int i = 0; i < arr.size(); ++i)
		{
			int  elem = arr[i];
			buckets[elem / power_of_ten % 10].push_back(elem);
		}

		arr.clear();
		for(int i = 0; i < buckets.size(); ++i)
		{
			for(int j = 0; j < buckets[i].size(); ++j)
			{
				arr.push_back(buckets[i][j]);
			}
				buckets[i].clear();
		}
		power_of_ten *= 10;
	}
}



int main(void)
{
	vector<int> arr;
	vector<int> copy_arr;
	unsigned int arr_size = rand() % 10 + 1;
	for(int i = 0; i < arr_size; ++i)
		arr.push_back(rand() % 1000);
	copy_arr = arr;
	radix_sort(arr);
	
	// sort(copy_arr.begin(), copy_arr.end());
	// cout << "Is Sorted ? " << (copy_arr == arr) << endl; 

}