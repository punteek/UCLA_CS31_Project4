// Prateek Singh
// Project 4
// Professor Smalllberg
// Array of Sunshine (many random functions to do with string arrays)

#include <iostream>
#include <string>

using namespace std;

// adds the given value to each element of the array
int appendToAll(string a[], int n, string value)
{
	if (n < 0)
	{
		return -1;
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = a[i] + value;
	}

	return n;
}

// finds a target string in the array
int lookup(const string a[], int n, string target)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == target)
		{
			return i;
		}
	}

	return -1;
}

// finds the position of the last string alphabetically in the array
int positionOfMax(const string a[], int n)
{
	if (n <= 0)
	{
		return -1;
	}

	int maxPos = 0;
	
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i + 1] > a[i])
		{
			maxPos = i + 1;
		}
	}

	return maxPos;
}

// get rid of the string at pos, move everything to the left, take the previous string and put it at the end
int rotateLeft(string a[], int n, int pos)
{
	if (n <= 0 || pos < 0)
	{
		return -1;
	}

	if (n <= pos)
	{
		return -1;
	}

	string temp = a[pos];

	for (int i = pos; i < n - 1; i++)
	{
		//assigns the element one spot to the left
		a[i] = a[i + 1];
	}

	a[n - 1] = temp;

	return pos;
}

// count occurences of distinct nonconsecutive elements
int countRuns(const string a[], int n)
{
	if (n < 0)
	{
		return -1;
	}

	if (n == 0)
	{
		return 0;
	}

	int sequences = 1;

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] != a[i + 1])
		{
			sequences++;
		}
	}

	return sequences;
}

// reverses the elements of the array upto the given value of n
int flip(string a[], int n)
{
	if (n < 0)
	{
		return -1;
	}

	for (int i = 0; i < n / 2; i++)
	{
		//using a temp variable to switch strings
		string temp = a[i];
		a[i] = a[n - (i + 1)];
		a[n - (i + 1)] = temp;
	}

	return n;
}

// checks to see if there is any difference between two given arrays
int differ(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0)
	{
		return -1;
	}

	if (n1 == 0 || n2 == 0)
	{
		return 0;
	}

	int smallerLength = 0;
	
	if (n1 < n2)
	{
		smallerLength = n1;
	}
	else
	{
		smallerLength = n2;
	}

	for (int i = 0; i < smallerLength; i++)
	{
		if (a1[i] != a2[i])
		{
			return i;
		}
	}

	return smallerLength;
}

// checks whether the elements given in the second array appear exactly in the first array
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 <= 0 || n2 < 0)
	{
		return -1;
	}

	if (n2 == 0)
	{
		return 0;
	}

	for (int i = 0; i < n1; i++)
	{
		if (a2[0] == a1[i])
		{
			int currentSpotInA1 = i;
			
			for (int j = 0; j < n2; j++)
			{
				if (a2[j] != a1[j + i])
				{
					return -1;
				}
			}

			return i;
		}
	}

	return -1;
}

// finds the first identical element in both given arrays
int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 <= 0 || n2 <= 0)
	{
		return -1;
	}

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (a1[i] == a2[j])
			{
				return i;
			}
		}
	}

	return -1;
}

// organizes elements of the array so that they aplhabetically come before or after the given splitter string
int split(string a[], int n, string splitter)
{
	if (n < 0)
	{
		return -1;
	}

	//sorts all of the strings in the given array aplhabetically
	for (int i = 1; i < n; i++)
	{
		int j = i;

		while (j > 0 && a[j - 1] > a[j])
		{
			string temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
	}

	//finds the spot of the first element over the splitter string
	for (int k = 0; k < n; k++)
	{
		if (a[k] >= splitter)
		{
			return k;
		}
	}

	return n;
}

int main()
{
	string people[] = { "ben", "marco", "chris", "donald", "marco" };
	cout << countRuns(people, 5);
}