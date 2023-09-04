/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tremy <tremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:29:58 by nbrabant          #+#    #+#             */
/*   Updated: 2023/09/04 15:55:47 by tremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct node
{
	int			value;
	struct node	*previous;
	struct node	*next;
}	t_node;

int		*ft_create_list_numbers(int *len, char **input, int i);
int		ft_get_length(char **str);
void	ft_error(void);
t_node	**ss(t_node **s_table, int toggle);
t_node	**push(t_node **s_table, char s, int t);
t_node	**push1(t_node *src_h, t_node **s_table, char s, int t);
t_node	**push2(t_node *rec_h, t_node **s_table, int t);
t_node	**push3(t_node *rec_h, t_node *src_h, t_node **s_table);
t_node	*swap(t_node *head, char stack, int toggle);
int		ft_issort(t_node *head);
t_node	**lst_init_b(t_node **s_table);
void	ft_print_linked_list(t_node *head);
int		ft_lst_size(t_node	*head);
t_node	*ft_node_insert(t_node *head, int value);
t_node	*ft_node_delete(t_node *head);
void	ft_free_lst(t_node **s_table, int toggle);
t_node	*create_linked_list(int *numbers, int len);
t_node	*lst_init(int first_value);
t_node	**rota(t_node **s_table, char stack, int toggle);
t_node	**rev_rota(t_node **s_table, char stack, int toggle);
int		ft_both_up(int pos_a, int pos_b);
int		ft_both_down(int pos_a, int pos_b, t_node **s_table);
int		ft_pos_b(int cv, t_node *head_b);
int		ft_calcul(int cv, int pos_a, t_node **s_table);
t_node	*ft_compare(t_node **s_table);
int		ft_lst_min(t_node *head);
int		ft_lst_max(t_node *head);
int		ft_lst_find_max(t_node *head, int max);
int		ft_lst_find_min(t_node *head, int min);
int		ft_pathfinder(int pos_a, int pos_b, t_node **s_table);
t_node	**ft_fill_b(t_node **s_table);
t_node	*lst_finder(t_node *head, int value);
t_node	**ft_pattern_manager(t_node *a, t_node *b, t_node **s_table, int i);
t_node	**ft_pattern_dblup(t_node *a, t_node *b, t_node **s_table);
t_node	**ft_pattern_dbldwn(t_node *a, t_node *b, t_node **s_table);
t_node	**ft_pattern_aup(t_node *a, t_node *b, t_node **s_table);
t_node	**ft_pattern_bup(t_node *a, t_node *b, t_node **s_table);
int		ft_up_a(int a, int b, t_node **s_table);
int		ft_up_b(int a, int b, t_node **s_table);
t_node	*lst_sort_a(t_node **s_table);
t_node	**ft_fill_a(t_node **s_table);
t_node	**ft_push2(t_node **s_table, int max_a, int i);
t_node	**ft_sort_b(t_node **s_table);
t_node	**ft_sort_end_a(t_node **s_table);
int		pos_finder(t_node *head, int value);
int		ft_check_init(t_node **stack_table);
void	ft_free_tab(char **tab, int toggle);
int		ft_is_zero(char *str, size_t len);

#endif