//Cracked by Roath
// Room: /d/mingjiao/shijie2.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是一条长长的青石阶，两旁站着几个明教的护卫，每人的左袖上都
绣有一血红的火焰。在石阶的尽头处，耸立着两个高十仗的箭楼。如有外
人闯进这里，箭 楼上的弓箭手将会发动攻击。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yongdao2",
  "southwest" : __DIR__"shanmentongdao",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
