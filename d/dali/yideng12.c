//Cracked by Roath
// yideng quest room 12

inherit ROOM;
void create()
{
        set("short", "庙后石室");
        set("long", @LONG
竹林深处的石室清雅幽静，窗外满眼是幽幽碧竹，正是禅宗参禅之妙所。室
中小几上点着一炉檀香，几旁一位老僧端坐在蒲团上。
LONG);
	set("objects", ([
		"/kungfu/class/dali/yideng.c" : 1,
		]) );
	set("exits", ([
		"south" : __DIR__"yideng11",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}
