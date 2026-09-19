#include <REGX52.H>
#include "Nixie.h"
#include "key.h"
#include "Delay.h"
#include "Buzzer.h"

unsigned char KeyNum;

void main()
{
    NixieTube(1,0);
	while(1)
    {
        KeyNum = Key();
        if(KeyNum){
            Buzzer_Time(100);
            NixieTube(1,KeyNum);
        }
    }
}