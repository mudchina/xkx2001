//Cracked by Roath
// workroom.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "´ó³µ");
        set("valid_startroom",1);
        
	set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
