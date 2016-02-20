//Cracked by Roath
// chuanwu.c 船坞
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "船坞");
	set("long", @LONG
这里是云集了全国最好的造船技师和工匠。一眼望去，满是已完工和即将
完工的各种用途，各种大小的木船。坞内人们忙忙碌碌，一片繁忙景象。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"gangkou2",
	]));

        set("objects", ([ 
		__DIR__"npc/kuli" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
