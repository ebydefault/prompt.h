#   Simple looping interactive prompts

Tired of repeating myself,
I wrote this simple module to grab user input (hopefully) securely.

Currently only integer and single character input are supported

##  Functions available

All functions are member of `prompt` structure,
and should be called with dot operator,
e.g. `prompt.yesno("Are you hungry? ")`.

- `bool binopt(char* prompt, char opt_y, char opt_n)`

  Binary options prompt, with case-insensitive input.

- `bool yesno(char* prompt)`

  Y/N prompt, a shorthand for `bin_prompt()`, with `Y` or `N` input.

- `int intrange(char* prompt, int min, int max)`

  Integer prompt: `min <= input <= max`.
  
  When `min > max`, you'll get an endless loop.

- `int intbetween(char* prompt, int min, int max)`

  Integer prompt: `min < input < max`.
  
  When `min > max`, you'll get an endless loop.

##  Issues with musl

Tested with musl 1.1.24-1 and valgrind 3.150 on Ubuntu 20.04.2 LTS (WSL 2).

1. `musl-gcc` needs `static` flag, e.g.

   ```
   musl-gcc -static demo.c -o demo.out
   ```

   Otherwise, valgrind will throw an error: `__libc_freeres: symbol not found`.

   This error has been around sometime (GIYBF),
   but I haven't digged it any further.

2. Weird newlines behaviour.

   This seems to be a problem with musl `scanf()` implementaion.

Any contribution will be absolutely appreciated.
