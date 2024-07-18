#include "Mean.h"


	void Mean::update(std::vector<double>& numbers)
	{
		double sum = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			sum += numbers[i];
		}
		m_mean = sum / numbers.size();
	}

	double Mean::eval() const
	{
		return m_mean;
	}

	const char* Mean::name() const
	{
		return "mean";
	}