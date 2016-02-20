//Cracked by Roath
// pine_road.c 松林大道
// by Marz@XKX 11/11/96

inherit ROOM;

void create()
{
	set("short", "松林大道");
	set("long", @LONG
你走在山脚松林中的一条道路上，不时有道士打扮的人扛着红松树木从身
旁经过。西面是上山的路，两边是茂密的松树林，林中伐木铿锵，间或有大树
倒塌声，「喀哧」作响。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"eastdown" : __DIR__"wdroad8",
		"west" : __DIR__"shanmen",
		"north" : __DIR__"pine_road1",
		"south" : __DIR__"pine_road2",
	]));

	set("cost", 2);
	setup();
	replace_program(ROOM);
}

