/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:39:21 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/24 15:39:22 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_itoa(unsigned int nbr) {
    unsigned int i = 0, j = 0;
    char *str , c;

    str = (char *)malloc(sizeof(char) * 100);
    while(nbr > 0){
        str[i] = nbr % 10 + 48;
        nbr = nbr / 10;
        i++;
    }
    str[i] = '\0';
    i--;
    while (i > j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        j++;
        i--;
    }
    return (str);
}

char    *ft_strcat(char *s1, char *s2) {
    int i = 0, j = 0;
    char *s3;

    s3 = (char*)malloc(sizeof(char) * 500);

    while (s1[i]) {
        s3[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i]) {
        s3[j] = s2[i];
        i++;
        j++;
    }
    s3[j] = '\0';
    return (s3);
}

char    *moment(unsigned int duration) {
    char *str;

    if (duration == 0)
        return ("0 seconds ago.");
    else if (duration == 1)
        return ("1 second ago.");
    else if (duration < 60)
        return (ft_strcat(ft_itoa(duration)," seconds ago."));
    else if (duration < (60 * 2))
        return ("1 minute ago.");
    else if (duration < (60 * 60))
        return (ft_strcat(ft_itoa(duration/60)," minutes ago."));
    else if (duration < (60 * 60 * 2))
        return ("1 hour ago.");
    else if (duration < (60 * 60 * 24))
        return (ft_strcat(ft_itoa(duration / (60 * 60))," hours ago."));
    else if (duration < (60 * 60 * 24 * 2))
        return (ft_strcat(ft_itoa(duration),"1 day ago."));
    else if (duration < (60 * 60 * 24 * 30))
        return (ft_strcat(ft_itoa(duration / (60 * 60 * 24))," days ago."));
    else if (duration < (60 * 60 * 24 * 30 * 2))
        return ("1 month ago.");
    else
        return (ft_strcat(ft_itoa(duration / (60 * 60 * 24 * 30))," months ago."));
}
