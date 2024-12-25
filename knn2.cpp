#include<iostream>
#include<conio.h>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
int c,r,ct = 0,sum = 0;
vector<int> cls;
int Knn(int ,int ,double *,double *);
int main()
{
	cout << "Count Of Columns :- ";
	cin >> c;
	cout << "Count Of Rows :- ";
	cin >> r;
	double value[c][r],testpoint[c],n;
	for (int i = 0; i < c; ++i)
	{
		cout << endl;
		for (int j = 0; j < r; ++j)
		{
			cout << "Enter "<< i + 1 <<" Column "<< j + 1 << " Row Value :- ";
			cin >> value[i][j];
			cout << endl;
		}
	}
	for (int j = 0; j < r; ++j)
	{
		cout << "Enter "<< j + 1 << " Class Value :- ";
		cin >> n;
		cls.push_back(n);
		cout << endl;
	}	
	int ch;
	do
	{
		cout << "1.Enter Predict Value For Press [1] :- " << endl;
		cout << "Exit For Press [0] :- " << endl;
		cin >> ch; 
		if(ch==1)
		{
			for (int i = 0; i < c; ++i)
			{	
				cout << "Enter Predict "<< i + 1 << " Values :- ";
				cin >> testpoint[i];
			}
			Knn(c,r,(double*)value,(double*)testpoint);
		}
	}while(ch!=0);
	return 0;
}
int Knn(int a,int b,double *values,double *test)
{
	double ans[a][b];
	vector<double> ans2;
	int clss[b],ct=0;
	vector<double> ans3;
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			ans[i][j] = ((*(test + i) - *(values + i * b + j)) * (*(test + i) - *(values + i * b + j)));
		}
	}	
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			ans2.push_back(ans[i][j] + ans[i+1][j]);
		}
	}
	for (int i = 0; i < ans2.size()/a; ++i)
	{
		ans3.push_back(sqrt(ans2[i])); 
	}
	sort(ans3.begin(),ans3.end());
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < ans2.size() / a; ++j)
		{
			if(ans3[i]==sqrt(ans2[j]))
			{
				clss[ct] = cls[j];
				ct++;
			}
		}
	}
	cout << "Values " << " \t" << "Class" << endl;
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < ans2.size() / a; ++i)
	{
		cout << sqrt(ans2[i]) << "\t   \t" << cls[i] << endl;
	}
	cout << endl << "K = 3" << "\t" << "Class" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << ans3[i] << "\t  " << clss[i] << endl;
	}
	int y=0,n=0;
	for (int i = 0; i < 3; ++i)
	{
		if(clss[i]==1)
		{
			++y;
		}
		else if (clss[i]==0)
		{
			++n;
		}	
	}
	if (y>n)
	{
		cout << endl << "Yes" << endl;
	}
	else
	{
		cout << endl << "No" << endl;
	}		
	return 0;
}