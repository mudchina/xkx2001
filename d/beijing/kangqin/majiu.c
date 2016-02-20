//Cracked by Roath
// Room: /d/beijing/kangqin/majiu.c

inherit ROOM;

void create()
{
	set("short", "王府马厩");
	set("long", @LONG
这里是王府的马厩。康亲王酷爱宝马，花了很多精力
和金钱收罗了不少好马。地上铺了一层干草，靠墙的饲料
槽总是满的。离饲料槽不远处是个池子，可以洗马。旁边
有块沙地，可供马夫遛马。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"neijiu",
  "north" : __DIR__"zhoulang9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
