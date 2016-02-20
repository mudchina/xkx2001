//Cracked by Roath
// Room: /d/beijing/west/zhonglou.c

inherit ROOM;

void create()
{
	set("short", "钟楼");
	set("long", @LONG
北京城钟楼高九丈有余，完全砖石结构，建于元朝至元年
间。钟楼上的大铜钟一到定更天，就会打两番一百零八下钟声，
据说还有一个“铸钟娘娘”的凄凉传说。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"gulou",
  "west" : __DIR__"guloudajie",
  "east" : "/d/beijing/east/zhongtianlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
