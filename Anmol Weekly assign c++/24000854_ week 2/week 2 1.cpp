#include<iostream>
using namespace std;
class Std
{
	public:
		string name;
		int mark[3];
		
		void details()
		{
			cout<<"enter student name=";
			cin>>name;
			for(int i=0;i<3;i++)
			{
				cout<<"enter mark of 3 subject";
				cin>>mark[i];
			}
		}
void report(){
	int total = mark[0]+mark[1]+mark[2];
	float average = total / 3.0;
	char grade = (average >= 90) ? 'A' : (average >= 80) ? 'B' : (average >= 70) ? 'C' : (average >= 60) ? 'D' : 'F';
	cout<<"\n Student Report";
	cout<<"\n Name="<<name;
	cout<<"\n Total mark="<<total;
	cout<<"\n Average mark="<<average;
	cout<<"\n Grade="<<grade;
}
};
int main()
{
	Std st;
    st.details();
    st.report();
    return 0;
}
	

