#include "ASorter.h"
using namespace std;


void printVec(std::vector<int> &v)
{
	int size = v.size();
	for (int i = 0;i < size;i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int> fileRead(char *file)
{
	char c;
	int i = 0;
	std::vector< int > readFile;
	ifstream infile(file);
	if (!infile)
	{
		cout << "There was a problem opening file " << file << " for reading." << endl;
	}
	cout << "Opened " << file << " for reading." << endl;
	string s = "";
	while (infile.get(c))
	{
		if (c == '-' || c == '\n' || c == ' ') {
			i = stoi(s);
			readFile.push_back(i);
			s = "";
		}
		else if (c > 47 && c < 58)
		{
			s += c;
		}
	}
	i = stoi(s);	//convert string to integer
	readFile.push_back(i);
	cout << "File read successfully. " << endl;
	return readFile;
}
std::vector<int> incrementVec(std::vector<int> &values, int input)
{
	std::vector<int> fileVec;
	for (int i = 0; i < input; i++)
	{
		fileVec.push_back(values[i]);
	}
	return fileVec;
}
