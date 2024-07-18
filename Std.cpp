#include "Std.h"

	void Std::update(std::vector<double>& numbers)
	{
		double sum = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			sum += numbers[i];
		}
		double mean = sum / numbers.size();

		double disp = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			disp += (pow((numbers[i] - mean), 2)) / numbers.size();
		}

		m_std = pow(disp, 0.5);
	}

	double Std::eval() const
	{
		return m_std;
	}

	const char* Std::name() const
	{
		return "std";
	}
