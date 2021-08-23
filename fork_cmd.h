/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_cmd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:45:47 by CWatcher          #+#    #+#             */
/*   Updated: 2021/08/26 15:46:20 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_CMD_H
# define FORK_CMD_H

void	fork_cmd(const char *cmd, char *envp[], int fd_in, int fd_out);

#endif