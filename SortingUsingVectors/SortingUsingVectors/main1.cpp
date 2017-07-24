#include "ASorter.h"
#include "WindowsStopWatch.h"
#include "Functions.h"
using namespace std;

int main()
{
	WindowsStopwatch w;
	int input = 1000;
	char *inname = "random.txt";
	char *inname1 = "ascending.txt";
	char *inname2 = "decsending.txt";
	std::vector< int > values;	
	std::vector< int > values1;
	std::vector< int > values2;
	std::vector< int > val1;
	std::vector< int > val2;
	std::vector< int > val3;
	values = fileRead(inname);	// values are copied from random.txt file to vector
	values1 = fileRead(inname1);	// values are copied from ascending.txt file to vector
	values2 = fileRead(inname2);	// values are copied from descending.txt file to vector
	ofstream myfile;
	myfile.open("output.txt");

	do {

		cout << endl << "\n\n*** SORTING " << input << " ELEMENTS FROM random.txt ***\n\n" << endl;
		myfile<< "*** SORTING " << input << " ELEMENTS FROM random.txt ***" << endl;
		val1 = incrementVec(values, input);	// val1 has values from random.txt
//		printVec(val1);

		std::cout << "Insertion sort";
		w.start();				//start stop watch
		ASorter::insertionSort(val1);
		w.stop();				// end stop watch
		std::cout << std::endl;
		std::cout << "The time taken for Insertion sort of " << input << " elements is :" << w.getTime() << endl << endl;
		myfile << "Insertion sort\t\t" << w.getTime() << endl;
		val1 = incrementVec(values, input);		//stores new value again	
		
		std::cout << "Selection Sort\n";
		w.start();
		ASorter::selectionSort(val1);
		w.stop();
		std::cout << "The time taken for Selection sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Selection Sort\t\t" << w.getTime() << endl;
		val1 = incrementVec(values, input);		//stores new value again

		std::cout << "Merge Sort \n";
		w.start();
		ASorter::mergeSort(val1, 0, val1.size() - 1);
		w.stop();
		std::cout << "The time taken for Merge sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Merge Sort\t\t" << w.getTime() << endl;;
		//printVec(val1);
		val1 = incrementVec(values, input);		//stores new value again
		
		std::cout << "Quick Sort\n";
		w.start();
		ASorter::quicksort(val1, 0, val1.size() - 1,val1.size());
		w.stop();
		std::cout << "The time taken for Quick sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Quick Sort\t\t" << w.getTime() << endl;
		val1 = incrementVec(values, input);		//stores new value again
		
		std::cout << "Bubble Sort\n";
		w.start();
		ASorter::bubbleSort(val1);
		w.stop();
		std::cout << "The time taken for Bubble sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Bubble Sort\t\t" << w.getTime() << endl;
		val1 = incrementVec(values, input);		//stores new value again
		
		std::cout << "Comb Sort\n";
		w.start();
		ASorter::combSort(val1, val1.size());
		w.stop();
		std::cout << "The time taken for Comb sort of " << input << " elements is :" << w.getTime() << endl;
		myfile << "Comb Sort\t\t" << w.getTime() << endl;
		std::cout << std::endl;
		val1 = incrementVec(values, input);		//stores new value again
		
		std::cout << "Shell Sort\n";
		w.start();
		ASorter::shellSort(val1, val1.size());
		w.stop();
		std::cout << "The time taken for Shell sort of " << input << " elements is :" << w.getTime() << endl;
		myfile << "Shell Sort\t\t" << w.getTime() << endl;
		std::cout << std::endl;
		val1 = incrementVec(values, input);		//stores new value again
		
		std::cout << "Radix Sort\n";
		w.start();
		ASorter::RadixSortLSD(val1, val1.size());
		w.stop();
		std::cout << "The time taken for Radix sort of " << input << " elements is :" << w.getTime() << endl;
		myfile << "Radix Sort\t\t" << w.getTime() << endl;
		std::cout << std::endl;
		val1 = incrementVec(values, input);		//stores new value again
		
		std::cout << "Heap Sort\n";
		w.start();
		ASorter::heapsort(val1, val1.size());
		w.stop();
		std::cout << "The time taken for Heap sort of " << input << " elements is :" << w.getTime() << endl;
		myfile << "Heap Sort\t\t" << w.getTime() << endl;
		std::cout << std::endl;
		val1 = incrementVec(values, input);		//stores new value again
		
		std::cout << "Counting Sort\n";
		w.start();
		ASorter::countingsort(val1, val1.size());
		w.stop();
		std::cout << "The time taken for Count sort of " << input << " elements is :" << w.getTime() << endl;
		myfile << "Counting Sort\t\t" << w.getTime() << endl;
		std::cout << std::endl;
		val1 = incrementVec(values, input);		//stores new value again
		
		std::cout << "Intro Sort \n";
		w.start();
		ASorter::invokeIntroSort(val1);
		w.stop();
		std::cout << "The time taken for Intro sort of " << input << " elements is :" << w.getTime() << endl;
		myfile << "Intro Sort \t\t" << w.getTime() << endl;
		std::cout << std::endl;
		
		cout << endl << "*** SORTING " << input << " ELEMENTS FROM ascending.txt ***" << endl;
		myfile << endl << "*** SORTING " << input << " ELEMENTS FROM ascending.txt ***" << endl;
		val1 = incrementVec(values1, input);	// val1 has values from ascending.txt
		
		std::cout << "Insertion sort";
		w.start();			
		ASorter::insertionSort(val2);
		w.stop();			
		std::cout << std::endl;
		std::cout << "The time taken for Insertion sort of " << input << " elements is :" << w.getTime() << endl << endl;
		myfile << "Insertion sort\t\t" << w.getTime() << endl;
		val2 = incrementVec(values1, input);		//stores new value again	
		
		std::cout << "Selection Sort\n";
		w.start();
		ASorter::selectionSort(val2);
		w.stop();
		std::cout << "The time taken for Selection sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Selection Sort\t\t" << w.getTime() << endl;
		val2 = incrementVec(values1, input);		//stores new value again

		std::cout << "Merge Sort \n";
		w.start();
		ASorter::mergeSort(val2, 0, val2.size() - 1);
		w.stop();
		std::cout << "The time taken for Merge sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Merge Sort\t\t" << w.getTime() << endl;;
		val2 = incrementVec(values1, input);		//stores new value again

		std::cout << "Quick Sort\n";
		w.start();
		ASorter::quicksort(val2, 0, val2.size() - 1, val2.size());
		w.stop();
		std::cout << "The time taken for Quick sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Quick Sort\t\t" << w.getTime() << endl;
		val2 = incrementVec(values1, input);		//stores new value again
		
		std::cout << "Bubble Sort\n";
		w.start();
		ASorter::bubbleSort(val2);
		w.stop();
		std::cout << "The time taken for Bubble sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Bubble Sort\t\t" << w.getTime() << endl;
		val2 = incrementVec(values1, input);		//stores new value again
		
		std::cout << "Comb Sort\n";
		w.start();
		ASorter::combSort(val2, val2.size());
		w.stop();
		std::cout << "The time taken for Comb sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Comb Sort\t\t" << w.getTime() << endl;
		val2 = incrementVec(values1, input);		//stores new value again
		
		std::cout << "Shell Sort\n";
		w.start();
		ASorter::shellSort(val2, val2.size());
		w.stop();
		std::cout << "The time taken for Shell sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Shell Sort\t\t" << w.getTime() << endl;
		val2 = incrementVec(values1, input);		//stores new value again
		
		std::cout << "Radix Sort\n";
		w.start();
		ASorter::RadixSortLSD(val2, val2.size());
		w.stop();
		std::cout << "The time taken for Radix sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Radix Sort\t\t" << w.getTime() << endl;
		val2 = incrementVec(values1, input);		//stores new value again
		
		std::cout << "Heap Sort\n";
		w.start();
		ASorter::heapsort(val2, val2.size());
		w.stop();
		std::cout << "The time taken for Heap sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Heap Sort\t\t" << w.getTime() << endl;
		val2 = incrementVec(values1, input);		//stores new value again
		
		std::cout << "Counting Sort\n";
		w.start();
		ASorter::countingsort(val2, val2.size());
		w.stop();
		std::cout << "The time taken for Count sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Counting Sort\t\t" << w.getTime() << endl;
		val2 = incrementVec(values1, input);		//stores new value again
		
		std::cout << "Intro Sort \n";
		w.start();
		ASorter::invokeIntroSort(val2);//, val2.size());
		w.stop();
		std::cout << "The time taken for Intro sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Intro Sort \t\t" << w.getTime() << endl;
		
		cout << "*** SORTING " << input << " ELEMENTS FROM descending.txt ***" << endl;
		myfile << "*** SORTING " << input << " ELEMENTS FROM descending.txt ***" << endl;
		val3 = incrementVec(values2, input);	// val1 has values from descending.txt
		
		std::cout << "Insertion sort";
		w.start();				//start stop watch
		ASorter::insertionSort(val3);
		w.stop();				// end stop watch
		std::cout << std::endl;
		std::cout << "The time taken for Insertion sort of " << input << " elements is :" << w.getTime() << endl << endl;
		myfile << "Insertion sort\t\t" << w.getTime() << endl;
		val3 = incrementVec(values2, input);		//stores new value again	
		
		std::cout << "Selection Sort\n";
		w.start();
		ASorter::selectionSort(val3);
		w.stop();
		std::cout << "The time taken for Selection sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Selection Sort\t\t" << w.getTime() << endl;
		val3 = incrementVec(values2, input);		//stores new value again

		std::cout << "Merge Sort \n";
		w.start();
		ASorter::mergeSort(val3, 0, val3.size() - 1);
		w.stop();
		std::cout << "The time taken for Merge sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Merge Sort\t\t" << w.getTime() << endl;;
		val3 = incrementVec(values2, input);		//stores new value again

		std::cout << "Quick Sort\n";
		w.start();
		ASorter::quicksort(val3, 0, val3.size() - 1, val3.size());
		w.stop();
		std::cout << "The time taken for Quick sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Quick Sort\t\t" << w.getTime() << endl;
		val3 = incrementVec(values2, input);		//stores new value again

		std::cout << "Bubble Sort\n";
		w.start();
		ASorter::bubbleSort(val3);
		w.stop();
		std::cout << "The time taken for Bubble sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Bubble Sort\t\t" << w.getTime() << endl;
		val3 = incrementVec(values2, input);		//stores new value again

		std::cout << "Comb Sort\n";
		w.start();
		ASorter::combSort(val3, val3.size());
		w.stop();
		std::cout << "The time taken for Comb sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Comb Sort\t\t" << w.getTime() << endl;
		val3 = incrementVec(values2, input);		//stores new value again

		std::cout << "Shell Sort\n";
		w.start();
		ASorter::shellSort(val3, val3.size());
		w.stop();
		std::cout << "The time taken for Shell sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Shell Sort\t\t" << w.getTime() << endl;
		val3 = incrementVec(values2, input);		//stores new value again

		std::cout << "Radix Sort\n";
		w.start();
		ASorter::RadixSortLSD(val3, val3.size());
		w.stop();
		std::cout << "The time taken for Radix sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Radix Sort\t\t" << w.getTime() << endl;
		val3 = incrementVec(values2, input);		//stores new value again

		std::cout << "Heap Sort\n";
		w.start();
		ASorter::heapsort(val3, val3.size());
		w.stop();
		std::cout << "The time taken for Heap sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Heap Sort\t\t" << w.getTime() << endl;
		val3 = incrementVec(values2, input);		//stores new value again

		std::cout << "Counting Sort\n";
		w.start();
		ASorter::countingsort(val3, val3.size());
		w.stop();
		std::cout << "The time taken for Count sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Counting Sort\t\t" << w.getTime() << endl;
		val3 = incrementVec(values2, input);		//stores new value again

		std::cout << "Intro Sort \n";
		w.start();
		ASorter::invokeIntroSort(val3);
		w.stop();
		std::cout << "The time taken for Intro sort of " << input << " elements is :" << w.getTime() << endl;
		std::cout << std::endl;
		myfile << "Intro Sort \t\t" << w.getTime() << endl;
		input *= 2;
	}while (input < 300000);
	myfile.close();
	return 0;
}

