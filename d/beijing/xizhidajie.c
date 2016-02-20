//Cracked by Roath
// Room: /d/beijing/xizhidajie.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"fuchengdajie",
	  "east" : __DIR__"guloudajie_w",
	]));
    } else {
	set("exits", ([ /* sizeof() == 3 */
	  "northwest" : __DIR__"deshengmen",
	  "west" : __DIR__"xizhimen",
	  "south" : __DIR__"fuchengdajie",
	  "east" : __DIR__"guloudajie_w",
	]));
    }
}

void create()
{
	set("short", "西直门大街");
	set("long", @LONG
这是一条十分宽阔的大街。人来人往，相当热闹。有几个小贩
正在沿街叫卖着什麽，偶有几个行人会停下来驻足问价。南面是阜
成门大街，西面则是西直门。
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
