/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:43:39 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/11 22:02:15 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_quotes(t_token **tok, char *str, int *count, int b)
{
	int i;
	char temp;

	i = 1;
	while (str[i] && str[i] != '"')
		i++;
	temp = str[i + 1];
	str[i + 1] = '\0';
	ft_push_token(tok, str, *count, b);
	str[i + 1] = temp;
	*count = *count + i;
}

static int	ft_sip(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '"'
			&& str[i] != ';' && str[i] != '#')
		i++;
	return (i);
}

static void	ft_naco(t_token **tok, char *str, int *count, int b)
{
	int i;
	char temp;

	i = ft_sip(str);
	temp = str[i];
	str[i] = '\0';
	ft_push_token(tok, str, *count, b);
	str[i] = temp;
	if (temp == '"')
		i--;
	*count = *count + i;
}

void	ft_medium(t_token **tok, char *str, int a)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == ';' || str[i] == '#')
			break ;
		if (str[i] == '"')
			ft_quotes(tok, &str[i], &i, a);
		else
			ft_naco(tok, &str[i], &i, a);
		if (str[i] == ';' || str[i] == '#')
			break ;
		i++;
	}
}
