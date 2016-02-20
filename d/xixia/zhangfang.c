//Cracked by Roath
// Room: /d/xixia/zhangfang.c

inherit ROOM;

void create()
{
	set("short", "账房");
	set("long", @LONG
这是一品堂帐房，陈设倒很有点象当铺，不过柜台没有那么高。靠墙
是两排放帐簿的樟木柜，三个管账先生正劈里啪啦在打算盘忙着算账。边
上有几个管事手捧帐簿在候着，看来每天的进出的帐目不少。柜台边有个
衣着光鲜的干瘦的老头正有滋有味得坐在太师椅上吸着水烟。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/nuerhai" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dayuan",
]));

	setup();
	replace_program(ROOM);
}
