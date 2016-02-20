//Cracked by Roath
// huayuan1.c

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这是一个园子，庭院清幽，异种花卉甚是不少。百花争放，山石古拙，
杨柳垂清，苍松翠竹，景致煞是宜人。清澈的溪流旁耸立着一座小亭子，
潺潺溪水向西南流去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "south" : __DIR__"houyuan",
	    "north" : __DIR__"buwei1",
	    "west" : __DIR__"xilang",
	    "east" : __DIR__"donglang",
	    "southwest" : __DIR__"huayuan2",  
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}