#include "function.h"
bool check(int n)
{
	if (n <= 1) return 0;
	else
	{

		for (int i = 2; i * i <= n; ++i)
		{
			if (n % i == 0) return 0;
		}
		return 1;
	}
}