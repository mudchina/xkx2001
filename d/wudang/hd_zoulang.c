//Cracked by Roath
// hd_zoulang.c 后殿走廊
// xQin 11/00

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "后殿走廊" );
	set("long", @LONG
这里是三清殿后的走廊，来往行人逐渐稀少。来往游人一般走到这里都
会止步。走廊东西两头可同往丹药房等地，南面便是后院。
LONG
	);
	set("exits", ([
		"south" : __DIR__"houyuan",
		"north" : __DIR__"sanqingdian",
		"east" : __DIR__"donglang1",
		"west" : __DIR__"xilang1",
	]));

	set("objects", ([
		"/kungfu/class/wudang/xi.c" : 1,
	]));
		
	setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "武当派") 
        && objectp(present("zhang songxi", environment(me))) ) {
        	
        if (dir == "east" || dir == "west" || dir == "south") 
           return notify_fail("张松溪喝道：里面是武当重地，闲人请止步。\n");
        }        
        return ::valid_leave(me, dir);
}
