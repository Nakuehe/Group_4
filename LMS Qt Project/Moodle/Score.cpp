#include "Score.h"
float ReadFloat(std::string number)
{
	//Check if string is float
	int n = (int)number.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!isdigit(number[i]) && number[i] != '.') return 1e-9;
		if (number[i] == '.') ++cnt;
	}
	if (cnt > 1) return 1e-9;
	if (number[0] == '.'||number[n-1]=='.') return 1e-9;
	//Read number
	float int_part(0.0), decimal_part(0.0);
	float x = 10.0;
	bool status = true;
	for (int i = 0; i < n; ++i)
	{
		if (number[i] != '.')
		{
			if (status) int_part = int_part * 10 + (number[i] - '0');
			else
			{
				decimal_part += (number[i] - '0') / x;
				x = x * 10;
			}
		}
		else status = false;
	}
	return (int_part + decimal_part);
}