//Cracked by Roath
// huru.c 虎乳泉
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "虎乳泉");
	set("long", @LONG
这是一块斜卧着的石皮，有泉水从缝隙中迸出，流入一个尺余见方的石孔
中。它流了不知多少岁月了，但从来不涸。水清洌见底，甘甜似乳，用它泡茶，
香味沁人心脾。泉州及清源山得名「泉山」，皆源于此泉。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northup" : __DIR__"qingyuan",
		"southdown" : __DIR__"shanlu2",
	]));

	set("resource/water", 1);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
