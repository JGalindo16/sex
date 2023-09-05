#include "sort.hpp"
#include "utils.hpp"
#include <chrono>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

using namespace std;
int main(int argc, char* argv[]){
	char * metodo = argv[2];
	char * archivo = argv[1];
	vector <int> A;
	string dato;
	int rut;
	ifstream myfile (archivo) ;

	while (getline(myfile, dato, '\n')) {
		rut = stoi(dato);
        A.push_back(rut);
    }
	myfile.close();
	int n = A.size();

	if (strcmp(metodo, "I") == 0){
		auto start = std::chrono::high_resolution_clock::now();
		//change the sort method here

		sort::insertionSort(A, n, archivo);
		
		//
		auto end = std::chrono::high_resolution_clock::now();
		long elapsed =  getElapsedTime(start, end);
		std::cout << " [" << elapsed << "]" << std::endl;
		

    }else if (strcmp(metodo, "M") == 0){

		auto start = std::chrono::high_resolution_clock::now();
		//change the sort method here

		sort::mergeSort(A, n, archivo);
		
		//
		auto end = std::chrono::high_resolution_clock::now();
		long elapsed =  getElapsedTime(start, end);
		std::cout << " [" << elapsed << "]" << std::endl;
		

    }else if (strcmp(metodo, "Q") == 0){

		auto start = std::chrono::high_resolution_clock::now();
		//change the sort method here

		sort::quickSort(A, n, archivo);
		
		//
		auto end = std::chrono::high_resolution_clock::now();
		long elapsed =  getElapsedTime(start, end);
		std::cout << " [" << elapsed << "]" << std::endl;


    }else if (strcmp(metodo, "R") == 0){

        auto start = std::chrono::high_resolution_clock::now();
		//change the sort method here

		sort::radixSort(A, n, archivo);
		
		//
		auto end = std::chrono::high_resolution_clock::now();
		long elapsed =  getElapsedTime(start, end);
		std::cout << " [" << elapsed << "]" << std::endl;

    }

	
	return 0;
}
