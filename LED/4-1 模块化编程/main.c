#include <at89c51RC2.h>
#include "Delay.h"
#include "Nixie.h"

void main()
{
	while(1)
	{
		NixieTube(1,10);
		NixieTube(2,10);
		NixieTube(3,11);
		NixieTube(4,12);
		NixieTube(5,13);
		NixieTube(6,14);
	}
}
