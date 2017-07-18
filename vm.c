/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:14:48 by nolivier          #+#    #+#             */
/*   Updated: 2017/07/18 14:21:03 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "vm.h"
#include "libft/libft.h"

int				ft_usage(void)
{
	ft_putstr("Usage: \n");
	return (0);
}

int				ft_error(char *mess)
{
	ft_putstr(mess);
	return (0);
}

void			ft_putnbr_hex(int nb)
{
	char			addr[5];
	char			*b;
	int				i;

	b = "0123456789abcdef";
	i = 0;
	while (i < 4)
	{
		addr[3 - i] = b[nb % 16];
		nb = nb / 16;
		i++;
	}
	addr[4] = '\0';
	ft_putstr(addr);
}

void			ft_dump_memory(unsigned char *memory, int size)
{
	char			*b;
	int				i;
	int				j;

	if (LINE_SIZE < 1)
		return ;
	b = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		ft_putstr("0x");
		ft_putnbr_hex(i);
		ft_putstr(" : ");
		j = 0;
		while (j < LINE_SIZE && i + j < size)
		{
			ft_putchar(b[memory[i + j] / 16]);
			ft_putchar(b[memory[i + j] % 16]);
			ft_putchar(' ');
			j++;
		}
		i += LINE_SIZE;
		ft_putchar('\n');
	}
}

int			ft_invert_endian(int nb)
{
	return (((nb >> 24) & 255) + ((nb >> 8) & 65280) + ((nb & 65280) << 8) + ((nb & 255) << 24));
}

int			ft_add_specify_entry(int *player_number, int *i, int *nb_champ, int val)
{
	int				tmp;
	int				j;

	if (player_number[val - 1] == 0)
	{
		player_number[val - 1] = *i + 1;
		*nb_champ += 1;
	}
	else
	{
		tmp = player_number[val - 1];
		j = val - 1;
		while (player_number[j] && j <= MAX_ARGS_NUMBER)
			j++;
		if (j <= MAX_ARGS_NUMBER && player_number[j] == 0)
		{
			player_number[val - 1] = *i + 1;
			player_number[j] = tmp;
			*nb_champ += 1;
		}
		else
			return (ft_error("Bad player number specification\n"));
	}
	return (1);
}


int			ft_specify_player(char **argv, int *player_number, int *i, int *nb_champ)
{
	int				val;

	*i+=1;
	if (*(argv + *i) && (val = ft_atoi(*(argv + *i))) > 0)
	{
		*i+=1;
		if (*(argv + *i) && val <= MAX_ARGS_NUMBER)
		{
			if (ft_add_specify_entry(player_number, i, nb_champ, val) < 1)
				return (0);
		}
		else
			return (ft_error("Error\n"));
	}
	else
		return (ft_error("Error\n"));
	return (1);
}

int			ft_add_entry(int *player_number, int i, int *nb_champ)
{
	int				j;

	j = 0;
	while (player_number[j] && j <= MAX_ARGS_NUMBER)
		j++;
	if (j <= MAX_ARGS_NUMBER)
	{
		player_number[j] = i + 1;
		*nb_champ += 1;
	}
	else
		return (ft_error("Too many champions\n"));
	return (1);
}

int			ft_manage_entry(char **argv, int *player_number)
{
	int             nb_champ;
	int             i;

	nb_champ = 0;
	ft_bzero(player_number, MAX_ARGS_NUMBER * 4);
	i = 0;
	while (*(argv + i))
	{
		if (!ft_strcmp(*(argv + i), "-n"))
		{
			if (ft_specify_player(argv, player_number, &i, &nb_champ) < 1)
				return (0);
		}
		else
		{
			if (ft_add_entry(player_number, i, &nb_champ) < 1)
				return (0);
		}
		i++;
	}
	if (nb_champ > MAX_PLAYERS)
		return (ft_error("Too many champions\n"));
	return (nb_champ);
}

int			ft_extract_header(int fd, t_header *champs)
{
	int				ret;
	char            buf[HEADER_SIZE];

	if ((ret = read(fd, buf, HEADER_SIZE)) < 1)
		return (0);
	ft_memcpy(champs, buf, HEADER_SIZE);
	champs->magic = ft_invert_endian(champs->magic);
	champs->prog_size = ft_invert_endian(champs->prog_size);
	if (champs->magic != COREWAR_EXEC_MAGIC)
	{
		ft_putstr("Wrong Magic number!!!!\n");
		return (0);
	}
	else
		ft_putstr("Magic number OK!\n");
	return (1);
}

int			ft_extract_prog(int fd, t_header *champs, unsigned char *memory)
{
	int				ret;
	char			buf[CHAMP_MAX_SIZE + 1];

	if ((ret = read(fd, buf, CHAMP_MAX_SIZE + 1)) < 1)
		return (0);
	if (ret > CHAMP_MAX_SIZE)
		return (ft_error("Champion too big!\n"));
	if ((unsigned int)ret != champs->prog_size)
	{
		ft_putstr("The size shown differs from the size of the program!\nSize information: ");
		ft_putnbr(ret);
		ft_putstr(" bytes\nSize program: ");
		ft_putnbr(champs->prog_size);
		ft_putstr(" bytes\n");
		champs->prog_size = ret;
	}
	ft_memcpy(memory, buf, ret);
	return (1);
}

t_header	*ft_insert_champ(char **argv, unsigned char *memory, int *player_number, int nb_champ)
{
	t_header		*champs;
	int				i;
	int				j;
	int				fd;

	champs = (t_header*)malloc(sizeof(t_header) * nb_champ);
	i = 0;
	j = 0;
	while (i < nb_champ)
	{
		while (player_number[j] == 0)
			j++;
		if ((fd = open(*(argv + player_number[j] - 1), O_RDONLY)) < 1)
			return (0);
		if (ft_extract_header(fd, champs + i) < 1)
			return (0);
		if (ft_extract_prog(fd, champs + i, (memory + i * (MEM_SIZE / nb_champ))) < 1)
			return (0);
		j++;
		ft_dump_memory((unsigned char*)(champs + i), HEADER_SIZE);
		ft_putstr("ICIIIIIII : ");
		ft_putstr((champs + i)->prog_name);
		ft_putchar('\n');
		ft_putstr((champs + i)->comment);
		ft_putchar('\n');
		ft_putnbr((champs + i)->prog_size);
		ft_putstr("\n\n");
		if (close(fd) == -1)
			return (0);
		i++;
	}
	ft_dump_memory(memory, MEM_SIZE);
	return (champs);
}

int 			ft_load_champ(char **argv, unsigned char *memory, t_header **champs)
{	
	int				nb_champ;
	int				player_number[MAX_ARGS_NUMBER];

	if (!(nb_champ = ft_manage_entry(argv, player_number)))
		return (0);

	/* NEW PART */
	/*
	   ft_putstr("nb_champ = ");
	   ft_putnbr(nb_champ);
	   ft_putchar('\n');
	   i=0;
	   while(i < MAX_ARGS_NUMBER)
	   {
	   ft_putnbr(player_number[i]);
	   ft_putstr("   <--\n");
	   i++;
	   }
	   */

	if (!(*champs = ft_insert_champ(argv, memory, player_number, nb_champ)))
		return (0);
	return (nb_champ);
}

t_process		*ft_init_process(t_settings *sets)
{
	t_process		*process;
	t_process		*tmp;
	unsigned int	i;

	i = 0;
	process = NULL;
	while (i < sets->nb_champs)
	{
		tmp = (t_process*)malloc(sizeof(t_process));
		if (!process)
			tmp->next = NULL;
		else
			tmp->next = process;
		process = tmp;
		process->player = i + 1;
		process->position = i * (MEM_SIZE / sets->nb_champs);
		process->turns_count = 0;
		i++;
	}
	return (process);
}

int				ft_play(unsigned char *memory, t_header *champs, t_settings *sets)
{
	t_process		*process;
	unsigned int	i;

	(void)memory;
	process = ft_init_process(sets);
	
	
	
	ft_putchar('\n');
	i = 0;
	while (i < sets->nb_champs)
	{
		ft_putstr((champs + process->player - 1)->prog_name);
		ft_putchar('\n');
		ft_putnbr(process->position);
		ft_putstr("\n\n");
		process = process->next;
		i++;
	}
	return (1);
}

int				ft_corewar(char **argv)
{
	unsigned char	*memory;
	t_header		*champs;
	t_settings		sets;

	if (!(memory = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)))
		return (-1);
	if (!(sets.nb_champs = ft_load_champ(argv + 1, memory, &champs)))
		ft_error("Can t load champions!\n");
	ft_play(memory, champs, &sets);
	ft_putstr("ALLLLLLLLLLOOOOOOOOOOO\n");
	ft_putstr((g_op_tab + 13)->desc);
	/*ft_dump_memory(memory, MEM_SIZE);*/
	return (1);
}

int				main(int argc, char **argv)
{
	if (argc < 2)
	{
		return(ft_usage());
	}
	ft_corewar(argv);
	return(1);
}
