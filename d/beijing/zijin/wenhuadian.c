//Cracked by Roath
// Room: /d/beijing/zijincheng/wenhuadian.c

inherit ROOM;

void create()
{
	set("short", "文华殿");
	set("long", @LONG
是皇太子活动的东宫，这里常举行一些经筵，即按一定日期,皇
帝和大臣们一起讲儒家经典,然后赐茶,赐宴.对面一片较矮的房子是
内阁。


这是御前侍卫头领门聚议的地方，但是经常从里面传出喝五吆六
的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhujingdian",
  "south" : __DIR__"wenhuamen",
  "west" : __DIR__"neige",
  "east" : __DIR__"chuanxindian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
