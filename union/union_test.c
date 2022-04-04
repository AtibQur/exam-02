/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:30:13 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/04 13:34:50 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int    main(int argc, char **argv)
{
    int used[255];
    int i, j;

    if (argc == 3)
    {
        i = 0;
        while (i < 255)
            used[i++] = 0;
        i = 1;
        while (i < 3)
        {
            j = 0;
            while (argv[i][j])
            {
                if (!used[(unsigned char)argv[i][j]])
                {
                    used[(unsigned char)argv[i][j]] = 1;
                    write(1, &argv[i][j], 1);
                }
                j++;
            }
            i++;
        }
    }



    write (1, "\n", 1);
    return (0);
}