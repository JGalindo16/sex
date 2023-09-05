#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

#include "utils.hpp"

namespace sort{

	using namespace std;

	float* createArray(int n){
		return new float[n];
	}

	float* createRandomArray(int n){
		float* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] =  std::rand() / static_cast<float>(RAND_MAX);
		}
		return A;
	}

	float* createRandomIntArray(int n, int minVal, int maxVal){
		float* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] = getRandomInt(minVal, maxVal);
		}
		return A;
	}


	void printArray(vector<int> A, int n){
		for (int i = 0; i < n; i++){
			std::cout<<A[i]<<" ";
		}
		std::cout<<std::endl;
	}

	void setAll(vector<int> A, int n, float value){
		for (int i = 0; i < n; i++){
			A[i] =  value;
		}
	}

	void swap(vector<int> A, int i, int j){
		float aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	int getRandomInt(int min, int max){
		float a = rand() / static_cast<float>(RAND_MAX);
		return static_cast<int>(a * (max - min) + min + 0.5);
	}

	int* linspace(int max, int n_parts){
		int* V = new int[n_parts];
		int part_size = max / n_parts;
		for(int i = 1; i <= n_parts; i++){
			V[i - 1] = part_size * i;
		}
		return V;
	}

	void merge(vector<int> A, int i, int j, int k){
		float* A_random = createRandomIntArray (j-i+1,0,0);
		int contador_1=0;
		int indicador_1=i;
		int indicador_2=k+1;
		while (indicador_1<=k && indicador_2<=j){
			if (A[indicador_1]<= A[indicador_2]){
			A_random[contador_1]=A[indicador_1]; 
			indicador_1++;}
			else{
			A_random[contador_1]=A[indicador_2];
			indicador_2++;}
			contador_1++;}
		while(indicador_1<=k){
			A_random[contador_1]=A[indicador_1];
			indicador_1++;
			contador_1++;}
		while(indicador_2<=j){
			A_random[contador_1]=A[indicador_2];
			indicador_2++;
			contador_1++;}
		int contador_2=0;
		for (int con=i;con<(j+1);con++){ 
			A[con] = A_random[contador_2];
			contador_2++;}
		delete [] A_random;
	}

}