# include <unistd.h>

char    *ft_brainfuck(char *str) {
    int i = -1, curr = 0, p = 0;
    char tab[4096];

    while (tab[i])
        tab[i++] = 0;
    i = 0;

    while (str[i]) {
        if (str[i] == '+')
            tab[curr]++;
        else if (str[i] == '-')
            tab[curr]--;
        else if (str[i] == '.')
            write(1,&tab[curr],1);
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