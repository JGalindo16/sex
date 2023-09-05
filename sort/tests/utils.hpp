#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP
#include <vector>

namespace sort{

	using namespace std;

	float* createArray(int n);
	float* createRandomArray(int n);
	float* createRandomIntArray(int n, int minVal = 0, int maxVal = 100);
	void deleteArray(vector<int> A);
	void printArray(vector<int> A, int n);
	void setAll(vector<int> A, int n, float value);
	void swap(vector<int> A, int i, int j);
	int getRandomInt(int min, int max);
	int* linspace(int max, int n_parts);
	void merge(vector<int> A, int i, int j, int k);
}

#endif
