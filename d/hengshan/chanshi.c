//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "禅室");
        set("long", 
"一间不大的禅室，为恒山掌门定闲师太日常静修之所，
但见四壁萧然，只地下有个旧蒲团，此外一无所有。\n");
        
set("exits", ([
                "out"  : __DIR__"annei",
        ]));
        set("no_clean_up", 0);
	  set("cost", 1);
        setup();
        replace_program(ROOM);
}

