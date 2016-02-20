//Cracked by Roath
// Room: /d/beijing/west/yamen.c

inherit ROOM;

void create()
{
	set("short", "顺天府衙门");
	set("long", @LONG
这是顺天府衙所在之地，因为顺天府负责维护京畿一带治安，
责任重大，加之京城权贵众多，颇不易管辖，故而顺天府比之其它
州府要高上一级，衙门也威风许多。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guloudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
