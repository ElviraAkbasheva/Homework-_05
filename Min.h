#pragma once
#include <vector>
#include "IStatistics.h"

class Min : public IStatistics
{
private:
	double m_min;
public:
	Min();
	void update(std::vector<double>& numbers) override;
	double eval() const override;
	const char* name() const override;

};
