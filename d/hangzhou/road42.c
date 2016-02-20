//Cracked by Roath
// 茅家埠
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "茅家埠");
    set("long", @LONG
路两旁盖着几座小土房。房门口一位老大娘正在喂鸡，几个小孩
正在追逐嬉戏。北边是上黄泥岭。南面是丁家山。
LONG
        );

    set("exits", ([ /* sizeof() == 2 */ 
                   "northup" : __DIR__"road41", 
                   "southwest" : __DIR__"road43", 
                 ])
        );
	set("objects", ([ "/d/village/npc/boy" : 1,
			  "/d/village/npc/oldwoman" : 1]));

	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
