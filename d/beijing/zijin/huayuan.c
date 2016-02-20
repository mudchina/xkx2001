//Cracked by Roath
// Room: /d/beijing/zijincheng/huayuan.c

inherit ROOM;

void create()
{
	set("short", "宁寿宫花园");
	set("long", @LONG
这里是乾隆皇帝准备退位后，作为御花园而为自己建的。 
园内布满亭、台、楼、阁，苍松翠柏，曲径通幽。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gzxd5",
  "east" : __DIR__"leshoutang",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
