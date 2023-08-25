#include <stdio.h>// µ¥´ÊÄæĞò   l am a boy!  boy! a am l
#include <stdlib.h>
#include <string.h>
void solution(char arr[3][50]){
 
	 char temp;
	temp = *(char*)arr;
	*(char*)arr = *((char*)arr + 2);
	*((char*)arr + 2) = temp;
	fputs(arr,stdout);

}

int main() {
    char arr[3][50];
    
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", arr[i][50]);
    }
	solution(arr);
    return 0;
}
