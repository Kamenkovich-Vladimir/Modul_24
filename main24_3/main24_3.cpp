#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>


void timer(int i)
{
		int min, sec;
		min = i / 60;
		sec = i % 60;
		std::cout << min << ":" << sec << "\t";
		//std::this_thread::sleep_for(std::chrono::seconds(1)); Можно включить этот вариант
}

int main()
{
	std::cout << "***************** Implementation of the timer program *****************\n\n";

	std::cout << "Enter the number of minutes and seconds (mm:ss) to be timed on the timer and press Enter: \n";
	std::string time_str;
	std::cin >> time_str;
	if (time_str.length() != 5) {
		std::cerr << "Invalid time format!" << std::endl;
		return -1;
	}

	std::time_t tt = std::time(nullptr);
	std::tm local = *std::localtime(&tt);
	std::istringstream time_stream(time_str);

	//Проверим валидность введённых данных 
	time_stream >> std::get_time(&local, "%M:%S");

	if (time_stream.fail()) {
		std::cerr << "Invalid time format!" << std::endl;
	}
	else {
		std::time_t timer_begin = std::time(nullptr);
		std::time_t timer_end = mktime(&local);
		double time_diff = difftime(timer_end, timer_begin);

		for (int i = time_diff; i > 0; --i) {
			double sec_diff = 0;
			std::time_t timer_begin = std::time(nullptr);			
			while (sec_diff < 1) {
				std::time_t timer_end = std::time(nullptr);
				sec_diff = difftime(timer_end, timer_begin);			
			}
			int min = i / 60;
			int sec = i % 60;
			timer(i);	//Как вариант
			std::cout << min << ":" << sec << std::endl;
			//sec_diff = 0;
		}
		std::cout << "Ding-Dong" << std::endl;
	}
	
}