//Cracked by Roath
// Room: /d/beijing/east/dongbianmen.c

inherit ROOM;

void create()
{
	set("short", "东便门");
	set("long", @LONG
这是北京城外城女墙朝东向的偏门，此处城墙比起外城其
他处的城墙要低矮一些，守军也较少，盘查也不如其他外城门
那么严厉，走此门的大多是运水、倒粪操持贱业之人。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"dongbianmenlou",
  "southwest" : __DIR__"guangqudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
