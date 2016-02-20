//Cracked by Roath
// acep , mantian , mantian

inherit ROOM;

void create()
{
	set("short", "小厅");
	set("long", @LONG
一间雅致的小厅，桌上点着一对巨烛，东壁上四幅屏条，绘的是梅兰竹菊，
可是顺序却挂成了兰竹梅菊，西壁上的春夏秋冬，则挂成了冬夏春秋。看来此间
主人必是个武人。
LONG);
	set("objects", ([
		__DIR__"npc/ganbaobao": 1,
		__DIR__"npc/yahuan": 1,
		]));
	set("exits", ([
		"east" : __DIR__"wjg2.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
