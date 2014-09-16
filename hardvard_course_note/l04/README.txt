Fun reading about a floating point representation hack:

  http://en.wikipedia.org/wiki/Fast_inverse_square_root

Things to try (this should work on Linux or on Mac OS X):

  % make
  % ./testsum
  % ./testsum 2 4
  % ./testsum 60 1
  % ./testsum 100000000000000 1
  % ./testsum-web http://cs61.seas.harvard.edu/cs61wiki/skins/common/images/cs61hello.jpg 0x9F00
  % ./testsum-file hello.jpg 0x9F00 100 2

Here are some of the sum versions from class:

  unsigned sum(unsigned a, unsigned b) {
      return a + b;
  }
  char *sum(char *a, int b) {
      return &a[b];
  }
  int *sum(int *a, int b) {
      return &a[b];
  }
  const unsigned char sum[] = {
      0x8b, 0x44, 0x24, 0x08, 0x03, 0x44, 0x24, 0x04, 0xc3
  };

From Nate Herman:

  % ./testsum-web http://www.pnveneto.org/wp-content/uploads/2009/03/venezia-repubblica-cartina.gif 0x1f6d4
  % ./testsum-web http://www.pnveneto.org/wp-content/uploads/2009/03/venezia-repubblica-cartina.gif 0x1f6d4 1 3
  % ./testsum-web http://www.pnveneto.org/wp-content/uploads/2009/03/venezia-repubblica-cartina.gif 0x1f6d4 4 0
  % ./testsum-web http://www.pnveneto.org/wp-content/uploads/2009/03/venezia-repubblica-cartina.gif 0x1f6d4 100 200
  % ./testsum-web http://upload.wikimedia.org/wikipedia/commons/4/48/Akn_leer.png 0xede65

The evil program only works on Linux.

  % ./testsum-file hello-evil.jpg 72
