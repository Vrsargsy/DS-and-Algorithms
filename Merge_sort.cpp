#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b) // Merge O(n + m)
{
	vector<int> merged;
	int left_id = 0, right_id = 0;

	while(left_id < a.size() && right_id < b.size())
	{
		if (a[left_id] <= b[right_id])
			merged.push_back(a[left_id++]);
		else
			merged.push_back(b[right_id++]);
	}

	while(left_id < a.size())
		merged.push_back(a[left_id++]);

	while(right_id < b.size())
		merged.push_back(b[right_id++]);

	return merged;
}

void    merge_sort(vector<int> &arr) // O( n * log(n) )
{
	if (arr.size() <= 1)
		return ;

	vector<int> left, right;
	int n = arr.size() / 2;

	for(int i = 0; i < n; ++i)
		left.push_back(arr[i]);
	for(int i = n; i < arr.size(); ++i)
		right.push_back(arr[i]);

	merge_sort(left);
	merge_sort(right);

	arr = merge(left,right);
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
	unsigned int arr_size = rand();
	for(int i = 0; i < arr_size; ++i)
		arr.push_back(rand());
	copy_arr = arr;
	merge_sort(arr);
	
	// sort(copy_arr.begin(), copy_arr.end());
	// cout << "Is Sorted ? " << (copy_arr == arr) << endl; 

}