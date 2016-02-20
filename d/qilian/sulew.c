//Cracked by Roath
#include "room.h"

inherit ROOM;

void create()
{
  set ("short", "疏勒河西岸");
  set ("long", @LONG
河水沿着大泉的冰河河床下到甘肃，水势渐缓，在鸣沙山和三危
山间冲刷出一道山崖断层。莫高窟就座落在西面鸣沙山的断层上。
LONG);

	set("exits", ([
                "west" : __DIR__"mingsha",

        ]));
	set("outdoors", "/d/qilian");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

