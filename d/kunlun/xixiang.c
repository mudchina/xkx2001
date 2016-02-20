//Cracked by Roath
// Room: /d/mingjiao/xixiang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "西厢房");
	set("long", @LONG
置身所在竟似是一间大户人家小姐的闺房。靠窗边的是一张梳妆台，
台上红烛高烧，照耀得房中花团锦簇，堂皇富丽，颇不输于帝王之家。另
一边是张牙床，罗帐低垂，床前还放着一对女子的粉红秀鞋，显是有人睡
在床中。这闺房只有一道进门，窗户紧闭。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yuanzi65",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
