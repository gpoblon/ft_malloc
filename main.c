#include <stdlib.h>


int main()
{
int i; char *addr;

i = 0;
while (i < 10)
{
	addr = (char*)malloc(15);
	addr[0] = 42;
//	free(addr);
	i++;
}
show_alloc_mem_full();
return (0);
}
