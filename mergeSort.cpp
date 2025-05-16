#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;
using namespace chrono;

const int SMALL_SIZE_THRESHOLD = 1000;  // Below this, use normal sort
const int MAX_DEPTH = 3;                // Only parallelize for top 3 levels

pair<vector<int>, int> getData();
void saveData(vector<int> &nums, size_t size);
int nextGap(int gap)
{
  if (gap <= 1)
    return 0;
  return (gap / 2) + (gap % 2);
}

void merge(vector<int>& nums, int leftStart, int mid, int rightEnd) {
    int n1 = mid - leftStart + 1;
    int n2 = rightEnd - mid;

    vector<int> left(nums.begin() + leftStart, nums.begin() + mid + 1);
    vector<int> right(nums.begin() + mid + 1, nums.begin() + rightEnd + 1);

    int i = 0, j = 0, k = leftStart;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            nums[k++] = left[i++];
        } else {
            nums[k++] = right[j++];
        }
    }

    while (i < n1) nums[k++] = left[i++];
    while (j < n2) nums[k++] = right[j++];
}

void sort(vector<int>& nums, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    sort(nums, left, mid);
    sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void parallel_merge_sort(std::vector<int>& arr, int left, int right, int depth) {
    if (right - left + 1 <= SMALL_SIZE_THRESHOLD) {
        std::sort(arr.begin() + left, arr.begin() + right + 1);
        return;
    }

    int mid = left + (right - left) / 2;

    if (depth < MAX_DEPTH) {
        std::thread t1(parallel_merge_sort, std::ref(arr), left, mid, depth + 1);
        std::thread t2(parallel_merge_sort, std::ref(arr), mid + 1, right, depth + 1);
        t1.join();
        t2.join();
    } else {
        parallel_merge_sort(arr, left, mid, depth + 1);
        parallel_merge_sort(arr, mid + 1, right, depth + 1);
    }

    merge(arr, left, mid, right);
}

int main()
{
  vector<int> nums = {1, 2, 7, 9, 0, 5};
  // sort(nums, 6);
  pair p = getData();
  auto start = high_resolution_clock::now();
  sort(p.first, 0, p.second - 1);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);
  cout << "\nTime taken: " << duration.count() << " ms" << endl;
  pair p2 = getData();
  auto start2 = high_resolution_clock::now();
  parallel_merge_sort(p2.first, 0, p2.second - 1, 0);
  auto end2 = high_resolution_clock::now();
  auto duration2 = duration_cast<milliseconds>(end2 - start2);
  cout << "\nTime taken: " << duration2.count() << " ms" << endl;
  saveData(p2.first, p2.second);
}

void saveData(vector<int> &nums, size_t size){
  ofstream writer("sorted.csv");
  if (!writer.is_open())
  {
    return;
  }
  for (size_t i = 0; i < size;i++){
    writer << nums[i] << "\n";
  }
}

pair<vector<int>, int> getData(){
  string line;
  ifstream reader("dataset.csv");
  vector<int> nums;
  int index = 0;
  if (!reader.is_open())
  {
    return {nums, 0};
  }
  while(getline(reader, line)){
    nums.push_back(stoi(line));
    index++;
  }
  return {nums, index};
}
