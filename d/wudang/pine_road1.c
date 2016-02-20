//Cracked by Roath
// pine_road1.c 松林小道
// by Marz@XKX 11/11/96

inherit ROOM;

void create()
{
	set("short", "松林小路");
	set("long", @LONG
	这是山脚松林中的小路，两边长满参天的红松树，只能看见一线天空。
路旁有道士在奋力砍(chop)树。北面通向密林深处，南边可回大道。
LONG
	);
	
	set("objects", ([
		CLASS_D("wudang") + "/famu" : 1,
		__DIR__"obj/pine" : 2]));
	                        	
	
	set("exits", ([
		"north" : __DIR__"pine_forest0",
		"south" : __DIR__"pine_road",
	]));
	
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

