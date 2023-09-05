#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <vector>
#include "sort.hpp"
#include "utils.hpp"
#include <vector>
#include <sstream>


namespace sort{

using namespace std;

	int split_qs(vector<int> A, int i, int j){

		int p = getRandomInt(i, j);
		while (i  < j) {
			while ( i < p && A[i] <= A[p]){
				i = i + 1;
			}
			while ( j > p && A[j] >= A[p]){
				j = j - 1;
			}
			swap(A, i, j);
			if (i == p){
				p = j;
			}
			else if (j == p){
				p = i;
			}
		}
		return p;
	}

	void quickSort(vector<int> A, int i, int j, char * nombre_archivo){
		if (i < j){
			int k = split_qs(A, i, j);
			cout<<"entre"<<endl;
			quickSort(A, i, k-1, nombre_archivo);
			quickSort(A, k + 1, j,nombre_archivo);
		}
		
		string s;
		stringstream ss;
		ss<<nombre_archivo;
		ss<<".sorted";
		ss>>s;
		cout<<s;
		ofstream file;
  		file.open(s);
		for (i = 1; i < j; i++){
			file<<A[i]<<endl;
		}
		file.close();
	}

	void quickSort(vector<int> A, int n, char * nombre_archivo){
		quickSort(A, 0, n - 1, nombre_archivo);
	}

	int  k_smallest(vector<int> A, int i, int j, int k){
		int p = split_qs(A, i, j);
		int val = 0;
		if (k == p){
			val = A[p];
		}
		else if (k < p){
			val = k_smallest(A, i, p-1, k);
		}
		else{
			val = k_smallest(A, p+1, j, k);
		}
		return val;
	}

	int  k_smallest(vector<int> A, int n, int k){
		return k_smallest(A, 0, n-1, k);
	}

	void mergeSort(vector<int> A, int i, int j, char * nombre_archivo){
		int k = (i+j)/2;
		if(i<j){
			mergeSort(A, i, k, nombre_archivo);
			mergeSort(A, k + 1, j, nombre_archivo);
			merge(A, i, j, k);
			}
		string s;
		stringstream ss;
		ss<<nombre_archivo;
		ss<<".sorted";
		ss>>s;
		ofstream file;
  		file.open(s);
		for (int f = 1; f < j; f++){
			file<<A[f]<<endl;
		}
		file.close();
	}

	void mergeSort(vector<int> A, int n, char * nombre_archivo){
		mergeSort(A, 0 , n - 1, nombre_archivo);
	}

	void insertionSort(vector<int> A, int n, char * nombre_archivo) { 
		int i, key, j; 
		string linea;
		for (i = 1; i < n; i++){
			key = A[i]; 
			j = i - 1; 
			while (j > 0 && A[j] > key){ 
				A[j + 1] = A[j]; 
				j = j - 1; 
			} 
			A[j + 1] = key; 
		}
		string s;
		stringstream ss;
		ss<<nombre_archivo;
		ss<<".sorted";
		ss>>s;
		cout<<s;
		ofstream file;
  		file.open(s);
		for (i = 1; i < n; i++){
			file<<A[i]<<endl;
		}
		file.close();
	} 

	void radixSort(vector<int> arr, int n, int max, char * nombre_archivo) {
	int i, j, m, p = 1, index, temp, count = 0;
	std::list<int> pocket[10];
	for(i = 0; i< max; i++) {
		m = pow(10, i+1);
		p = pow(10, i);
		for(j = 0; j<n; j++) {
			temp = fmod(arr[j],m);
			index = temp/p;
			pocket[index].push_back(arr[j]);
			}
		count = 0;
		for(j = 0; j<10; j++) {
			while(!pocket[j].empty()) {
				arr[count] = *(pocket[j].begin());
				pocket[j].erase(pocket[j].begin());
				count++;
				}
			}
		}
		string s;
		stringstream ss;
		ss<<nombre_archivo;
		ss<<".sorted";
		ss>>s;
		cout<<s;
		ofstream file;
  		file.open(s);
		for (i = 1; i < max; i++){
			file<<arr[i]<<endl;
		}
		file.close();
	}

	void radixSort(vector<int> A, int n, char * nombre_archivo){
		radixSort(A, 0, n - 1, nombre_archivo);
	}

}
