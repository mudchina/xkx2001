//Cracked by Roath
// Room: /d/beijing/east/libu.c

inherit ROOM;

void create()
{
	set("short", "吏部");
	set("long", @LONG
吏部居六部之首，主管官吏甄别选拔，故而其中营私舞弊之
风甚重，每天吏部门口都冠盖云集，不外是功臣大将为子孙谋个
荫庇，或活动关节、买卖官爵之类。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : __DIR__"wangfudajie3",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
