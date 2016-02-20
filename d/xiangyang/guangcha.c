//Cracked by Roath
// Room: /d/xiangyang/guangchang.c

inherit ROOM;

void create()
{
	set("short", "中心广场");
	set("long", @LONG
襄阳城北接宛洛，南连荆宜，东临武汉，西屏川陕，历来便为各朝军事重镇。
城区依山傍水，水陆交通发达。入川陕、下江南、朝京洛多在这换舟船，易车
马，故有“南船北马”之说，“七省通衢”之说。城中央宽阔的广场上南来北往
的旅客商人马不停蹄，络绎不绝。然而四周显得却不是很繁华，东南西北望去皆
是一片森严气象，不时还可以见到巡逻的官兵走过，人群避路而行。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beijie1",
  "south" : __DIR__"nanjie1",
  "east" : __DIR__"dongjie1",
  "west" : __DIR__"xijie1",
]));
	set("no_sleep_room", 1);

	setup();
	replace_program(ROOM);
}
