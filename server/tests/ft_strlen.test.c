#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_strlen.c"

#define GREEN "\033[38;5;84m"
#define RED "\033[38;5;197m"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"
#define CHECKMARK "\xE2\x9C\x93"
#define putchar custom_putchar

typedef struct s_test
{
  char *desc;
  char *input;
  int expected_output;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
  t_test tests[] = {
      {
          .desc = "Empty string",
          .input = "",
          .expected_output = 0,
      },
      {
          .desc = "Single character",
          .input = "H",
          .expected_output = 1,
      },
      {
          .desc = "Long string with no null character",
          .input = "Hello, world!",
          .expected_output = 13,
      },
      {
          .desc = "Long string with null character",
          .input = "Hello\0, world!",
          .expected_output = 5,
      },
      {
          .desc = "Very long string",
          .input = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",
          .expected_output = 62,
      },
  };
  int count = sizeof(tests) / sizeof(tests[0]);

  return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
  int i;
  int error = 0;

  for (i = 0; i < count; i++)
  {
    int result = ft_strlen(tests[i].input);

    if (result != tests[i].expected_output)
    {
      printf("    " RED "[%d] ft_strlen(\"%s\") Expected %d, got %d\n" DEFAULT, i + 1, tests[i].input, tests[i].expected_output, result);
      error -= 1;
    }
    else
    {
      printf("  " GREEN CHECKMARK GREY " [%d] ft_strlen(\"%s\") output %d as expected\n" DEFAULT, i + 1, tests[i].input, result);
    }
  }

  return error;
}