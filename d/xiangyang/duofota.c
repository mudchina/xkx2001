//Cracked by Roath
// Room: /d/xiangyang/duofota.c

inherit ROOM;

void create()
{
	set("short", "多宝佛塔");
	set("long", @LONG
塔座顶部是一平台，上建五座小塔，中央主塔形似喇叭，名喇嘛塔，高十七
米，下层为八方须弥座，上刻覆莲瓣四层，顶为铜制宝珠、宝盖，宝盖下沿悬八
枚小铜铃，风吹铃响，悦耳动听。主塔四周围四座六角攒尖、重檐三层的亭式小
宝塔，塔壁均有佛龛和佛像，共四十八佛，塔故名。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -15, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"guangde",
]));

	setup();
	replace_program(ROOM);
}
