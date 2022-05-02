#include <stdio.h>
#include <unistd.h>

int main()
{
	int a = 100;
	void	*ptr = &a;
	write(1, ptr, 4);
	write(1, "\n", 1);
	printf("%x\n", 200);
	//printf("There are %k fruits.\n", 10);
	return (0);
}