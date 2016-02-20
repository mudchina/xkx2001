//Cracked by Kafei
// Room: /d/dali/tianlong3.c

inherit ROOM;

void create()
{
	set("short", "僧舍");
	set("long", @LONG
这里的布置简简单单，几张竹桌、木椅、竹榻，地上散
散乱乱的放了几个蒲团。除此外再也没有别的什物。这里就是
天龙寺诸僧的练功所在。
LONG
	);
	set("cost", 4);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tianlong4.c",
  "north" : __DIR__"tianlong2.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
