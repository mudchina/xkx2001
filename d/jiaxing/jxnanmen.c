//Cracked by Roath
// Room: /d/jiaxing/jxnanmen.c
// modified by aln  2 / 98

inherit ROOM;

void create()
{
	set("short", "嘉兴南门");
	set("long", @LONG
这里是嘉兴的南门。周围长着茂密的竹林。东面是座庙宇。
向南可入福建。往东南走就是杭州了。
LONG
	);

	set("cost", 1);
	set("outdoors", "quanzhou");
	set("exits", ([ /* sizeof() == 4 */
                "east" : __DIR__"tieqiang",
                "southeast" : __DIR__"chating",
                "southwest" : __DIR__"field",
                "north" : __DIR__"jiaxing",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
