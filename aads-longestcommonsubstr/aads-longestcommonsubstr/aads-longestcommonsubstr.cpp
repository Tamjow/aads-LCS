// aads-longestcommonsubstr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void lcs(string Y, string X)
{
	int m = X.length();
	int n = Y.length();
	int** L;
	L = new int*[m+1];
	for (int i = 0; i < m + 1; i++) {
		L[i] = new int[n + 1];
	}
	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// Following code is used to print LCS
	int index = L[m][n];
	int length = index;
	// Create a character array to store the lcs string
	//char* lcs = new char[index+1];
	string lcs(index+1,'0');
	lcs[index] = '\0'; // Set the terminating character

					 // Start from the right-most-bottom-most corner and
					 // one by one store characters in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		//cout << lcs << endl;
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (X[i - 1] == Y[j - 1])
		{
			lcs[index - 1] = X[i - 1]; // Put current character in result
			i--; j--; index--;     // reduce values of i, j and index
			
		}
		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	// Print the lcs
	cout << "LCS of " << X << " and " << Y << " is " << lcs << " of length: "<< length << endl;
}

int main()
{
	string first = "ABCBDAB";
	string second = "BDCABA";
	//string first = "XMJYAUZ";
	//string second = "MZJAWXU";

	lcs(first, second);
	system("pause");
    return 0;
}

