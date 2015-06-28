#include <string.h>
#include <stdio.h>
#include <libft.h>

void main(void)
{
	char	src[] = "Ceci est un test.";
	char	dest[200];// = ft_strnew(ft_strlen(dest));
	void	*ptr, *ptr2;

	ptr = NULL;
	ptr = ft_memccpy(dest, src, 'i', 10);
	printf("ft_memccpy:\n%p\n", ptr);
	ptr2 = memccpy(dest, src, 'i', 10);
	printf("memccpy:\n%p\n", ptr2);
	printf("%s\n", dest);
	//ft_strclr(dest);
	//ptr = NULL;
}
