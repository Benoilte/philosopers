/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:50 by bebrandt          #+#    #+#             */
/*   Updated: 2024/02/02 16:32:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
return line of the corresponding file descriptor.
return NULL If an error occur.
*/
char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	t_gnl_lst	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	lst = (void *)0;
	return (ft_read_and_check_line(fd, stash, lst));
}

/*
Read n (BUFFER_SIZE) chars of the fd file until a new line is foud or until
we reach the end of the file. return the line included new line if present.
Return NULL if an error occur.
*/
char	*ft_read_and_check_line(int fd, char *stash, t_gnl_lst *lst)
{
	int		bytes_r;
	size_t	stash_len;
	char	line[BUFFER_SIZE + 1];

	while (!ft_check_new_line(stash))
	{
		stash_len = ft_strlen(stash);
		if (stash_len > 0)
		{
			ft_strlcpy(line, stash, stash_len + 1);
			ft_gnl_lstadd_back(&lst, line);
			stash[0] = '\0';
		}
		bytes_r = read(fd, stash, BUFFER_SIZE);
		if (bytes_r < 0)
			return (ft_gnl_lstclear(&lst));
		if (bytes_r < BUFFER_SIZE)
		{
			stash[bytes_r] = '\0';
			return (ft_get_line(stash, lst));
		}
	}
	return (ft_get_line(stash, lst));
}

/*
Locates if there is a new line in the string str.
Return 1 if yes, or NULL if there is no occurence
*/
size_t	ft_check_new_line(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i])
	{
		if ((unsigned char) stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
Copy stash in str until the new line included or until the end of stash
Add str as last element of lst.
Fill stash with chars behind the new line
*/
char	*ft_get_line(char *stash, t_gnl_lst *lst)
{
	size_t			i;
	size_t			t;
	char			line[BUFFER_SIZE + 1];

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!i && !lst)
		return ((void *)0);
	if (i)
	{
		ft_strlcpy(line, stash, i + 1);
		ft_gnl_lstadd_back(&lst, line);
		t = 0;
		while (stash[i])
			stash[t++] = stash[i++];
		stash[t] = '\0';
	}
	return (ft_copy_line(lst));
}

/*
Go through lst and concatenate all str member together.
Return a new string corresponding to a new line.
*/
char	*ft_copy_line(t_gnl_lst *lst)
{
	int			len;
	int			i;
	int			k;
	char		*line;
	t_gnl_lst	*tmp;

	len = ft_count_line_chars(lst);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (ft_gnl_lstclear(&lst));
	tmp = lst;
	i = 0;
	while (tmp)
	{
		k = 0;
		while (tmp->str[k])
			line[i++] = tmp->str[k++];
		tmp = tmp->next;
	}
	line[i] = '\0';
	ft_gnl_lstclear(&lst);
	return (line);
}
