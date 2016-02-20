//Cracked by Roath
// 三潭映月
// Dong  11/03/1996.
// Need to add connection to boat.

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "我心相印亭");
    set("long", @LONG
走进亭内往南一望，便可看见南湖面中的三个石塔。塔的中部中
空，塔面有五个小圆洞。每逢皓月当空，游客们纷纷来到此处观赏那
“月光映潭，影分为三”的三潭映月。东北和西北两边都有一条
沿湖石路。往北是一座九曲石桥。
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
        "north" : __DIR__"santan6", 
	"northeast" : __DIR__"santan2",
	"northwest" : __DIR__"santan7",
                 ])
       );
    setup();
    replace_program(ROOM);
}