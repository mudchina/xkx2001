//Cracked by Roath
// Room: /d/beijing/kangqin/neijiu.c

inherit ROOM;

void create()
{
	set("short", "内厩");
	set("long", @LONG
这里比外面的马厩要干净得多，饲料槽里的饲料也要
精细得多。地上铺了厚厚的干草。旁边有扇门，但已经给锁
死了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"majiu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
