#include "hotrace.h"

void		*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = NULL;
	if (!(dest = malloc(sizeof(unsigned char) * size)))
		return (NULL);
	while (i < size)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	i = 0;
	d_temp = NULL;
	s_temp = NULL;
	if (n != 0)
	{
		d_temp = (unsigned char *)dst;
		s_temp = (unsigned char *)src;
		while (i < n)
		{
			d_temp[i] = s_temp[i];
			i++;
		}
		dst = (void *)d_temp;
	}
	return (dst);
}

int				ft_strcmp(unsigned char *s1, unsigned char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (int)(s1[i] - s2[i]);
	}
	return (0);
}

unsigned char	*ft_strcpy(unsigned char *dst, unsigned char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}
