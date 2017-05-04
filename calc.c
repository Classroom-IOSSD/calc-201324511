#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	double result = 0;
	int line = 0;
	double (*calc_operator)(int,int);

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				//result = add(operand1, operand2);
				calc_operator = add;
				break;
				case '-':
				//result = minus(operand1, operand2);
				calc_operator = minus;
				break;
				case '*':
				//result = mul(operand1, operand2);
				calc_operator = mul;
				break;
				case '/':
				//result = div(operand1, operand2);
				calc_operator = div;
				break;
			}
			result = calc_operator(operand1, operand2);		
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

