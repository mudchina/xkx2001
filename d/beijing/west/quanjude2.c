//Cracked by Roath
// Room: /d/beijing/west/quanjude2.c

inherit ROOM;

void create()
{
	set("short", "雅座");
	set("long", @LONG
这里是全聚德烤鸭店二楼雅座，在这里的客人多是达官贵人或是
有钱有闲的八旗公子哥儿，气氛也和楼下一片喧哗大不一样。客人们
大多浅斟慢饮，店伙计也一脸笑容，服侍周到。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"quanjude",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
