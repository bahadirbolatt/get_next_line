/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:50:25 by bbolat            #+#    #+#             */
/*   Updated: 2022/06/07 13:31:45 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE); /* üstünde gectigi yeri tekrar okumaz.*/
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0'; /* rd_bytes=4, sonuna null atar.*/
		left_str = ft_strjoin(left_str, buff);/*buff ı leftstr nin üzerine yazar.*/
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd) /* neden pointer?? dizi olduğu için. */
{
	char		*line;
	static char	*left_str; /*bir önceki yazdığını aklında tutar*/

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
/* #include <stdio.h>
#include "unistd.h"
int main()
{
 	int fd;
 	fd = open("asd", O_RDWR);
 	printf("%s", get_next_line(fd));
} */
