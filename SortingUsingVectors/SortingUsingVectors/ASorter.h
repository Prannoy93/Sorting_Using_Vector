#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
class ASorter
{
public:
	static void insertionSort(std::vector<int> &arr);
	static void selectionSort(std::vector<int> &arr);
	static void mergeSort(std::vector<int> &arr, int l, int h);
	static void merge(std::vector<int> &arr, int l, int mid, int h);//****
	static int partition(std::vector<int> &arr, const int left, const int right);
	static void quicksort(std::vector<int> &arr, const int left, const int right, const int sz);
	static void bubbleSort(std::vector<int> &vec);
	static int getNextGap(int gap);
	static void combSort(std::vector<int> &vec, int n);
	static void shellSort(std::vector<int> &vec, int size);
	static void RadixSortLSD(std::vector<int> &a, int arraySize);
	static void movedown(std::vector<int> &a, int first, int last);
	static void heapsort(std::vector<int>&a, int size);
	static void countingsort(std::vector<int> &data, const int n);
	static void invokeIntroSort(std::vector<int> &a);
	static void introSort(std::vector<int> &a, int first, int last, int maxDepth);
};
