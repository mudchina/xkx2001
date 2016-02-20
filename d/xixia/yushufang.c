//Cracked by Roath
// Room: /d/xixia/yushufang.c

inherit ROOM;

void create()
{
	set("short", "御书房");
	set("long", @LONG
这里是皇上的御书房，古色古香，居中一张特别大的书桌，东墙是
排椅子，南窗前是一排博物架，摆了不少珍稀古玩，北墙挂幅着『猛虎
下山』图。皇上平时就在这里批阅群臣的奏章和接见进谏的臣子。西夏
虽然是偏域番国，但皇上却是雄才武略颇有大志，时用汉人高贤为官。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"piandian2",
  "east" : __DIR__"xidian",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
