//Cracked by Roath
// Room: /d/beijing/west/xizhidajie2.c

inherit ROOM;

void create()
{
	set("short", "西直门大街");
	set("long", @LONG
这是一条十分宽阔的大街。人来人往，相当热闹。有几个小贩
正在沿街叫卖着什麽，偶有几个行人会停下来驻足问价。从这儿向
东望去，可看到钟楼和鼓楼的尖顶。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"guloudajie2",
  "east" : __DIR__"guloudajie2",
  "southwest" : __DIR__"xizhidajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
