/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:21:35 by iel-ferk          #+#    #+#             */
/*   Updated: 2020/01/07 17:29:59 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // for test
#include <stdlib.h>

int     ft_strlen(char *str) {
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char    *ft_strcat(char *s1, char *s2) {
    char *s;
    int i = 0, j = 0;

    if (!(s = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 100))))
        return (NULL);
    while(s1[i]) {
        s[i] = s1[i];
        i++;
    }
    while (s2[j]) {
        s[i] = s2[j];
        i++;
        j++;
    }
    s[i] = '\0';
    return (s);
}

char    *ft_itoa(unsigned int n) {
    char *r, c;
    int i = 0, j = 0;

    if(!(r = (char*)malloc(sizeof(char) * 100)))
        return (NULL);
    if (n <= 0)
        return ("0");
    while(n > 0) {
        r[i] = n % 10 + 48;
        n = n / 10;
        i++;
    }
    i--;
    while (r[j] && j < i) {
        c = r[j];
        r[j] = r[i];
        r[i] = c;
        i--;
        j++;
    }
    return (r);
}

char    *moment(unsigned int duration) {
    if (duration <= 0)
        return ("0 seconds ago.");
    else if (duration == 1)
        return ("1 second ago.");
    else if (duration < 60)
        return (ft_strcat(ft_itoa(duration)," seconds ago."));
    else if (duration < 120)
        return (ft_strcat(ft_itoa(duration / 60)," minute ago."));
    else if (duration < 3600)
        return (ft_strcat(ft_itoa(duration / 60)," minutes ago."));
    else if (duration < 7200)
        return (ft_strcat(ft_itoa(duration / 3600)," hour ago."));
    else if (duration < 86400)
        return (ft_strcat(ft_itoa(duration / 3600)," hours ago."));
    else if (duration < 172800)
        return (ft_strcat(ft_itoa(duration / 86400)," day ago."));
    else if (duration < 2592000)
        return (ft_strcat(ft_itoa(duration / 86400)," days ago."));
    else if (duration < 5184000)
        return (ft_strcat(ft_itoa(duration / 2592000)," month ago."));
    else
        return (ft_strcat(ft_itoa(duration / 2592000)," months ago."));
}

int main(int ac, char **av) // for test
{
    printf("date ===>%s\n",moment(atoi(av[1])));
    return (0);
}