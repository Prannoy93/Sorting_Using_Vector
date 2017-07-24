#include "ASorter.h"
#include <iostream>
using namespace std;

void ASorter::selectionSort(std::vector<int> &vec)
{
	int size = vec.size();
	int min_index = 0;
	int temp = 0;
	for (int i = 0;i < size;i++)
	{
		min_index = i;
		for (int j = i + 1;j < size;j++)
		{
			if (vec[j]< vec[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i) //Makes sure we don't swap an element with itself.
		{
			temp = vec[i];
			vec[i] = vec[min_index];
			vec[min_index] = temp;
		}
	}

}


void ASorter::bubbleSort(std::vector<int>& vec)
{
	bool swapp = true;
	while (swapp) {
		swapp = false;
		for (size_t i = 0; i < vec.size() - 1; i++) {
			if (vec[i]>vec[i + 1]) {
				vec[i] += vec[i + 1];
				vec[i + 1] = vec[i] - vec[i + 1];
				vec[i] -= vec[i + 1];
				swapp = true;
			}
		}
	}
}

void ASorter::insertionSort(std::vector<int> &arr)
{
	int size = arr.size();
	int j, temp = 0;
	for (int i = 0;i < size;i++)
	{
		j = i;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}
//
//void ASorter::mergeSort(int arr[], int l, int h)
//{
//	if (l == h)
//		return;
//	int mid = (h + l) / 2;
//	mergeSort(arr, l, mid); //sort left half
//	mergeSort(arr, mid + 1, h); //sort right half
//	merge(arr, l, mid, h);
//
//}
//
//void ASorter::merge(int arr[], int l, int mid, int h)
//{
//
//	int i = l;
//	int j = mid + 1;
//	int k = l;
//	int *temp = new int[h + 1]{}; //dyanmically allocated for memory efficiency
//	while (i <= mid && j <= h)
//	{
//		if (arr[i] < arr[j])
//		{
//			temp[k] = arr[i];
//			i++;
//
//		}
//		else
//		{
//			temp[k] = arr[j];
//			j++;
//		}
//		k++;
//	}
//
//	while (i <= mid)
//	{
//		temp[k] = arr[i];
//		i++;
//		k++;
//	}
//	while (j <= h)
//	{
//		temp[k] = arr[j];
//		j++;
//		k++;
//	}
//
//	for (i = l;i < h + 1;i++)
//	{
//		arr[i] = temp[i];
//	}
//	delete[] temp; //delete temp array
//	return;
//}

void ASorter::merge(std::vector<int>& vec, int l, int m, int h)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = h - m;

	vector<int> L(n1);
	vector<int> H(n2);

	for (i = 0; i < n1; i++)
		L[i] = vec[l + i];
	for (j = 0; j < n2; j++)
		H[j] = vec[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= H[j])
		{
			vec[k] = L[i];
			i++;
		}
		else
		{
			vec[k] = H[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		vec[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		vec[k] = H[j];
		j++;
		k++;
	}
}

void ASorter::mergeSort(std::vector<int>& vec, int l, int h)
{

	if (l < h)
	{

		int m = l + (h - l) / 2;

		mergeSort(vec, l, m);
		mergeSort(vec, m + 1, h);
		merge(vec, l, m, h);
	}
}
int ASorter::partition(vector<int> &arr, const int left, const int right) {
	const int mid = left + (right - left) / 2;
	const int pivot = arr[mid];
	// move the mid point value to the front.
	std::swap(arr[mid], arr[left]);
	int i = left + 1;
	int j = right;
	while (i <= j) {
		while (i <= j && arr[i] <= pivot) {
			i++;
		}

		while (i <= j && arr[j] > pivot) {
			j--;
		}

		if (i < j) {

			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i - 1], arr[left]);
	return i - 1;
}

void ASorter :: quicksort(vector<int> &arr, const int left, const int right, const int sz) {

	if (left >= right) {
		return;
	}
	int part = partition(arr, left, right);
	quicksort(arr, left, part - 1, sz);
	quicksort(arr, part + 1, right, sz);
}

// To find gap between elements
int ASorter::getNextGap(int gap)
{
	// Shrink gap by Shrink factor
	gap = (gap * 10) / 13;

	if (gap < 1)
		return 1;
	return gap;
}

// Function to sort a[0..n-1] using Comb Sort
//std::vector<int> 
void ASorter::combSort(std::vector<int> &vec, int n)
{
	// Initialize gap
	int gap = n;
	int s = 0;
	// Initialize swapped as true to make sure that
	// loop runs
	bool swapped = true;

	// Keep running while gap is more than 1 and last
	// iteration caused a swap
	while (gap != 1 || swapped == true)
	{
		// Find next gap
		gap = getNextGap(gap);

		// Initialize swapped as false so that we can
		// check if swap happened or not
		swapped = false;

		// Compare all elements with current gap
		for (int i = 0; i < n - gap; i++)
		{
			if (vec[i] > vec[i + gap])
			{
				//swap(a[i], a[i + gap]);
				s = vec[i];
				vec[i] = vec[i + gap];
				vec[i + gap] = s;
				swapped = true;
			}
		}
	}
}
void ASorter ::RadixSortLSD(std::vector<int> &a, int arraySize)
	{
		int i, bucket[100000], maxVal = 0, digitPosition = 1;
		for (i = 0; i < arraySize; i++) {
			if (a[i] > maxVal) maxVal = a[i];
		}

		int pass = 1;  // used to show the progress
					   /* maxVal: this variable decide the while-loop count
					   if maxVal is 3 digits, then we loop through 3 times */
		while (maxVal / digitPosition > 0) {
			/* reset counter */
			int digitCount[10] = { 0 };

			/* count pos-th digits (keys) */
			for (i = 0; i < arraySize; i++)
				digitCount[a[i] / digitPosition % 10]++;

			/* accumulated count */
			for (i = 1; i < 10; i++)
				digitCount[i] += digitCount[i - 1];

			/* To keep the order, start from back side */
			for (i = arraySize - 1; i >= 0; i--)
				bucket[--digitCount[a[i] / digitPosition % 10]] = a[i];

			/* rearrange the original array using elements in the bucket */
			for (i = 0; i < arraySize; i++)
				a[i] = bucket[i];

			/* at this point, a array is sorted by digitPosition-th digit */
			//cout << "pass #" << pass++ << ": ";


			/* move up the digit position */
			digitPosition *= 10;
		}
		//std::cout << "the sorted array is \n";
		//print(a, arraySize);
	}

void ASorter::shellSort(std::vector<int> &vec, int size)
{
	int j;

	//Narrow the array by 2 everytime
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; ++i)
		{
			int temp = vec[i];
			for (j = i; j >= gap && temp < vec[j - gap]; j -= gap)
			{
				vec[j] = vec[j - gap];
			}
			vec[j] = temp;
		}
	}
	//return ar;
}


void ASorter::movedown(std::vector<int> &a, int first, int last)
{
	int s;// = 0;
	int largest = 2 * first + 1;
	while (largest <= last) {
		if (largest < last && a[largest] < a[largest + 1])
			largest++;

		if (a[first] < a[largest]) {
			s = a[first];
			a[first] = a[largest];
			a[largest] = s;
			first = largest;
			largest = 2 * first + 1;
		}
		else
			largest = last + 1;
	}
}

void ASorter::heapsort(std::vector<int>&a, int size)
{
	int s;// = 0;
	for (int i = size / 2 - 1; i >= 0;--i)
		movedown(a, i, size - 1);
	for (int i = size - 1; i >= 1; --i)
	{
		s = a[0];
		a[0] = a[i];
		a[i] = s;
		//swap(data[0], data[j]);
		movedown(a, 0, i - 1);
	}
	//return a;
}
void ASorter::countingsort(std::vector<int> &data, const int n) {
	int i;
	int largest = data[0];
	int *tmp = new int[n];
	for (i = 1;i < n;i++)
		if (largest < data[i])
			largest = data[i];
	unsigned int *count = new unsigned int[largest + 1];
	for (i = 0;i <= largest;i++)
		count[i] = 0;
	for (i = 0;i < n;i++)
		count[data[i]]++;
	for (i = 1; i <= largest;i++)
		count[i] = count[i - 1] + count[i];
	for (i = n - 1;i >= 0;i--) {
		tmp[count[data[i]] - 1] = data[i];
		count[data[i]]--;
	}
	for (i = 0;i < n;i++)
		data[i] = tmp[i];
}
//INTROSORT
//*************
// int ASorter::Partition(vector<int> &data, int left, int right) {
//	int pivot = data[right];
//	int temp;
//	int i = left;
//
//	for (int j = left; j < right; ++j)
//	{
//		if (data[j] <= pivot)
//		{
//			temp = data[j];
//			data[j] = data[i];
//			data[i] = temp;
//			i++;
//		}
//	}
//
//	data[right] = data[i];
//	data[i] = pivot;
//
//	return i;
//}
// //**************
// void ASorter::QuickSortRecursive(vector<int> &data, int left, int right) {
//	if (left < right)
//	{
//		int q = Partition(data, left, right);
//		QuickSortRecursive(data, left, q - 1);
//		QuickSortRecursive(data, q + 1, right);
//	}
//}
 //********************
//void ASorter::MaxHeapify(vector<int> &data, int heapSize, int index) {
//	int left = (index + 1) * 2 - 1;
//	int right = (index + 1) * 2;
//	int largest = 0;
//
//	if (left < heapSize && data[left] > data[index])
//		largest = left;
//	else
//		largest = index;
//
//	if (right < heapSize && data[right] > data[largest])
//		largest = right;
//
//	if (largest != index)
//	{
//		int temp = data[index];
//		data[index] = data[largest];
//		data[largest] = temp;
//
//		MaxHeapify(data, heapSize, largest);
//	}
//}
////******************
// void ASorter::HeapSort(vector<int> &data, int count) {
//	int heapSize = count;
//
//	for (int p = (heapSize - 1) / 2; p >= 0; --p)
//		MaxHeapify(data, heapSize, p);
//
//	for (int i = count - 1; i > 0; --i)
//	{
//		int temp = data[i];
//		data[i] = data[0];
//		data[0] = temp;
//
//		--heapSize;
//		MaxHeapify(data, heapSize, 0);
//	}
//}
 //*******************
 /*void ASorter::InsertionSort(vector<int> &data, int count) {
	for (int i = 1; i < count; ++i)
	{
		int j = i;

		while ((j > 0))
		{
			if (data[j - 1] > data[j])
			{
				data[j - 1] ^= data[j];
				data[j] ^= data[j - 1];
				data[j - 1] ^= data[j];

				--j;
			}
			else
			{
				break;
			}
		}
	}
}
*/
 //*******************
 void ASorter:: introSort(std::vector<int> &a, int first, int last, int maxDepth) {

	 int length = a.size();

	 //introSort(A, maxdepth);
	 if (length <= 1)
		 return;// base case
	 else if (maxDepth == 0)
	 {
		 int s, size = last - first;// = 0;
		 for (int i = size / 2 - 1; i >= 0;--i)
			 movedown(a, i, size - 1);
		 for (int i = size - 1; i >= 1; --i)
		 {
			 s = a[0];
			 a[0] = a[i];
			 a[i] = s;
			 //swap(data[0], data[j]);
			 movedown(a, 0, i - 1);
		 }
	 }
	 else
	 {
		 if (first >= last) {
			 return;
		 }

		 int pivot = a[last];
		 int temp;
		 int i = first;

		 for (int j = first; j < last; ++j)
		 {
			 if (a[j] <= pivot)
			 {
				 temp = a[j];
				 a[j] = a[i];
				 a[i] = temp;
				 i++;
			 }
		 }

		 a[last] = a[i];
		 a[i] = pivot;

		 introSort(a, first, i - 1, maxDepth - 1);
		 introSort(a, i + 1, last, maxDepth - 1);
	 }
 }

 void ASorter::invokeIntroSort(std::vector<int> &a) {
	 int maxdepth = log(a.size()) * 2;

	 int max = 0;
	 for (int i = 1; i < a.size(); i++) {
		 if (a[max] < a[i]) {
			 max = i;
		 }
	 }
	 int temp = a[a.size() - 1];
	 a[a.size() - 1] = a[max];
	 a[max] = temp;

	 introSort(a, 0, a.size() - 1, maxdepth);
 }


//
//void ASorter::IntroSort(vector<int>& data, int count) {
//	int partitionSize = Partition(data, 0, count - 1);
//
//	if (partitionSize <=1)// 16)
//	{
//	//	InsertionSort(data, count);
//	}
//	else if (partitionSize >(2 * log(count)))
//	{
//		HeapSort(data, count);
//	}
//	else
//	{
//		QuickSortRecursive(data, 0, count - 1);
//	}
//}
