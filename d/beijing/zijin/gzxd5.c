//Cracked by Roath
// Room: /d/beijing/zijincheng/gzxd5.c

inherit ROOM;

void create()
{
	set("short", "¹¬ÖÐÐ¡µÀ");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"yangxingmen",
  "southeast" : __DIR__"ningshoumen",
  "north" : __DIR__"huayuan",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
