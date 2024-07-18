#pragma once
#include <vector>
#include "IStatistics.h"


class Pct : public IStatistics
{
private:
	double m_pct;
	double m_perc;
public:
	Pct(double perc);
	void update(std::vector<double>& numbers) override;
	double eval() const override;
	const char* name() const override;
};
