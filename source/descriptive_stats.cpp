#include "descriptive_stats.h"

DescriptiveStats::DescriptiveStats(){

}

DescriptiveStats::~DescriptiveStats(){

}

double DescriptiveStats::median(std::vector<int> values){

	// sort in increasing order

	std::sort(values.begin(), values.end());

	// find the median

	int banyak_data = values.size();

	double nilai_median = -1.0;


	if(banyak_data % 2 != 0){

		int posisi_median = banyak_data / 2;

		nilai_median = values.at(posisi_median);

	}

	else{

		nilai_median = (values.at((banyak_data/2)) + values.at((banyak_data/2)-1))*1.0 / 2.0;

	}

	return nilai_median;

}

double DescriptiveStats::mean(std::vector<int> values){

	double sum = 0.0;

	for (int i = 0; i < values.size(); ++i)
	{
		/* code */
		sum+=values.at(i)*1.0;
	}

	return sum*1.0 / values.size()*1.0;
}

double DescriptiveStats::mean(std::vector<double> values){

	double sum = 0.0;

	for (int i = 0; i < values.size(); ++i)
	{
		/* code */
		sum+=values.at(i)*1.0;
	}

	return sum*1.0 / values.size()*1.0;
}

double DescriptiveStats::standard_deviation(std::vector<int> values){

	double rata2 = mean(values);

	double squared_sum = 0.0;

	for (int i = 0; i < values.size(); ++i)
	{
		/* code */
		squared_sum+= (values.at(i) - rata2) * (values.at(i) - rata2);
	}

	double deviasi = squared_sum / (values.size() - 1)*1.0;

	return sqrt(deviasi);
}

double DescriptiveStats::standard_deviation(std::vector<double> values){

	double rata2 = mean(values);

	double squared_sum = 0.0;

	for (int i = 0; i < values.size(); ++i)
	{
		/* code */
		squared_sum+= (values.at(i) - rata2) * (values.at(i) - rata2);
	}

	double deviasi = squared_sum / (values.size() - 1)*1.0;

	return sqrt(deviasi);
}

double DescriptiveStats::z_score(int value, double rata2, double standard_deviasi){
	double z = (value - rata2)*1.0 / (standard_deviasi*1.0);
}

double DescriptiveStats::q1(std::vector<int> values){
	
	double nilai_median = median(values);

	std::vector<int> lower_half;

	for (int i = 0; i < values.size(); ++i)
	{
		/* code */
		if(values.at(i) < nilai_median){
			lower_half.push_back(values.at(i));
		}
	}

	double nilai_q1 = median(lower_half);

	return nilai_q1;

}

double DescriptiveStats::q3(std::vector<int> values){
	double nilai_median = median(values);

	std::vector<int> upper_half;

	for (int i = 0; i < values.size(); ++i)
	{
		/* code */
		if(values.at(i) > nilai_median){
			upper_half.push_back(values.at(i));
		}
	}



	double nilai_q3 = median(upper_half);

	return nilai_q3;

}

double DescriptiveStats::index_max_value(std::map<double,double> maps){
	auto x = std::max_element(maps.begin(), maps.end(),
    [](const std::pair<double, double>& p1, const std::pair<double, double>& p2) {
        return p1.second < p2.second; });

	return x->first;
}

