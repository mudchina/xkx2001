//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一条白砖砌墙的长廊，北边的拱门通往大厅，西边一道木门，後
头是白驼山庄众武师所住的房间。西南边另有一扇小门，那是家丁、
婢女等下人们休息的所在。东南边的走廊飘来阵阵香味，是白驼山庄
的厨房。
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"dating",
	    "west" : __DIR__"bedroom2",
	    "southwest" : __DIR__"bedroom3",
	    "southeast" : __DIR__"kitchen",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
