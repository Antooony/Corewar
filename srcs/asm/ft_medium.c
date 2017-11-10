/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:43:39 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/10 18:47:24 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_nospace(t_token *tok, char *str, int a)
{
	int i;
	char c;

	*ft_strchr(str, '"') = '\0';
	i = ft_strlen(str);
	ft_push_token(tok, str, a, 1);
	*ft_strchr(str, '\0') = '"';
	c = *ft_strrchr(str, '"') + 1;
	*ft_strrchr(str, '"') + 1 = '\0';
	ft_push_token(tok, &str[i], a, i);
	i = ft_strlen(str);
	*ft_strrchr(str, '"') + 1 = c;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0' && str[i] != '#' && str[i] != ';')
	{
		while (*(str + i) != '\0' && 
	

void	ft_medium(t_token *tok, char *str, int a)
{
	if (!ft_strchr(str, ' '))
		ft_nospace(tok, str, a);
	else if (ft_strchr(str, '"') < ft_strchr(str, ' '))
		ft_nospace(tok, str, a);
	else
		ft_espace(tok, str, a);
}
