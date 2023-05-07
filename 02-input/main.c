# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count * size < count && count * size < size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// ft_string_join
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (0);
	while (i < len1)
	{
		res[i] = s1[i];
		i ++;
	}
	while (i < len1 + len2)
	{
		res[i] = s2[i - len1];
		i ++;
	}
	res[i] = '\0';
	return (res);
}
// ft_split
static	int	should_free_mem(char **array_word, size_t k, size_t len)
{
	if (k != len)
	{
		len -= 1;
		while (len > 0)
		{
			free(array_word[len]);
			len--;
		}
		free(array_word);
		return (1);
	}
	return (0);
}

static int	write_word(char **array_word, char const *s, char c, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*word;

	i = 0;
	j = 0;
	k = 0;
	while (k < len)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		word = ft_calloc(j - i + 1, sizeof(char));
		if (word == NULL)
			break ;
		j = 0;
		while (s[i] != c && s[i] != '\0')
			word[j++] = s[i++];
		array_word[k] = word;
		k++;
	}
	return (should_free_mem(array_word, k, len));
}

static	int	count_word(char const *s, char c)
{
	size_t	len;
	size_t	end_word;

	len = 0;
	end_word = 0;
	if (!*s)
		return (0);
	while (*s == c)
		s++;
	if (!*s)
		return (0);
	while (*s != '\0')
	{
		if (*s != c && end_word == 1)
		{
			len++;
			end_word = 0;
		}
		else if (*s == c && end_word == 0)
			end_word = 1;
		s++;
	}
	if (s[ft_strlen(s)] == c && c != '\0')
		len--;
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_word;
	char	**array_word;

	if (!s)
		return (NULL);
	num_word = count_word(s, c);
	array_word = malloc((num_word + 1) * sizeof(char *));
	if (array_word == NULL)
		return (NULL);
	array_word[num_word] = NULL;
	if (write_word(array_word, s, c, num_word) == 1)
		return (NULL);
	return (array_word);
}

// atoi
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i ++;
	}
	return (sign * res);
}

int main(int ac, char *av[])
{
	int i = 0;
	char **arr_args;
	// while(*(av+ ++i))
	// 	printf("%s\n",*(av+i));
	i = 1;
	int j = 0;
	while (*(av+i))
	{
		arr_args = ft_split(*(av+i), ' ');
		while(*(arr_args+j)) {
			printf("NUM : %d\n",ft_atoi(*(arr_args+j)));
			free(*(arr_args+j));
			j++;
		}
		j =0;
		i++;
	}
	free(arr_args);

}
