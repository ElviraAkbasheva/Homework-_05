#pragma once
#include <vector>
#include "IStatistics.h"

class Max : public IStatistics
{
private:
	double m_max;

public:
	Max();
	void update(std::vector<double>& numbers) override;
	double eval() const override;
	const char* name() const override;
};