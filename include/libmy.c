#include "libmy.h"

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(char *str)
{
  int j;

  j = 0;
  while (str[j] != '\0')
    {
      my_putchar(str[j]);
      str++;
    }
}

int my_strlen(char *str)
{
  int a;

  a = 0;
  while (*str != '\0')
    {
      str = str + 1;
      a = a + 1;
    }
  return (a);
}

void my_put_nbr(int n)
{
  int t;

  t = 0;
  if (n < '\0')
    {
      my_putchar('-');
      if (n == (-2147483647 - 1))
	{
	  n = n + 1;
	}
      n = n * -1;
    }
  if (n >= 10)
    my_put_nbr(n / 10);
  if (t == 1)
    my_putchar(n % 10 + '1');
  else
    my_putchar(n % 10 + '0');
}
