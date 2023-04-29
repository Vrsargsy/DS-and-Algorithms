#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void    selection_sort(vector<int> &arr) // O( ~n^2 )
{
	for(int i = 0; i < arr.size(); ++i)
	{
		int min = i;
		for(int j = i + 1; j < arr.size(); ++j)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		swap(arr[min], arr[i]);
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
	selection_sort(arr);
	
	// sort(copy_arr.begin(), copy_arr.end());
	// cout << "Is Sorted ? " << (copy_arr == arr) << endl; 

}