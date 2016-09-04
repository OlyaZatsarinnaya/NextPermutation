#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

int abs(int a)
{
	if (a >= 0)
		return a;
	else
		return -a;
}

long int factorial(int n)
{
	if (n == 1)
		return 1;
	
	return n*factorial(n - 1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;

	int *arr = new int[n];
	long int fact = factorial(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);
	bool permut = true;

	while (permut)
	{
		permut = false;
		int k;
		for (int i = n - 1; i > 0; i--)
			if (arr[i] > arr[i - 1])
			{
				k = i;
				permut = true;
				break;
			}

		if (permut == true)
		{
			for (int i = n - 1; i >= k; i--)
				if (arr[k - 1] < arr[i])
				{
					int temp = arr[k - 1];
					arr[k - 1] = arr[i];
					arr[i] = temp;
					break;
				}


			for (int i = 0; i < (n - k) / 2; i++)
			{
				int temp = arr[k + i];
				arr[k + i] = arr[n - 1 - i];
				arr[n - 1 - i] = temp;
			}

			for (int i = 0; i < n; i++)
				cout << arr[i] << " " ;
		}

		

		cout << endl;
	}
	system("pause");
	return 0;

}