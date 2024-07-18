#pragma once
#include <vector>
#include "IStatistics.h"

class Mean : public IStatistics
{
private:
	double m_mean;
public:
	void update(std::vector<double>& numbers) override;
	double eval() const override;
	const char* name() const override;
};
