//Cracked by Roath
// 孤山 1
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "孤山");
    set("long", @LONG
通过林荫道向前，迎面石壁上刻有“孤山”两个丹红大字。朝南
拾级登山便是平台。东北边便是发鹤亭。东南边则是平湖秋月。西北
边通往西冷桥。
LONG);

   set("exits", ([ /* sizeof() == 4 */ 
        "southup"   : __DIR__"gushan2", 
        "northeast" : __DIR__"fanghe", 
        "east" : __DIR__"pinghu", 
        "northwest" : __DIR__"xileng",
                ])
       );
	set("cost", 3);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}