#include<iostream>
#include <cmath>

using namespace std;
int logistic(int ,double *,double *,double ,double ,double);
int main()
{
	int xn;
	cout << "Count Of X :- ";
	cin >> xn;
	double xi[xn],yi[xn],a=0,b=0,prediction;
	for (int i = 0; i < xn; ++i)
	{
		cout << "Enter " << i+1 << " X :- ";
		cin >> xi[i];
		a += xi[i];
	}
	for (int i = 0; i < xn; ++i)
	{
		cout << "Enter " << i+1 << "Y :- ";
		cin >> yi[i];
		b += yi[i];
	}
	int ch=1;
	while(ch!=0)
	{
		cout << endl << "1.Prediction Value For Press [1] :- " << endl;
		cout << "Exit For Press [0] :- " << endl;
		cout << "Enter Your Choice :- ";
		cin >> ch;
		if (ch==1)
		{
			cout << endl << "Enter The Prediction values :-";
			cin >> prediction;
			logistic(xn,xi,yi,a,b,prediction);
		}

	}
	return 0;
}
int logistic(int n,double *x,double*y,double s1,double s2,double pre)
{
	double b1=0,b2=0,s3=0,s4=0,w,b,m,p;
	b1 = s1 / n;
	b2 = s2 / n;
	cout << "\n" << "X\tY\tX-XI\tY-YI\tX-XI*Y-YI\tX-XI*";
	for (int i = 0; i < n; ++i)
	{
		cout << "\n" << *(x + i) << "\t" << *(y + i) << "\t " << (b1 - *(x + i)) << "\t " << (b2 - *(y + i)) << "\t" << (b1 - *(x + i)) * (b2 - *(x + i)) << "\t\t" << (b1 - *(x + i)) * (b1 - *(x + i));
		s3 += (b1 - *(x + i)) * (b1 - *(x + i)); 
		s4 += (b1- *(x + i)) * (b2 - *(x + i));
	}
	cout << "\n" << "-" << "\t" << "-" << "\t " << "-" << "\t" <<"-" << "\t " << "-" << "\t\t " << "-";
	cout << "\n" << s1 << "\t" << s2 << "\t " << "-" << "\t " << "-"  "\t" << s4 << "\t\t" << s3;
	w = s4 / s3;
	b = b2 - (w * b1);
	m = (w * pre) + b;
	cout << endl <<"------------------------------------";
	cout << endl << "Value " << pre << " For Prediction Is " << m;
	cout << endl <<"------------------------------------";
	return 0;
}