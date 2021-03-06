/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   job_is.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 22:53:51 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/04 18:52:57 by gurival-    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
*** - Aim of the function : retrieve the pointer of the struct to avoid using
*** - a global
*/

t_js	*getter_job(void)
{
	static t_js job = (t_js) {.first_job = 0, .shell_pgid = 0,

	{ .c_iflag = 0, .c_oflag = 0, .c_cflag = 0, .c_lflag = 0 },
	.shell_terminal = 0, .shell_is_interactive = 0};
	return (&job);
}

int		put_job_done(t_job *j)
{
	t_cmd *p;

	p = j->cmds;
	while (p)
	{
		p->done = 1;
		p = p->next_cmd;
	}
	return (1);
}
