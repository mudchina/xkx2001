//Cracked by Roath
// Room: /d/beijing/zijincheng/qinandian.c

inherit ROOM;

void create()
{
	set("short", "钦安殿");
	set("long", @LONG
殿内供玄武大帝,是宫中举行道教活动的重要常所,每逢重大祭
礼活动,皇帝在此殿拈香行礼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"yuhuayuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
