//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "後厅");
        set("long", @LONG
这是一间极有品味的小厅，四周的墙上挂满了名家字画，正中的
墙壁上是唐伯虎的“朱雀图”，厅内摆了几张雕木做的桌椅，桌上放
着一壶清茶和几个茶杯，厅里溢满了茶香，确是上等的龙井。
LONG
        );
        set("exits", ([
                "south" : __DIR__"datang",
		"north" : __DIR__"xingtang",
        ]));

	set("objects", ([
//		"/d/city/obj/kaoya" : 1,
		"/d/quanzhou/obj/yadan" : 2,
	]));
                
	set("cost", 1);
        setup();
        replace_program(ROOM);
}
