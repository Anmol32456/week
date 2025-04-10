#include<iostream>
using namespace std;
class Bouncy
{
	int num;
	public:
		void input()
		{
			cout<<"enter the number"<<endl;
			cin>>num;
		}
		void cal()
		{
			int ca = num % 10;
			num = num / 10;
			bool increase=false;
			bool decrease=false;
			while (num>0)
			{
				int n=num%10;
				if (n<ca)
				{
					decrease=true;
				}
				else if (n>ca)
				{
					increase=true;
				}
				if(increase&&decrease)
				{
					cout<"your number is bouncy";
				}
				ca=n;
				num=num/10;
			}
			cout<<"your number is not bouncy"<<endl;
		}
};
int main()
{
	Bouncy B;
	B.input();
	B.cal();
	return 0;
}
