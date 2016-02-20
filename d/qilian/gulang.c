//Cracked by Roath
// Room: /d/qilian/gulang.c

inherit ROOM;

void create()
{
	set("short", "古浪");
	set("long", @LONG
古浪城建于西周，本名鬼武，后整修于汉，更名古浪。古浪是西北地区的
毛皮集散地，当初的紫羊羔皮袄，一出于张家口，另一出处就是古浪了，过了
古浪再往西四十里，跨过纪水河即到兰州。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/taishan/npc/dao-ke" : 1,
]));
	set("cost", 1);
	set("outdoors", "qilian-shan");
	set("exits", ([ /* sizeof() == 5 */
  "northeast" : "/d/xixia/dacaigou",
  "west" : __DIR__"xiaojiaqiao",
  "north" : __DIR__"sishu",
  "south" : __DIR__"yongdeng",
  "east" : __DIR__"fur-shop",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
