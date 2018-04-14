/*#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int results;
	int a = 9;
	results = sqrt(a);

	printf("results: %d\n", results);
	return 0;
}*/
/* sqrt example */
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

int main ()
{
  double param, result;
  param = 1024.0;
  result = sqrt (param);
  printf ("sqrt(%f) = %f\n", param, result );
  return 0;
}