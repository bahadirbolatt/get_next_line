/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:50:12 by bbolat            #+#    #+#             */
/*   Updated: 2022/06/05 16:50:12 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n') //i 5 olana kadar arttırır. yani \n gelene kadar.
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2)); // null ve \n için.
	if (!str)
		return (NULL);
	i = 0; //bir dahaki satır için.
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i]; // ilk satırı str nin içine dolduruyoruz. yani na yı almaz.
		i++;
	}
	if (left_str[i] == '\n') // bir sonraki dörtlükte \n gördüğünde geç
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str) //diğer satırda önceki kısımdan kalan kısmı tutar. (NAsılsın)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i)); //8-5= 3 (na için ayırdığı alan.) + 1 (\n)
	if (!str)
		return (NULL);
	i++; // \n atladıii
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++]; //na yı yeni satıra yazdırıyor.
	str[j] = '\0';
	free(left_str);
	return (str);
}