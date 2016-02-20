//Cracked by Roath
// Room: /d/xiangyang/miao.c

inherit ROOM;

void create()
{
	set("short", "马王庙");
	set("long", @LONG
马王庙重檐六角，一层施拱，檐角高翘。供奉的是楚王马殷，案台上香
火缭绕。许多城民们为了祈求襄阳能为他们常保平安，都在此进香以尽心。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : 4 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"beijie2",
  "southwest" : __DIR__"mihua",
]));

	setup();
	replace_program(ROOM);
}
