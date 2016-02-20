//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是白驼山庄的大厅，器具陈设颇为考究，数名白衣女子手持红
纱宫灯站在两旁，厅中一队白衣舞女奏乐起舞，姿态妖娆，以娱视听。
南北各有一道拱门通往走廊，西边摆着一面屏风，上面绘着一祗雪白的
骆驼，後面的回廊可至灵蛇阁。
LONG
	);
	set("exits", ([ 
	    "east" : "d/xingxiu/btyard",
	    "west" : __DIR__"changlang1",
	    "north" : __DIR__"changlang3",
	    "south" : __DIR__"changlang4",
	]));
	set("objects", ([
	    __DIR__"npc/wuji" : 3,
	 ]) );
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
