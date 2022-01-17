/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:27:46 by mservais          #+#    #+#             */
/*   Updated: 2021/11/08 15:51:40 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <limits.h>

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_data
{
	int		*arr;
	int		*pivots;
	int		chunks;
	int		chunk_size;
	int		nbr_elemts;	
}				t_data;

/* Push_swap */
int		stack_is_sorted(t_list *lst);
void	sort_stack(t_data *data, t_list **lst_a, t_list **lst_b);

/* Operations */
void	swap(int *x, int *y);
void	swap_top(t_list **lst, char *instruction);
void	push_top(t_list **lst_1, t_list **lst_2, char *instruction);
void	rotate(t_list **lst, char *instruction);
void	rev_rotate(t_list **lst, char *instruction);

/* Sorting small list */
void	sort_three(t_list **lst);
void	sort_four(t_list **lst1, t_list **lst2);
void	sort_five(t_list **lst1, t_list **lst2);

/* Sorting large list */
void	insertion_sort(t_data *data, t_list **lst1, t_list **lst2);
void	search_chunk(t_data *data, t_list **lst_a, t_list **lst_b, int j);
void	sort_b(t_data *data, t_list **lst_b, t_list **lst_a);
void	sort_large(t_data *data, t_list **lst_a, t_list **lst_b);

/* Quick sorting */
int		partition(int *arr, int low, int high);
void	quick_sort(int *arr, int low, int high);

/* Initialization of stack and data */
t_list	*initialize_stack(int nbr_elemts, char **argv);
int		*copy_lst(t_list *lst, int nbr_elemts);
int		*find_pivots(t_data *data);
int		set_nbr_chunks(t_data *data);
t_data	*initialize_data(t_list *lst_a, int nbr);

/* Helper functions */
void	print_instruction(char *instruction);
int		find_min(t_list **lst);
int		find_max(t_list **lst);
void	send_top(t_list **lst, int nbr, int nbr_elemts, char *instr);
int		nbr_elemts(t_list **lst);
int		find_index_first(t_data *data, t_list **lst_a, int j);
int		find_index_last(t_data *data, t_list **lst_a, int j);
int		find_index(t_data *data, t_list **lst_a, int j);

/* Error handling */
int		error_message(void);
int		find_errors(char **argv, int argc);

/* Freeing memory */
void	free_stack(t_list **lst);
void	free_number_list(char **input, int nbr_elemts);
void	free_all(t_data *data, t_list **lst_a, t_list **lst_b);

#endif
