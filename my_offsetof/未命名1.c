#include <stdio.h>
#include <stddef.h>
#define off 1
#define OFFSETOF(type,my_name)  (size_t)&(((type*)0)->my_name)
struct S
{
	char a;
	int i;
	char b;
};
int main()
{
	struct S s = { 0 };
	#if off
	printf("offsetof%d \n",offsetof(struct S,a));
	printf("%d \n",offsetof(struct S,i));
	printf("%d \n",offsetof(struct S,b));
	#elif !off 
	printf("OFFSETOF%d \n",OFFSETOF(struct S,a));
	printf("%d \n",OFFSETOF(struct S,i));
	printf("%d \n",OFFSETOF(struct S,b));
	#endif //off
	
	return 0;
}
