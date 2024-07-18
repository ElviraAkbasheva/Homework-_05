#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>
#include "IStatistics.h"
#include "Min.h"
#include "Max.h"
#include "Mean.h"
#include "Std.h"
#include "Pct.h"

int main()
{
	std::cout << "> statistics" << std::endl;

	IStatistics* statistics[]{ new Min{}, new Max{}, new Mean{}, new Std{}, new Pct{90}, new Pct{95}};
	const size_t statistics_count = std::end(statistics) - std::begin(statistics);

	double val = 0;
	std::vector<double> numbers;
	while (std::cin >> val)
	{
		numbers.push_back(val);
	}

	std::sort(numbers.begin(), numbers.end());

	for (size_t i = 0; i < statistics_count; ++i)
	{
		statistics[i]->update(numbers);
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good())
	{
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i)
	{
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i)
	{
		delete statistics[i];
	}

	return 0;
}

