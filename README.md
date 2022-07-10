# Fixed-Point
A small fixed point class I made mainly for my nintendo ds projects, but can also be used for anything else

```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

#include "Fixed.h"

int main()
{
	f32 i = 22.2f;
	i /= 283.234f;
	
	printf("%d\n", i.Fixed);
	printf("%f\n", i.Float());

	return 0;
}
```
