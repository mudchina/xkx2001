//Cracked by Roath
// 古城
// maco

inherit ROOM;

void create()
{
	set("short", "古城郊野");
	set("long", @LONG
这里一片空旷，远方一座白玉山峰参天而起，峰前一排排的
都是房屋。千百所房屋断垣剩瓦，残破不堪，已没一座完整，但
建筑规模恢宏，气象开廓，想见当年是一座十分繁盛的城市。一
眼望去，高高矮矮的房子栉比鳞次，可是声息全无，甚至雀鸟啾
鸣之声亦丝毫不闻。
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanlu4",
		"west" : __DIR__"gucheng2",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

