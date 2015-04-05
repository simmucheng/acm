#include <stdio.h>
int main(){
	int sum;
	char winner;
	for(winner='A';winner<='D';winner++){
		sum = (winner != 'A' && winner != 'C') +
           	 (winner == 'B' || winner == 'D') +
           	 (winner == 'A' && winner != 'B') +
           	 (!(winner == 'B' || winner == 'D'));
           	if(sum==1) printf("Winner is %c\n", winner);
	}
	return 0;
}
