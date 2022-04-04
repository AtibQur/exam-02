/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:06:28 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/04 16:11:48 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int used[255];
    int i, j;

    if (argc == 3)
    {
        i = 0;
        while (i < 255)
            used[i++] = 0;
        i = 2;
        while (i > 0)
        {
            j = 0;
            while (argv[i][j])
            {
                if (i == 2 && !used[(unsigned char)argv[i][j]])
                    used[(unsigned char)argv[i][j]] = 1;
                if (i == 1 && used[(unsigned char)argv[i][j]] == 1)
                {
                    write(1, &argv[i][j], 1);
                    used[(unsigned char)argv[i][j]] = 2;
                }
                j++;
            }
            i--;
        }
    }
    write(1, "\n", 1);
    return (0);
}