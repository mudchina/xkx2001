//Cracked by Roath
// Room: /d/dali/shanlu4.c

inherit ROOM;

void create()
{
	set("short", "绿玉溪沿岸");
	set("long", @LONG
一条颇宽敞的土路沿着绿玉溪南岸横贯东西，一边是涓涓溪流碧波荡漾，另
一边是青山翠柳，郁郁葱葱的林木。东面有桥渡溪通向大理城南门，西去不远就
是五华楼了。
LONG);
	set("exits", ([
		"west" : __DIR__"shanlu3.c",
		"east" : __DIR__"shqiao.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
