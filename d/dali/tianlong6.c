//Cracked by Kafei
// Room: /d/dali/tianlong6.c

inherit ROOM;

void create()
{
	set("short", "小亭");
	set("long", @LONG
这是一个小小的八角竹亭，亭中只有一张石桌、几张石凳。
亭子中央站了个中年僧人，虽然只是背影, 你仍感到一股无形
的压力。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tianlong2.c",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
