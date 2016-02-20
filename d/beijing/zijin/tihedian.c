//Cracked by Roath
// Room: /d/beijing/zijincheng/tihedian.c

inherit ROOM;

void create()
{
	set("short", "体和殿");
	set("long", @LONG
   慈禧太后住储秀宫时,在此用膳,"寿膳房"每天要花费五十两白银.每餐有
主食十九种,菜肴二.三十个,还有各式菜点.光绪十三年(1887)慈禧太后在此
为光绪皇帝主持选皇后和妃子的仪式.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yikungong",
  "north" : __DIR__"chuxiugong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
