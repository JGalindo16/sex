#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP
#include <vector>

namespace sort{
	using namespace std;

	
	void quickSort(vector<int> A, int i, int j, char * nombre_archivo);
	void quickSort(vector<int> A, int n, char * nombre_archivo);
	
	void mergeSort(vector<int> A, int i, int j, char * nombre_archivo);
	void mergeSort(vector<int> A, int n, char * nombre_archivo);

	void insertionSort(vector<int> A, int n, char * nombre_archivo);

	void radixSort(vector<int> A, int n, int max, char * nombre_archivo);
	void radixSort(vector<int> A, int n, char * nombre_archivo);

	int  k_smallest(vector<int> A, int i, int j, int k);
	int  k_smallest(vector<int> A, int n, int k);
	int split_qs(vector<int> A, int i, int j);
	int partition(vector<int> A, int start, int end);
}

#endif