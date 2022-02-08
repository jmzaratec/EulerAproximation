// INCLUDE LIBRARIES
#include<iostream>
#include<cmath>
#include <cstdlib>
#include <fstream>



using namespace std;

double function(double xi,double wi)
{
	//return(2-exp((-4*xi))-(2*wi));
	return(wi-(xi*(exp(-pow(wi,2)))));


}

double ite(double alfa,int n, double a, double b,double k)
{
		

		////////////////////////////////////////////////////
	// OPEN up a file *.CSV to write data (already created)
			std::ofstream output;
			//Route of my *.csv file:   
			output.open("C:/Users/jm_zarate_c/Documents/Visual Studio 2010/Projects/ScientificComputing/3_homework_Euler/Euler2/data.csv");
			
			if(!output.is_open())
			{
			std::cout << " File not opened \n"; // To validate if the file was opened.
    		// stop the program here
			throw;
			}
  
			/* write HEADINGs on the file
            COLUMN 1              COLUMN 2      COLUMN 3          COLUMN 4*/
			output <<"n="<<" , "<< "wn" << " , " << " diff (wn-w(n/k) "<<" , "<< "1/n - k/n" << " , "<< "Constant for k=" <<k
				   <<","<<"y(b) = wn + (constant/n)"<<std::endl;
		///////////////////////////////////////////////	

double wi,xi, h,diff, odiff;
	double result;
	int i,j;	
	odiff=1;
	diff=1;


	for (j=1;j<=n;j*=k)//j++)j*=k
{

	xi=a;
	odiff=diff;
	diff=1;
	
	wi=alfa;
	h=((b-a))/double(j);
	
	// generata data
		for(i=1;i<=j;i++)
		{
		result= wi+ h*function(xi,wi);					
	    diff= wi-result;
		// TO GET every iteration for the first graphic
		/*cout<<j<<" "<<xi<<" "<<wi<<" " <<diff<< "  "  <<odiff/diff<< "  " <<"\n";
		output<<j<< " , " << xi << " , " << wi << " , " <<diff<< " , " <<odiff<< " , " <<double(odiff/diff)<<std::endl; */
		wi=result;
		xi=a +(h*i);
			
		}
		
		//cout<<j<<" "<<xi<<" "<<wi<<" " <<diff<< "  "  <<odiff/diff<< "  " <<"\n";
		/*output<<j<< " , " << xi << " , " << wi << " , " <<diff
		<< " , " <<odiff/diff<<","<<(((1/double(j))-(k/double(j))))<<","<<(diff/((1/double(j))-(k/double(j))))<<std::endl; */
		double constant;
		constant=(diff/((1/double(j))-(k/double(j))));
		output<<j<< " , "<< wi << " , " <<diff
		<< ","<<(((1/double(j))-(k/double(j))))<<","<<constant<< ","<< wi+(constant/double(j))<<std::endl; 
		
		//<<","<<double(((1/j)-(k/j)))<<","<<1/double(j)<<","<<double(k/j)<<std::endl; 
	
		//if (diff<=1e-5) break;	
		
}


		
		// Validate if file was written	
			std::cout << " File write successful \n";
  			// CLOSE file
 			output.close();
 			system("pause");
	return 0;
}

// VARIABLE GLOBAL


int main(int argc, char* argv[])
{
	//input variable
	int n,numresult;
	double a,b,alfa, k;



	a=0;
	b=log(double (3));
	alfa=0;
	k=3;
	//numresult= 100;
	//n=pow(k,numresult);
	n=10000000;
			
		ite(alfa,n,a,b,k);
	//int t;
			/*for(t=2;t<=10;t++)
			{
					ite(alfa,n,a,b,t);
			}*/
}
