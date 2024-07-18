#include "Min.h"


	Min::Min()
	{
		m_min = std::numeric_limits<double>::max();
	}

	void Min::update(std::vector<double>& numbers)
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] < m_min)
			{
				m_min = numbers[i];
			}
		}
	}

	double Min::eval() const
	{
		return m_min;
	}

	const char* Min::name() const
	{
		return "min";
	}
