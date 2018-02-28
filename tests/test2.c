#include <stdlib.h>

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
// 	free(str1);	show_alloc_mem_full();
// 	free(str2);	show_alloc_mem_full();
// 	free(str3); show_alloc_mem_full();
// 	free(str4); show_alloc_mem_full();
// 	free(str5); show_alloc_mem_full();
// 	free(str6); show_alloc_mem_full();
// 	free(str7);	show_alloc_mem_full();
// 	free(str8);	show_alloc_mem_full();
// 	free(str9);	show_alloc_mem_full();
// 	free(str10); show_alloc_mem_full();
// 	free(str11); show_alloc_mem_full();
// 	free(str12); show_alloc_mem_full();
// 	free(str13); show_alloc_mem_full();
// 	free(str14); show_alloc_mem_full();
// 	free(str15); show_alloc_mem_full();
// 	return (0);
// }

int main()
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		show_alloc_mem_full();
		free(addr);
		i++;
	}
	return (0);
}
