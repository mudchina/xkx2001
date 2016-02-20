//Cracked by Roath
// 三潭映月
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "亭亭亭");
    set("long", @LONG
亭外池中有一块形壮怪异的大石，九狮石。你凝神仔细观望，那
块大石果然有点像一头狮子。往南穿过曲桥是竹径通幽，东南和西南
分别是一条沿堤小路。
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
        "south" : __DIR__"santan4", 
	"southeast" : __DIR__"santan2",
	"southwest" : __DIR__"santan7",
                 ])
       );
    setup();
    replace_program(ROOM);
}