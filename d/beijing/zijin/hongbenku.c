//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "红本库");
	set("long",  @LONG
这是给御前侍卫休息使用的。靠墙是几张大床，当侍卫们在宫中
连续值班时，就来这里休息一下。
LONG
	);

	set("exits", ([
        "north" : __DIR__"wenhuamen",
        "east"  : __DIR__"shiluku",
	]));

	setup();
	replace_program(ROOM);
}
