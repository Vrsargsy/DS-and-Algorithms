#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	insertion_sort(vector<int> &arr) // O ( n^2) best algorithm for almost sorted data or small data
{
	for(int i = 1; i < arr.size(); ++i)
	{
		int j = i - 1;
		int cur = arr[i];
		while(j >= 0 && arr[j] > cur)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = cur;
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
	unsigned int arr_size = rand() % 10 + 1;
	for(int i = 0; i < arr_size; ++i)
		arr.push_back(rand() % 100 + 1);
	copy_arr = arr;
	insertion_sort(arr);
	print(arr);
	sort(copy_arr.begin(), copy_arr.end());
	cout << "Is Sorted ? " << (copy_arr == arr) << endl; 

}