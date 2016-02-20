//Cracked by Roath
// /d/hangzhou/yantian.c   盐田
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{        set("short", "盐田");
         set("long", @LONG
这里是浙东钱塘江入海口，海岸边一片片光滑如镜的平地，往往七八丈见
方，便是水磨的桌面也无此平整滑溜。那就是盐田。当地盐民引海水灌入盐田，
晒干以后，刮下含盐泥土，化成卤水，再逐步晒成盐粒。
LONG	);

         set("exits", ([ /* sizeof() == 2 */ 
                   "west" : __DIR__"haidi", 
		   "northeast" : __DIR__"hsmiao",
         ]));

	 set("objects", ([
                __DIR__"npc/hsbz" : 1,
                
         ]));

	 set("cost", 1);
         set("outdoors", "hangzhou");

         setup();

         replace_program(ROOM);
}
