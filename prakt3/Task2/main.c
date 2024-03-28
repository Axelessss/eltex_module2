#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10

void gen_dest(int (*Dst)[N], int count)
{
    srand(time(0));

    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            Dst[i][j] = rand()%256;
        }
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

void Net_Src(int *ip, int *mask, int *src)
{
    for(int i = 0; i < 4; i++)
        src[i]=ip[i]&mask[i];
  
    
}

void Net_Dst(int (*ip)[N], int *mask, int (*dst)[N], int count)
{
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            dst[i][j] = ip[i][j]&mask[j];
        }
    }

}

void Net_Cmp(int *src, int (*dst)[N], int *pack, int count)
{
    int res = 0;

    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            res += src[j]^dst[i][j];
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
    int IP_Dst[N][N];
    int mask[N];
    int net_src[N];
    int net_dest[N][N];
    int count;
    int pack[] = {0, 0};

    if(argc != 4)
    {
        printf("Too few args ");
        return 1;
    }

    get_nums(argv[1], IP_Src);
    get_nums(argv[2], mask);
    count = atoi(argv[3]);

    gen_dest(IP_Dst, count);
    Net_Src(IP_Src, mask, net_src);
    Net_Dst(IP_Dst, mask, net_dest, count);
    
    Net_Cmp(net_src, net_dest, pack, count);

    printf("Пакеты данной сети: %d, %d %% от всех пакетов\n", pack[0], pack[0]/count*100);
    printf("Пакеты других сетей: %d, %d %% от всех пакетов\n", pack[1], pack[1]/count*100);
    return 0;
}