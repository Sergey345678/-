// LR2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;


struct Array
{
	int * array;
	int length;
	void free();
};

void ArrayFill(Array & arr, int rnd = 10);
void ArrayPrint(Array & arr);
Array ArrayIntersect(Array & arr1, Array & arr2);
Array ArrayMerge(Array & arr1, Array & arr2);
void insertSort(Array & arr);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	int count = 10;

	cout << "Введите размер массива" << endl;
	cin >> count;

	Array arr1 = {NULL, count},
		arr2 = {NULL, count};


	ArrayFill(arr1);
	ArrayFill(arr2);
	cout << "Первый массив: ";
	ArrayPrint(arr1);
	cout << "Второй массив: ";
	ArrayPrint(arr2);

	Array arr3 = ArrayIntersect(arr1, arr2);
	cout << "Пересечение: ";
	ArrayPrint(arr3);
	arr3.free();

	Array arr4 = ArrayMerge(arr1, arr2);
	cout << "Объеденение: ";
	ArrayPrint(arr4);


	arr4.free();

	arr1.free();
	arr2.free();
		
	system("PAUSE");
	return 0;
}

void ArrayFill(Array & arr, int rnd) {
	arr.array = new int[arr.length];
	for(int i = 0;i < arr.length;++i)
		arr.array[i] = 1 + rand() % rnd;
}

void ArrayPrint(Array & arr) {
	for(int i = 0;i < arr.length;++i)
		cout << arr.array[i] << "    ";
	cout << endl;
}

Array ArrayIntersect(Array & arr1, Array & arr2) {
	int len = arr1.length > arr2.length ? arr1.length : arr2.length;
	Array arr = {new int[len], len};
	int newLen = 0;
	
	for(int i = 0;i < arr1.length;++i) 
		for(int j = 0;j <  arr2.length;j++)
			if(arr1.array[i] == arr2.array[j]) {
				bool find = false;
				for(int k = 0;k < newLen;++k)
					if(arr1.array[i] == arr.array[k])
						find = true;
				if(!find)
					arr.array[newLen++] = arr1.array[i];
				break;
			}
	Array arrfill = {new int[newLen], newLen};
	for(int i = 0;i < newLen;i++)
		arrfill.array[i] = arr.array[i];

	arr.free();

	return arrfill;
}

Array ArrayMerge(Array & arr1, Array & arr2) {
	int len = arr1.length + arr2.length;
	Array arr = {new int[len], len};
	int newlen = 0;

	for(int i = 0;i < arr1.length; ++i) {
		bool find = false;
		for(int j = 0;j < arr.length;++j)
			if(arr1.array[i] == arr.array[j])
				find = true;
		if(!find)
			arr.array[newlen++] = arr1.array[i];
	}

	for(int i = 0; i < arr2.length;++i) {
		bool find = false;
		for(int j = 0;j < arr.length;++j)
			if(arr2.array[i] == arr.array[j])
				find = true;
		if(!find)
			arr.array[newlen++] = arr2.array[i];
	}

	Array arrfill = {new int[newlen], newlen};
	for(int i = 0;i < newlen;i++)
		arrfill.array[i] = arr.array[i];

	arr.free();

	return arrfill;
}

void Array::free() {
	delete [] array;
}

void insertSort(Array & arr) 
{
    
}