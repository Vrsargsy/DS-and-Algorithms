#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void	print(vector<int> &arr)
{
	for(int i = 0; i < arr.size(); ++i)
		cout << arr.at(i) << ' ';
	cout << endl;
}

void	counting_sort(vector<int> &arr)  // O(n + m)
{
	int min = arr[0];
	int max = arr[0];

	for(int i = 0; i < arr.size(); ++i) // min max search
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
	vector<int> bucket(max - min + 1); // creating array for count
	for(int i = 0; i < arr.size(); ++i)
	{
		bucket[arr[i] - min]++;
	}
	print(bucket);
	cout << endl;
	arr.clear();
	for(int i = 0; i < bucket.size(); ++i)
	{
		int cnt = bucket[i];
		for(int j = 0; j < cnt; ++j)
		{
			arr.push_back(i + min);
		}
	}
}



int main(void)
{
	vector<int> arr;
	vector<int> copy_arr;
	unsigned int arr_size = rand() % 10 + 1;
	for(int i = 0; i < arr_size; ++i)
		arr.push_back(rand() % 100 + 1);
	copy_arr = arr;
	counting_sort(arr);
	print(arr);
	sort(copy_arr.begin(), copy_arr.end());
	cout << "Is Sorted ? " << (copy_arr == arr) << endl; 

}