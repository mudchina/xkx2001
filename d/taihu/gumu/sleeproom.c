//Cracked by Roath
//GU MU FROM SANTA
//sleeproom.C

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
你但见房中空空洞洞，一块本长条青石作床(shichuang)，床上铺
了张草席，一幅白布当作薄被。室东的一根铁钉上系住了一根绳索，
绳索横过室中，另一端系在西壁的一口钉上，绳索（shengsuo)离地
约莫一人来高。
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



