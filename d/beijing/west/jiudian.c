//Cracked by Roath
// Room: /d/beijing/west/jiudian.c

inherit ROOM;

void create()
{
	set("short", "小酒店");
	set("long", @LONG
这是一个很小的酒店，生意看上去十分清淡，买的也只是普通白
干，茴香豆之类。若不是对面有回春堂，恐怕早就关门了。店里零散
的坐着几个人，店小二招呼得也不是很起劲。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baozhu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
