//Cracked by Roath
// d/emei/tombpath2.c 小径
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "小径");
	set("long", @LONG
这是一条蜿蜒的山间小径，草木丛生，人迹罕见，只有些不知名的小虫
在吱吱叽叽唱着。南边通往峨眉山后山，北边就是九十九道拐。这里山石嶙
峋，走着走着，往回看，已经见不到来路。
LONG
	);

        set("exits", ([
		"northdown" : __DIR__"dao99",
		"southup" : __DIR__"tombpath",
        ]));

	set("cost", 6);
	setup();
        replace_program(ROOM);
}

