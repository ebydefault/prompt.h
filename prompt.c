/* 
 * prompt.c
 *
 * Simple looping interactive prompts
 *
 *
 * Copyright 2022 Wardhana <ellam.bydefault@gmail.com>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "prompt.h"

// All functions are static ...
static int  intrange(char* msg, int min, int max);
static int  intbetween(char* msg, int min, int max);
static bool binopt(char* msg, char opt_true, char opt_false);
static bool yesno(char* msg);

// and should be called as a member of prompt, e.g. prompt.yesno(...)
struct Prompts prompt = {
  intrange,
  intbetween,
  binopt,
  yesno
};

/*** Integer prompt: min <= input <= max ***/

// When min > max, you'll get an endless loop.
int intrange(char* msg, int min, int max)
{
  int ret;
  int num;
  do
  {
    printf("%s", msg);
    fflush(stdout); // flush buffer before calling scanf().
    if ((ret = scanf("%d", &num)) < 0) exit (EXIT_FAILURE); // handle EOF
    while (getchar() != '\n');  // clear the input buffer
    if (num >= min && num <= max) return num;
  }
  while (true);
}

/*** Integer prompt: min < input < max ***/

// When min > max, you'll get an endless loop.
int intbetween(char* msg, int min, int max)
{
  return intrange(msg, min + 1, max - 1);
}

/*** Binary options msg ***/

// Input is case-insensitive.
bool binopt(char* msg, char opt_true, char opt_false)
{
  int ret;
  char opt;
  do
  {
    printf("%s", msg);
    fflush(stdout); // flush buffer before calling scanf().
    if ((ret = scanf("%c", &opt)) < 0) exit (EXIT_FAILURE); // handle EOF
    while (getchar() != '\n');  // clear the input buffer
    opt       = toupper(opt);
    opt_true  = toupper(opt_true);
    opt_false = toupper(opt_false);
    if (opt == opt_true) return true;
    if (opt == opt_false) return false;
  }
  while (true);
}

/*** Y/N prompt ***/

// Shorthand for binopt() with Y or N input.
bool yesno(char* msg)
{
  return binopt(msg, 'Y', 'N');
}
