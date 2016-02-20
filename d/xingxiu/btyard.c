//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这是白驼山庄的前院。院墙白砖黑瓦，墙上刻着连绵不绝的蛇形
曲纹，偌大的山庄透着一股诡谲的感觉。西边是白驼山庄的大厅，南
北两边各有一条小径绕往重重屋宇之後，东边下山去就是山门。院中
有一块白玉石雕成的的石碑。
LONG
	);
	set("exits", ([ 
	    "eastdown" : "/d/xingxiu/btgate",
	    "west" : "/d/baituo/dating",
	    "north" : "/d/baituo/road1",
	    "south" : "/d/baituo/road2",
	]));
	set("objects", ([
	    "/d/baituo/npc/binu" : 1,
	    "/d/baituo/npc/jiading" : 1,
	 ]) );
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
	"/clone/board/baituo_b"->foo();
}
