#include <stdio.h>
#include <math.h> //fabs함수를 포함하고 있어서 math.h (header) 라이브러리 함수를 불러와야 한다. 

double x[10];
double x_o[10] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5}; //처음에 넣는 시작값 
double A[10][11]= {{-4.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -27.0}, {1.0, -4.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -15.0}, {0.0, 1.0, -4.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -15.0}, 
                   {0.0, 0.0, 1.0, -4.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, -15.0}, {0.0, 0.0, 0.0, 1.0, -4.0, 1.0, 0.0, 0.0, 0.0, 0.0, -15.0}, {0.0, 0.0, 0.0, 0.0, 1.0, -4.0, 1.0, 0.0, 0.0, 0.0, -15.0},
				   {0.0, 0.0, 0.0, 0.0, 0.0, 1.0, -4.0, 1.0, 0.0, 0.0, -15.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, -4.0, 1.0, 0.0, -15.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, -4.0, 1.0, -15.0},
				   {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, -4.0, -15.0}};

int main(void)
{
	int i, j, k, n, m;
	double sum, res, sum_old, sum_new, epsil; 
	n=9;
	m=1000; 
	epsil = 0.0000001;
	
	
	for(j=0; j<=m; j++)
	{
		sum_new=0.0;
		sum_old=0.0;
		for(i=0; i<=n; i++)
		{
			sum = 0.0;
			
			for(k=0; k<=n; k++)
			{
				if(i!=k)
				{
					sum=sum-A[i][k]*x_o[k]; // r1- (Sum) Diagonal 외의 부분들을 더하는 부분이다. 
				}
				}	
			x[i]=(sum+A[i][n+1])/A[i][i]; //여기까지 next-step의 x를 한 개 구하게된다.  e.g( x1하나를 구하게 된 것) 
			
			sum_new = sum_new +x[i];
			sum_old = sum_old +x_o[i];  //여기서 sum_old + x[i]를 한 이유:  여기서는 x1(new)-x1(old)를 비교하는 것이 아니다 
			                            // {new(x1+x2+x3.....} - {old(x1+x2+x3+x4....)} <epsil 로 해서 비교하고 자 하는 것이다. 
			
			x_o[i] = x[i]; //새로운 x값을 old값으로 넣는 과정. 
		
		} // for문을 돌면 x1, x2, x3,...... 한바퀴씩 돌게 된 지점이다. 
		//이 시점에서 old sum과 new one을 비교할 수 있는 값들이 생성되어 있다. 
		
			res=fabs(sum_new-sum_old); //차의 값의 크기를 비교하는 것이기때문에 절댓값을 씌워줘야한다. 
			//{new(x1+x2+x3.....} - {old(x1+x2+x3+x4....)} <epsil 비교. 
			
			if(res<epsil)
			{
			goto END;
			}  //res<epsil이 될 대까지 --> x1, x2, x3의 값이 변동이 거의 없을때까지 반복한다 단, 100번 이하로 
	}
	
	END:;	
	
	for(i=0; i<=n; i++)
	{
		printf("x=%f \n", x[i]);
	}
		
	return 0;
}
