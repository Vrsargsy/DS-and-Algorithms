#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void    bubble_sort(vector<int> &arr) // Optimized O(n^2)
{
	for(int i = 0; i < arr.size(); ++i)
	{
		bool	is_sorted = true;
		for(int j = 1; j < arr.size() - i; ++j)
		{
			if (arr[j] < arr[j - 1])
			{
				is_sorted = false;
				swap(arr[j], arr[j - 1]);
			}
		}
		if (is_sorted)
			return ;
	}
}

void	print(vector<int> &arr)
{
	for(int i = 0; i < arr.size(); ++i)
		cout << arr.at(i) << ' ';
	cout << endl;
}

int main(void)
{
	vector<int> arr;
	vector<int> copy_arr;
	unsigned int arr_size = rand() + 1;
	for(int i = 0; i < arr_size; ++i)
		arr.push_back(rand() + 1);
	copy_arr = arr;
	bubble_sort(arr);
	
	// sort(copy_arr.begin(), copy_arr.end());
	// cout << "Is Sorted ? " << (copy_arr == arr) << endl; 

}












void	n2 (vecctor<int> &arr)
{
	for(int i = 0; i < arr.size(); ++i)
	{
	}

}