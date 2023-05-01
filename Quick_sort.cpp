#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int	partition(vector<int> &arr, int i, int j)
{
	// int pivot = rand() % (i - j) + i; (best pivot == best speed) 
	// swap(arr[pivot], arr[i]);
	// pivot = i;
	int	pivot = i;
	int s1 = i;
	int s2 = i;
	for(int k = i + 1; k < j; ++k)
	{
		if (arr[k] >= arr[pivot])
		{
			++s2;
		}
		else
		{
			++s1;
			swap(arr[s1], arr[k]);
			++s2;
		}
	}
	swap(arr[pivot], arr[s1]);
	pivot = s1;
	return pivot;
}
// O(n^2) if pivot is lowest number of array
// O(n * log(n)) if pivot is good number (middle + - )
// O(1) memory 
void    quick_sort(vector<int> &arr, int i, int j)
{
	if (i == j)
	{
		return ;
	}
	// cout << i << endl;
	int pivot = partition(arr, i, j);
	cout << "Pivot : " << pivot << endl;
	quick_sort(arr, i, pivot);
	quick_sort(arr, pivot + 1, j);
}

void    quick_sort(vector<int> &arr)
{
	quick_sort(arr, 0, arr.size());
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
	// for(int i = 0; i < arr_size; ++i)
	// 	arr.push_back(rand() % 100 + 1);
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(2);
	arr.push_back(0);
	arr.push_back(1);
	print(arr);
	copy_arr = arr;
	quick_sort(arr);
	
	// sort(copy_arr.begin(), copy_arr.end());
	// cout << "Is Sorted ? " << (copy_arr == arr) << endl; 

}