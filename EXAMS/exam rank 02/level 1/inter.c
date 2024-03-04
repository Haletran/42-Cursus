
#include <unistd.h>

void ft_intersect(char *str1, char *str2)
{
   int i = 0;
   int j;

   while (str1[i] != '\0')
   {
      j = 0;
      while (str2[j] != '\0')
      {
         if (str1[i] == str2[j])
         {
            int k = 0;
            while (k < i)
            {
               if (str1[k] == str1[i])
                  break;
               k++;
            }
            if (k == i)
               write(1, &str1[i], 1);
            break;
         }
         j++;
      }
      i++;
   }
   write(1, "\n", 1);
}

int main(int ac, char **av)
{
   if (ac == 3)
      ft_intersect(av[1], av[2]);
    else 
      write(1, "\n", 1);
   return 0;
}

