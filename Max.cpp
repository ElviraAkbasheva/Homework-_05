#include "Max.h"

	Max::Max()
	{
		m_max = -std::numeric_limits<double>::max();
	}

	void Max::update(std::vector<double>& numbers)
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] > m_max)
			{
				m_max = numbers[i];
			}
		}
	}

	double Max::eval() const
	{
		return m_max;
	}

	const char* Max::name() const
	{
		return "max";
	}
