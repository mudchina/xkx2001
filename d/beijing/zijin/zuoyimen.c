//Cracked by Roath
// Room: /d/beijing/zijincheng/zuoyimen.c

inherit ROOM;

void create()
{
	set("short", "左翼门");
	set("long", @LONG
这是太和殿前广场的一个侧门，通向文华殿。从这里向南是昭德
门，东面有一条小道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guang1",
  "east" : __DIR__"gzxd3",
  "south" : __DIR__"zhaodemen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
