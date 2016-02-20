//Cracked by Roath
// room: dadian.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "大殿");
        set("long", @LONG
这是一座宏伟的大殿，平时天鹰教首领们就在这里发号施令。殿
上竖着几根龙柱，两行椅子整齐的摆在两边。正对殿门的墙上挂着一
幅巨图，图上画着一只雄鹰，两边还有一幅对联(duilian)。
LONG );

        set("exits", ([
                "west" : __DIR__"zoulang1",
                "south" : __DIR__"guangchang",
		"east" : __DIR__"zoulang3",
		"north" : __DIR__"zoulang5",
        ]));

	set("item_desc", ([
		"duilian" : HIC "\n日月光照  天鹰展翅\n" NOR + HIC 				"圣焰熊熊  普惠世人\n" NOR,
	]));

        setup();
        replace_program(ROOM);
}
