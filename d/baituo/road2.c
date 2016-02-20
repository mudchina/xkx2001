//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
一条满地沙石的小径，北边通往山庄的前院，西南边有一间小屋
，窗口飘来阵阵酒菜香气。
LONG
	);
	set("exits", ([ 
	    "southwest" : __DIR__"kitchen",
	    "north" : "/d/xingxiu/btyard",
	]));
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
