//Cracked by Roath
// datefile for assign job
// by ALN

#include <dbase.h>

void create()
{
        seteuid(0);
}

void setup()
{
        seteuid(getuid(this_object()));
}
