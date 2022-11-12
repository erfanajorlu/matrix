#include<bits/stdc++.h>
#include<cmath>
using namespace std;

//build new matrix
void build(int b[10][10], int a[10][10], int i, int n)
{
 int h = 0, k = 0;
 	for (int l = 1; l<n; l++)
 	{
 		for (int j = 0; j<n; j++)
 		{
 			if (j == i)
 			{
 				continue;
 			}
 								b[h][k] = a[l][j];
 														k++;
																	 if (k == n - 1)
 																		{
 																			h++;
 															k = 0;
 																		}
 
 		}
 	}
}

//calculate determinte
int det(int a[10][10], int n)
{
 int sum = 0;
 		int b[10][10];
 				if (n == 2)
 				{
 					sum = a[0][0] * a[1][1] - a[0][1] * a[1][0];
 						return sum;
 
 				}
 else
 	{
 
 for (int i = 0; i<n; i++)
 {
 								build(b, a, i, n);
 												
												 
												 sum += a[0][i] * pow(-1, i)*det(b, (n - 1));
 
 }
 }
 return sum;
}
 

int main()


{
	//get rows and columns of matrix A & B
	
	
		cout<<"shomare haye mashin hesab="<<endl<<"1=Get matrix A"<<endl<<"2=Get matrix B";
		cout<<endl<<"3=a-->b"<<endl<<"4=b-->a"<<endl<<"5=A*B"<<endl;
		cout<<"6=A+B"<<endl<<"7=don't touch"<<endl<<"8=A-B"<<endl;
		cout<<"9=a*A"<<endl<<"10=det A"<<endl<<"11=det B"<<endl;
		cout<<"12=print A"<<endl<<"13=print B"<<endl;
		
		
		
		int n,m,n1,m1;
	cout<<"enter rows A=";
	cin>>n;
	cout<<"enter column A=";
	cin>>m;
	if(n>10 || m>10 || n<=0 || m<=0)  //shart baraye inke matrix bishtar az 1o nabashe satr va sutunesh
	{
	cout<<"error"<<endl;
	cout<<"enter rows A=";
	cin>>n;
	cout<<"enter columns A=";
	cin>>m; 
	}
	cout<<"enter rows B=";
cin>>n1;
cout<<"enter columns B=";
cin>>m1;
if(n1>10 || m1>10  || n1<=0 || m1<=0)
{
	cout<<"error"<<endl;
	cout<<"enter rows B=";
	cin>>n1;
	cout<<"enter colums B=";
	cin>>m1;
}
	
	int b[n1][m1];
	int a[n][m];
	
	//meghdardahi avalie sefr be matrix ha
	
	for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            a[i][j]=0;
        }
	
	for(int i = 0; i < n1; i++)
        for(int j = 0; j < m1; j++)
        {
            b[i][j]=0;
        }
        
	int adad;
	//hoshdar dadan be mokhateb ke age mohasebat tamom shd 0 ro bezane
	 
cout<<"when your calculate finish enter 0 :)"<<endl;

//shoroe marahel mashin hesab
do
{
	//vared kardan adad
	cout<<"enter number=";
	cin>>adad;
	
switch(adad)
{
	case 1:  //meghdar giri matrix A
		{
	cout<<"enter MATRIX A=";
	for(int i=0;i<n;i++)
	{
				for(int j=0;j<m;j++)
				{
							cin>>a[i][j];}
				}
	break;
}
	case 2:{ //meghdar giri matrix b
cout<<"enter MATRIX B=";
	for(int i=0;i<n1;i++)
	{
						for(int j=0;j<m1;j++)
						{
											cin>>b[i][j];
						}
	}
	}break;
	
	case 3: //ja be ja kardan matrix ha
	{
		m1=m;
		n1=n;
		
		for(int i=0;i<n;i++)
		{
						for(int j=0;j<m;j++)
						{
											b[i][j]=a[i][j];
						}
		}	
		break;
	}
	case 4:{
		
		n=n1;
		m=m1;
		for(int i=0;i<n1;i++)
		{
			for(int j=0;j<m1;j++)
			{
				a[i][j]=0;
			}
		}
		
			for(int i=0;i<n1;i++)
		{
						for(int j=0;j<m1;j++)
						{
										a[i][j]=b[i][j];
						}
		}
		break;
	}
	case 5:{
		//zarb matrix ha
		int c[n][m1];
        
        
		if(n1 != m)
		{
			cout<<"error"<<endl;
			break;
		}
		else 
		{
			
		 for(int i = 0; i < n; i++)
        {
        					for(int j = 0; j < m1; j++)
        					{
            											c[i][j]=0;
        					}
    	}
    
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m1;j++)
				{
					for(int k=0;k<n1;k++)
					{
						c[i][j] += b[k][j] * a[i][k];
					}
				}
			}
}

//taghir m be m1 baraye chap A
										m=m1;

	for(int i=0;i<n;i++)
	{
						for(int j=0;j<m;j++)
						{
											a[i][j]=c[i][j];
						}
	}
	}break;
	
	case 6:{
		if(n != n1 || m!=m1)
		{
			cout<<"error"<<endl;
			break;
		}
		else
		{
		for(int i=0;i<n;i++)
		{
							for(int j=0;j<m;j++)
		{
													a[i][j]=a[i][j] + b[i][j];
		}
		}
	}
	
	}break;
	
	case 7:{
		
		break;
	}
	
	case 8 :{
		if(n != n1 || m != m1)
		{
			cout<<"error"<<endl;
			break;
		}
		else {
	for(int i=0;i<n;i++)
		 {
		 for(int j=0;j<m;j++)
		 {
		 	a[i][j]=a[i][j] - b[i][j];
		 }
		}
	}
		break;
	}
	case 9:{
		
		int r;
		
		cout<<"Enter R=";
		cin>>r;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
		{
						a[i][j]=a[i][j] * r;
		}
	    }
		break;
	}
	//case 10 for calculate determinan A
	case 10 :{
		int por[10][10];
		
		if (n == m)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					por[i][j] = a[i][j];
				}
			}
			int d;
			if(n==1)
			{
				d=a[0][0];
			}
			else
			{
			d=det (por,n);
		}
			cout<<"Determinan of A= "<<d<<endl;
		}
		else
		{
			cout<<"Error"<<endl;
		}
		break;
	}
	//case 11 for calculate matrix B
	case 11:{
		int por[10][10];
		if(n1==m1)
		{
			for(int i=0;i<n1;i++)
			{
				for(int j=0;j<n1;j++)
				{
							por[i][j] = b[i][j];
			}
		}
			int d;
			if(n1==1)
			{
				d=b[0][0];
			}
			else
			{
			d=det (por,n1);
		}
			cout<<"Determina of B= "<<d<<endl;
		}
		else
		{
			cout<<"Error"<<endl;
		}
		break;
	}
	case 12:{
	for(int i=0;i<n;i++)
	{
							for(int j=0;j<m;j++)
	{
													cout<<a[i][j]<<"     ";		
	}
																				cout<<endl;
		}break;
	}
	case 13:{
		for(int i=0;i<n1;i++)
	{
									for(int j=0;j<m1;j++)
	{
															cout<<b[i][j]<<"    ";
	}
																								cout<<endl;
	}
		break;
	}
	
	default :
		cout<<"Enter number between 1 to 13 ="<<endl;
}
}while(adad != 0);

//OMIDAVARAM LEZAT BORDE BASHID
//GOOD LUCK

return 0;
}
