#include <stdio.h>




int	main(int argc, char *argv[])
{
	int i = 0;
	while(*(argv+i))
		printf("%s\n", *(argv+i++));

	printf("3/2 == %d\n", 3/2);
	return (0);
}