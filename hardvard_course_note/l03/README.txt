Fun reading about a floating point representation hack:

  http://en.wikipedia.org/wiki/Fast_inverse_square_root

mexplore.c contains programs like those we used in lecture. Change
main() to call one of the mainNN() programs.

Things to try for testsum (this should work on Linux or on Mac OS X):

  % make
  % ./testsum
  % ./testsum 2 4
  % ./testsum 60 1

Here are some of the sum versions from class:

  unsigned sum(unsigned a, unsigned b) {
      return a + b;
  }
  char *sum(char *a, int b) {
      return &a[b];
  }
