//Cracked by Roath
// Room: /d/xiangyang/migonglu.c

inherit ROOM;

void create()
{
	set("short", "米公路");
	set("long", @LONG
因为大书法家米芾的故居在这附近，这便把此处称为米公路。原本安宁
的小村因为蒙古大军时常南下，左近的村民大都南迁，良田如今已成荒野。东
去是南洋，北上可至陕西。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 0, "y" : 10 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"dufugang",
  "south" : __DIR__"hanshuin",
  "eastup" : __DIR__"shanlu2",
  "southwest" : __DIR__"migongci",
]));

	setup();
	replace_program(ROOM);
}
