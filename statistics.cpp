#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>


class IStatistics
{
public:
	virtual ~IStatistics() {}

	virtual void update(std::vector<double>& numbers) = 0;
	virtual double eval() const = 0;
	virtual const char* name() const = 0;
};

class Min : public IStatistics
{
private:
	double m_min;

public:
	Min() : m_min{ std::numeric_limits<double>::max() } {}

	void update(std::vector<double>& numbers) override
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] < m_min)
			{
				m_min = numbers[i];
			}
		}
	}

	double eval() const override
	{
		return m_min;
	}

	const char* name() const override
	{
		return "min";
	}
};

class Max : public IStatistics
{
private:
	double m_max;

public:
	Max() : m_max{ std::numeric_limits<double>::min() } {}

	void update(std::vector<double>& numbers) override
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] > m_max)
			{
				m_max = numbers[i];
			}
		}
	}

	double eval() const override
	{
		return m_max;
	}

	const char* name() const override
	{
		return "max";
	}
};

class Mean : public IStatistics
{
private:
	double m_mean;

public:
	void update(std::vector<double>& numbers) override
	{
		double sum = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			sum += numbers[i];
		}
		m_mean = sum / numbers.size();
	}

	double eval() const override
	{
		return m_mean;
	}

	const char* name() const override
	{
		return "mean";
	}
};

class Std : public IStatistics
{
private:
	double m_std;

public:
	void update(std::vector<double>& numbers) override
	{
		double sum = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			sum += numbers[i];
		}
		double mean = sum / numbers.size();

		double disp = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			disp += (pow((numbers[i] - mean), 2)) / numbers.size();
		}

		m_std = pow(disp, 0.5);
	}

	double eval() const override
	{
		return m_std;
	}

	const char* name() const override
	{
		return "std";
	}
};

class Pct90 : public IStatistics
{
private:
	double m_pct90;

public:
	void update(std::vector<double>& numbers) override
	{
		double rank = .9 * numbers.size();
		int index = ceil(rank) - 1;
		m_pct90 = numbers[index];
	}

	double eval() const override
	{
		return m_pct90;
	}

	const char* name() const override
	{
		return "pct90";
	}
};

class Pct95 : public IStatistics
{
private:
	double m_pct95;

public:
	void update(std::vector<double>& numbers) override
	{
		double rank = .95 * numbers.size();
		int index = ceil(rank) - 1;
		m_pct95 = numbers[index];
	}

	double eval() const override
	{
		return m_pct95;
	}

	const char* name() const override
	{
		return "pct95";
	}
};

int main()
{
	std::cout << "> statistics" << std::endl;

	IStatistics* statistics[]{ new Min{}, new Max{}, new Mean{}, new Std{}, new Pct90{}, new Pct95{} };
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