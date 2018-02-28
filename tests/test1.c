#include <stdlib.h>

int main()
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(10);
		addr[0] = 42;
		i++;
	}
	// show_alloc_mem();
	return (0);
}

// int main()
// {
// 	char *str1 = malloc(1024);
// 	char *str2 = malloc(1024);
// 	char *str3 = malloc(1024);
// 	char *str4 = malloc(1024);
// 	char *str5 = malloc(1024);
// 	char *str6 = malloc(1024);
// 	char *str7 = malloc(1024);
// 	char *str8 = malloc(1024);
// 	char *str9 = malloc(1024);
// 	char *str10 = malloc(1024);
// 	char *str11 = malloc(1024);
// 	char *str12 = malloc(1024);
// 	char *str13 = malloc(1024);
// 	char *str14 = malloc(1024);
// 	char *str15 = malloc(1024);

// 	show_alloc_mem_full();
// 	return (0);
// }