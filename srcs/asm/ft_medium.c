/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:43:39 by nagaloul          #+#    #+#             */
/*   Updated: 2017/11/10 20:26:26 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void	ft_naco(t_token *tok, char *str, int *count, int b)
{
	int i;
	char temp;

	i = ft_sip(str);
	temp = str[i];
	str[i] = '\0';
	ft_push_token(tok, str, *count, b);
	str[i] = temp;
}

void	ft_medium(t_token *tok, char *str, int a)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		ft_naco(tok, &str[i], &i, a);

}
