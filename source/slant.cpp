#include "slant.h"
#include "projection.h"
#include "help.h"

Slant::Slant(){

}

Slant::~Slant(){

}

double Slant::angle(cv::Mat img, double start, double end, double step){

	int alfa_baris = 0;

	std::map<double,std::vector<int> > Proj;

	std::map<double,double> alfa;

	for (double i = start; i <= end; i+=step)
	{
		/* code */
		alfa_baris++;

		std::vector<int> columns (img.cols,0);

		Proj.insert(std::pair<double,std::vector<int> >(i,columns));

		alfa.insert(std::pair<double,double>(i,0.0));
	}

	

	int baris = img.rows;

	int kolom = img.cols;

	//std::cout << "Kolom " << kolom << std::endl;

	Help help;

	for (int r = 0; r < baris; ++r)
	{
		/* code */

		std::map<double,double> Col_Disp;
		
		for (double i = start; i <= end; ++i)
					{
						/* code */
						double rad = ((PI*i*1.0)/180.0);

						Col_Disp.insert(std::pair<double,double>(i,r*tan(rad)));

					}

		for (int c = 0; c < kolom; ++c)
		{
			/* code */
			if(img.at<uchar>(r,c) == 0){

				std::map<double,std::vector<int> >::iterator find_it;
				for (double i = start; i <= end; i+=step)
				{
					/* code */
					double key = i;

					find_it = Proj.find(key);

					if(find_it!=Proj.end()){
						
						double key2 = c + Col_Disp[key];

						std::cout << key2 << std::endl;

						int x2 = int(key2);

						if((x2 > kolom-1)){
							//std::cout << "Ada " << i << " " << x2  << std::endl;
							int n = (x2 - Proj[key].size()) + 1;

							if(n < 0){
								//std::cout << n << std::endl;
							}

							for (int w = 0; w < n; ++w)
							{
								/* code */
								Proj[key].push_back(0);
							}

							// /Proj[key].push_back(0);
							
						}

						
						if(x2 >= 0){
							Proj[key].at(x2)++;
						}
						

						//std::cout << "Nilai vektor " << Proj[key].at(x2) << std::endl;

					}
				}
			}
		}

		//help.printMap(Col_Disp);

	}

	DescriptiveStats ds;

	std::map<double,double>::iterator it_alfa;

	for (it_alfa = alfa.begin(); it_alfa!=alfa.end(); ++it_alfa)
	{
		/* code */
		std::vector<int> values = Proj[it_alfa->first];

		double standard_deviation = ds.standard_deviation(values);

		alfa[it_alfa->first] = standard_deviation;
	}

	//help.printMap(alfa);

	double index_max_value = ds.index_max_value(alfa);

	//std::cout << "Nilai alfa terbesar " << index_max_value << std::endl;
	//help.printMap(Proj);

	return index_max_value;


}

cv::Mat Slant::shear(cv::Mat img,double angle){

	double rad = (PI * angle*1.0) / (180.0);

	cv::Mat_<cv::Vec2f> prjMap(img.size());
	
	for (int x=0; x<img.cols; x++) {
	    
	    for (int y=0; y<img.rows; y++) {
	        
	        float u = x - y * tan(rad);
	        
	        float v = y;
	        
	        prjMap(y, x) = cv::Vec2f(u,v);
	    }
	}
	
	cv::Mat projected;
	
	cv::remap(img, projected, prjMap, cv::Mat(), CV_INTER_LINEAR);

	return projected;

}


	