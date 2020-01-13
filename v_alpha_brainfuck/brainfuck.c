#include <unistd.h>
#include <stdio.h>

char    *ft_brainfuck(char *str) {
    int i = -1, curr = 0, p = 0, j = 0;
    char tab[4096];

    while (tab[i])
        tab[i++] = 0;
    i = 0;

    while (str[i]) {
        if (str[i] == '+')
            tab[curr]++;
        else if (str[i] == '-')
            tab[curr]--;
        else if (str[i] == '>')
            curr++;
        else if (str[i] == '<')
            curr--;
        else if (str[i] == '.')
            write(1,&tab[curr],1);
        else if (str[i] == '[') {
            j = i;
            while (!(str[j] == ']' && tab[curr] == 0) && str[j]) {
                if (str[j] == '+')
                    tab[curr]++;
                else if (str[j] == '-')
                    tab[curr]--;
                else if (str[j] == '>')
                    curr++;
                else if (str[j] == '<')
                    curr--;
                else if (str[j] == '.')
                    write(1,&tab[curr],1);
                j++;
            }
            i = j;
        }
        else if (str[i] == ']')
            printf("KKK\n");
        i++;
    }
    return (str);
}

int main(int ac, char **av) {
    if (ac == 2) {
        if(av[1])
            ft_brainfuck(av[1]);
    }
    write(1,"\n",1);
    return (0);
} 