/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/28 16:49:21 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 17:16:03 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char		*line_splitter(char **str, int i, int j)
{
	char *line;
	char *tmp;

	if ((*str)[i] == '\n')
	{
		line = ft_strsub(*str, 0, i);
		tmp = ft_strsub(*str, i + 1, j - i);
		*str = ft_strcpy(*str, tmp);
		free(tmp);
	}
	else
	{
		line = ft_strsub(*str, 0, i);
		(*str)[0] = '\0';
	}
	return (line);
}

char		*line_counter(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*str))
		return (NULL);
	if ((*str)[i] == '\0')
		return (NULL);
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	while ((*str)[j])
		j++;
	return (line_splitter(str, i, j));
}

int			line_reader(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*tmp;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	int			new_line;

	new_line = 0;
	if (line == NULL || fd < 0)
		return (-1);
	while (new_line == 0 && (ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (!(str))
			str = ft_strnew(1);
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		new_line = line_reader(buf);
	}
	if ((*line = line_counter(&str)) == NULL)
		return (0);
	return (1);
}
