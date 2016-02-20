//Cracked by Roath
// Room: /d/dali/wuhua2.c

inherit ROOM;

void create()
{
	set("short", "楼梯");
	set("long", @LONG
这就是通往二楼“迎宾斋”的楼梯，楼梯高有五十余级，上面铺了鲜红的毛
毡，楼梯两侧站了一些素衣卫士，楼上则是贵宾休息的地方。
LONG);
	set("objects", ([
		"kungfu/class/dali/gaoshengtai" : 1,
		__DIR__"npc/weishi4.c" : 3,
        ]));
	set("exits", ([
		"east" : __DIR__"wuhua1.c",
		"up" : __DIR__"wuhua3.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
}
void reset()//make this room no refresh
{
        ::reset();
        set("no_clean_up", 1);
}
