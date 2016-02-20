//Cracked by Roath
//GU MU FROM SANTA
//DAMEN.C

inherit ROOM;

void create()
{
	set("short", "活死人墓");
	set("long", @LONG
前面是一座气派森严的大坟墓。令人惊奇的是左侧方竟然
有炊烟缭绕，哗！莫非有人住在里面？ 
LONG
	);
	 set("exits", ([
		"north" : __DIR__"huating",
		"south" : __DIR__"qianyuan",
		"east" : __DIR__"shufang",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}


