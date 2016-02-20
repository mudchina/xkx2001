//Cracked by Roath
// Room: /d/shaolin/mishi.c
// Date: kane 98/03/26

#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "秘室");
	set("long", @LONG
这是一个布置得颇为整洁的小房间，此处像是深处地底，但
空气却十分清新，光线也很充足。地方虽然不大，屋中家什也不
多，但都摆放得井井有条，丝毫不见局促。
LONG
	);

	set("exits", ([
		"up" : __DIR__"andao2",
	]));

        set("objects", ([
                 "/d/shaolin/npc/chengkun" : 1,
	]));

	set("cost", 1);
	setup();
}
