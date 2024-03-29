#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define N 10

void gen_dest(int *Dst)
{
    for(int i = 0; i < 4; i++)
    {
        Dst[i] = rand()%256;
    }  
}

void get_nums(char *addr, int* result)
{
    int i = 0;
    char* src = strtok(addr, ".");

    while (src != NULL)
    {
        result[i] = atoi(src);
        src = strtok(NULL, " ,.");
        i++;
    }
}

void Net_gen(int *ip, int *mask, int *net)
{
    for(int i = 0; i < 4; i++)
        net[i]=ip[i]&mask[i];
}

void Net_Dst(int *ip, int *mask, int *dst)
{
    gen_dest(ip);
    for(int i = 0; i < 4; i++)
    {
        dst[i] = ip[i]&mask[i];
    }
}

void Net_Cmp(int *src, int *mask, int *pack, int count)
{
    int res = 0;
    int dst[4];
    int net_src[4];
    int net_dst[4];

    Net_gen(src, mask, net_src);
    

    for(int i = 0; i < count; i++)
    {
        gen_dest(dst);
        Net_gen(dst, mask, net_dst);
        
        for(int j = 0; j < 4; j++)
        {
            res += net_src[j]^net_dst[j];
        }

        if(res == 0)
            pack[0]++;
        else
            pack[1]++;

        res = 0;
    }
}

int main(int argc, char* argv[])
{
    int IP_Src[N];
    int mask[N];
    int count;
    int pack[] = {0, 0};

    srand(time(0));

    if(argc != 4)
    {
        printf("Too few arguments ");
        return 1;
    }

    get_nums(argv[1], IP_Src);
    get_nums(argv[2], mask);
    count = atoi(argv[3]);
    
    Net_Cmp(IP_Src, mask, pack, count);

    printf("Пакеты данной сети: %d, %f %% от всех пакетов\n", pack[0], ((float)pack[0]*100)/count);
    printf("Пакеты других сетей: %d, %f %% от всех пакетов\n", pack[1], ((float)pack[1]*100)/count);
    return 0;
}