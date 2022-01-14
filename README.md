#   Simple looping interactive prompts

Tired of repeating myself,
I wrote this simple module to grab user input (hopefully) securely.

Currently, only integer and single character input are supported.

##  Functions available

All functions are member of `prompt` structure,
and should be called with dot operator,
e.g. `prompt.yesno("Are you hungry? ")`.

- `static int intrange(char* prompt, int min, int max)`

  Integer prompt: `min <= input <= max`.
  
  When `min > max`, you'll get an endless loop.

- `static int intbetween(char* prompt, int min, int max)`

  Integer prompt: `min < input < max`.
  
  When `min > max`, you'll get an endless loop.

- `static bool binopt(char* prompt, char opt_y, char opt_n)`

  Binary options prompt, with case-insensitive input.

- `static bool yesno(char* prompt)`

  Y/N prompt, a shorthand for `bin_prompt()`, with `Y` or `N` input.

##  Issue with musl

`musl-gcc` needs `static` flag, e.g.

```
musl-gcc -static demo.c prompt.c -o demo.out
```

Otherwise, valgrind will throw an error: `__libc_freeres: symbol not found`.

This error has been around sometime (GIYBF),
but I haven't digged it any further.

Tested with musl 1.1.24-1 and valgrind 3.150 on Ubuntu 20.04.2 LTS (WSL 2).

Any contribution will be absolutely appreciated.
