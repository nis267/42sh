/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   job_is.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 22:53:51 by ythollet     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 22:53:51 by ythollet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "shell.h"

t_job *find_job(pid_t pgid)
{
	t_job *j;

	for (j = first_job; j; j = j->next)
		if (j->pgid == pgid)
			return j;
	return NULL;
}

/*
** Return true if all processes in the job have stopped or completed.
*/

int job_is_stopped(t_job *j)
{
	t_cmd *p;

	p = j->cmds;
	while (p)
	{
		if (!p->stopped)
			return (0);
		p = p->next_cmd;
	}
	return (1);
}

/*
** Return true if all processes in the job have completed.
*/

int job_is_completed(t_job *j)
{
	t_cmd *p;

	p = j->cmds;
	while (p)
	{
		if (!p->completed)
			return (0);
		p = p->next_cmd;
	}
	return (1);
}
