#pragma once
#include <vector>
#include "IStatistics.h"

class Std : public IStatistics
{
private:
	double m_std;

public:
	void update(std::vector<double>& numbers) override;
	double eval() const override;
	const char* name() const override;
};