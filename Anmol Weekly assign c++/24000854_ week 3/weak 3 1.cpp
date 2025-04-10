#include<iostream>
using namespace std;
class time
{
	private:
		int hour,min,sec;
		public:
			time(int a,int b,int c)
			{
				hour=a;
				min=b;
				sec=c;
			}
			time operator+(time t)
			{
				time calc;
				calc.sec=sec+t.sec;
				int MM=calc.sec/60;
				calc.sec=calc.sec%60;
				calc.min=MM+min+t.min;
				int hh=calc.min/60;
				calc.MM=calc.min%60;
				calc.hour=hour+t.hour+hh;
				return(calc);
			}
			time operator>(time t)
			{
				time calc;
				if(t1>t2)
				{
					cout<<"T1 is greater then T2 "<<endl;
				}
				else
				{
					cout<<"t2 is greater than t1"<<endl;
				}
			}
			void display()
			{
				cout<<"hour="<<hour<<"minute="<<min<<"second="<<sec<<endl;
			}
			void exc(int hour,int mmin)
			{
				if(hour>24||min>60)
				{
					throw(hour,min);
				}
			}
			void exc1()
			{
				try{
					exc(hour,min);
				}
				catch(int hour,int min)
				{
					cout<<"hour is more than 24 or min is more than 60 min"<<endl;
				}
				
			}
};
int main()
{
	time t1(hour,min,sec);
	time t2(hour,min,sec);
	time t3=t1+t2;
	int hour,min ,sec;
	cout<<"enter hour minute and second"<<endl;
	cin>>hour>>min>>sec;
	cout<<"enter hour minute and second 2nd time "<<endl;
	cin>>hour>>min>>sec;
	time t4=t1>t2;
	time t5;
	t5.exc1();
	return 0;
}
