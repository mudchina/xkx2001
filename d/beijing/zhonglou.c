//Cracked by Roath
// Room: /d/beijing/zhonglou.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"gulou",
	  "up" : __DIR__"zhonglou2",
	]));
    } else {
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"gulou",
	  "north" : __DIR__"andingmen",
	  "up" : __DIR__"zhonglou2",
	]));
    }
}

void create()
{
	set("short", "钟楼");
	set("long", @LONG
北京城钟楼高九丈有余，完全砖石结构，建于元朝至元年
间。钟楼上的大铜钟一到定更天，就会打两番一百零八下钟声，
据说还有一个“铸钟娘娘”的凄凉传说。
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
