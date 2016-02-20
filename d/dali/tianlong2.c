//Cracked by Kafei
// Room: /d/dali/tianlong2.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
空空荡荡的庭院里只有几只小鸟“喳喳”的叫着，南面隐隐可
以看到几间僧舍在松林间隐现。
LONG
	);
	set("cost", 4);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tianlong6.c",
  "south" : __DIR__"tianlong3.c",
  "north" : __DIR__"tianls7.c",]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

