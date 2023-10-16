
#include "get_next_line.h"

unsigned long	ft_strlen(char *str)
{
	unsigned long	i;

	i =0;
	while (str && str[i] != 0)
		i++;
	return (i);
}

char	*ft_strcpy(char *str2, int i)
{
	int		j;
	char	*str1;

	j = 0;
    str1 = malloc(ft_strlen(str2));
    if (str1 == NULL)
	{
        return (NULL);
	}
	while (str2[i] != 0)
	{
		str1[j] = str2[i];
		i++;
		j++;
	}
    
	return (str1);
}

char	*add_resid(char *str)
{
	char	*resid;
	int		i;
	int		j;
	
	i = check_end(str);
    resid = ft_calloc(1 , 1);
    if (!resid)
	{
        return (NULL);
	}
	j = 0;
	if (i != BUFFER_SIZE)
	{   
		resid = (char *)malloc(BUFFER_SIZE - i + 1);
		if (resid == NULL)
			return (NULL);
		while (i < BUFFER_SIZE)
		{
			resid[j] = str[i];
			i++;
			j++;
		}
        resid[j] = 0;
		return (resid);
	}
	return (resid);
}
	
int	check_end(char *str)
{
	int	i;

	i = 0;
	while(i < BUFFER_SIZE && str[i])
	{
		if (str[i] == 0)
			return (i);
		else if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*strjoin(char *existing, char *extra)
{
	int				len1;
	int				len2;
	int				i;
	int				j;
	char			*line;
	
	len1 = ft_strlen(existing);
	len2 = check_end(extra);
	line = (char *)malloc(len1 + len2 + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (existing[i] != 0)
	{
		line[i] = existing[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		line[i] = extra[j];
		i++;
		j++;
	}
    line[i] = 0;
	free(existing);
	return (line);
}
