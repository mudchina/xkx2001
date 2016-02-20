//Cracked by Roath
// 洪春桥
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "洪春桥");
    set("long", @LONG
从这里可以看到西湖十景之一的双峰插云(scenery)。大道东西走  
向，再向西是通往灵隐寺的路。
LONG
);

    set("item_desc", 
	   ([
            "scenery" : 
		"双峰，南高峰在西湖之西南，北高峰在西湖之西北。南北遥遥相对，\n"
		"只见宿雨初收，双峰隐现在轻风薄雾之中，或浓或淡，时有时无；雾\n"
		"层飘移，卷舒断续，变幻无穹。\n"
           ])
	);
    set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"road31", 
                  "west" : __DIR__"road32", 
                ])
       );
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
