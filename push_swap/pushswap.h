/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrabant <nbrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:29:58 by nbrabant          #+#    #+#             */
/*   Updated: 2023/08/16 17:14:09 by nbrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct node
{
	int value;
	struct node *previous;
	struct node *next;
} node_t;

int		*ft_create_list_numbers(int size_input, char **input);
int		ft_get_length(char **str);
void	ft_error(void);
node_t	**ss(node_t **s_table);
node_t	**push(node_t *src_h, node_t *rec_h, node_t **s_table, char stack);
node_t	*swap(node_t *head, char stack);
int		ft_issort(node_t *head);
node_t	**lst_init_b(node_t **s_table);
void	ft_print_linked_list(node_t *head);
int		ft_lst_size(node_t	*head);
node_t	*ft_node_insert(node_t *head, int value);
node_t	*ft_node_delete(node_t *head);
void	ft_free_lst(node_t **s_table, int toggle);
node_t	*create_linked_list(int *numbers);
node_t	*lst_init(int first_value);
node_t	**rota(node_t **s_table, char stack);
node_t	**rev_rota(node_t **s_table, char stack);
int		ft_both_up(int pos_a, int pos_b);
int		ft_both_down(int pos_a, int pos_b, node_t **s_table);
int		ft_pos_b(int cv, node_t *head_b);
int		ft_calcul(int cv, int pos_a, node_t **s_table);
node_t	*ft_compare(node_t **s_table);
int 	ft_lst_min (node_t *head);
int 	ft_lst_max (node_t *head);
int		ft_lst_find_max(node_t *head, int max);
int		ft_lst_find_min(node_t *head, int min);
int		ft_pathfinder(int pos_a, int pos_b, node_t **s_table);
node_t 	**ft_fill_b(node_t **s_table);
node_t	*lst_finder(node_t *head, int value);
node_t	**ft_pattern_manager(node_t *a, node_t *b, node_t **s_table, int i);
node_t 	**ft_pattern_dblup(node_t  *a, node_t *b, node_t **s_table);
node_t 	**ft_pattern_dbldwn(node_t  *a, node_t *b, node_t **s_table);
node_t 	**ft_pattern_aup(node_t  *a, node_t *b, node_t **s_table);
node_t 	**ft_pattern_bup(node_t  *a, node_t *b, node_t **s_table);
int		ft_up_a(int a, int b, node_t **s_table);
int		ft_up_b(int a, int b, node_t **s_table);
node_t 	*lst_sort_a(node_t **s_table);
node_t	**ft_fill_a(node_t **s_table);
node_t	**ft_push2(node_t **s_table, int max_a, int i);
node_t	**ft_sort_b(node_t **s_table);
node_t	**ft_sort_end_a(node_t **s_table);
int		lst_pos_finder(node_t *head, int value);
int		ft_check_init(node_t **stack_table);

#endif