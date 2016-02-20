//Cracked by Roath
// Room: /d/mingjiao/liangong.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
室间除一香炉和几个座垫，并无它物。四周因有竹林遮掩，没有一丝
杂音。偶而几声蝉鸣，更显幽静。功力深厚的弟子们常常整日在此勤练内
功。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"shijie51",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
