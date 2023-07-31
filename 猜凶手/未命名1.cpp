#include <stdio.h>
int main ()
{
	for(int killer='a';killer<='d';killer++){
		if((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3){
			printf("%c",killer);//TODO
		}//TODO
	}
	return 0;
}
