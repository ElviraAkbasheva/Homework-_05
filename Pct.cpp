#include "Pct.h"

	Pct::Pct(double perc)
	{
		m_perc = perc;
	}
	void Pct::update(std::vector<double>& numbers)
	{
		double rank = m_perc / 100 * numbers.size();
		int index = ceil(rank) - 1;
		m_pct = numbers[index];
	}

	double Pct::eval() const
	{
		return m_pct;
	}

	const char* Pct::name() const
	{
		if (m_perc == 90)
		{
			return "pct90";
		}
		if (m_perc == 95)
		{
			return "pct95";
		}
	}
