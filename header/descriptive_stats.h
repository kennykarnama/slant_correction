#ifndef DESCRIPTIVE_STATS_H
#define DESCRIPTIVE_STATS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>



	class DescriptiveStats
	{
	public:
		DescriptiveStats();
		~DescriptiveStats();


		
		double median(std::vector<int>);

		double mean(std::vector<int>);

		double mean(std::vector<double>);

		double standard_deviation(std::vector<int>);

		double standard_deviation(std::vector<double>);


		double z_score(int, double, double);

		double q1(std::vector<int>);

		double q3(std::vector<int>);

		double index_max_value(std::map<double,double>);
		/* data */
	};
#endif