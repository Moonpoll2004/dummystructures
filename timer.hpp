#include<time.h>
#include<iostream>


class Timer{
	
	public:
		Timer(){
			getTime();
		}

		~Timer(){
			getTime();
		}

		void getTime(){
			time_t know;
			time(&know);
			std::cout<<"The time is "<<ctime(&know);	
		}

};
