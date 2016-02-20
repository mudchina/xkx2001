//Cracked by Roath
// item.c

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;
inherit F_CLONEABLE;

void setup()
{
	seteuid(getuid());
}
