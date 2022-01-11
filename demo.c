#include <stdio.h>
#include "prompt.h"

int main(void)
{
  if (prompt.binopt("\nIs 2 + 2 = 5 true or false? [T/F]: ", 'T', 'F'))
       printf("\n  Oh, you think it's true. I hope you can prove it.\n");
  else printf("\n  You think it's false. That's common sense.\n");

  if (prompt.yesno("\nAre you yes or no? [Y/N] "))
       printf("\n  You sounds like a yes-man.\n");
  else printf("\n  You're not afraid of saying no.\n");

  printf("\n  You chosed %d\n",
      prompt.intrange("\nChoose a number from 12 to 21 ...\n"
                      "  Try me by choosing 11, or 22, or even a letter: ", 12, 21));
  
  printf("\n  You chosed %d\n",
      prompt.intbetween("\nChoose a number between 55 and 66 ...\n"
                        "  Try me by choosing 55 or 66: ", 55, 66));
}
