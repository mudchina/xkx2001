//Cracked by Roath
// Room: /d/beijing/zijincheng/dafotang.c

inherit ROOM;

void create()
{
	set("short", "大佛堂");
	set("long", @LONG
这是一间佛堂，比一般人家的佛堂要大的多。正中一尊佛像，前
面有只香案，上面点着几柱香。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"cininggong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
