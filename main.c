#include <stdio.h>
#include <unistd.h>

int main()
{
	int a = 100;
	void	*ptr = &a;
	write(1, ptr, 4);
	write(1, "\n", 1);
	printf("%lu\n", sizeof(ptr));
	//printf("There are %k fruits.\n", 10);
	return (0);
}