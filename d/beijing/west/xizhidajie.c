//Cracked by Roath
// Room: /d/beijing/west/xizhidajie.c

inherit ROOM;

void create()
{
	set("short", "西直门大街");
	set("long", @LONG
这是一条十分宽阔的大街。人来人往，相当热闹。有几个小贩
正在沿街叫卖着什麽，偶有几个行人会停下来驻足问价。南面有条
小胡同，西面则是西直门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"xizhidajie2",
  "west" : __DIR__"xizhimen",
  "south" : __DIR__"baozhu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
