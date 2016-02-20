//Cracked by Roath
// d/emei/tombpath.c 小径
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "小径");
	set("long", @LONG
这是一条蜿蜒的山间小径，一边通往峨眉山后山，另一边不知通到哪里。
这一路人迹罕见，只有些不知名的小虫在吱吱叽叽唱着。
LONG
	);

        set("exits", ([
                "west" : __DIR__"tomb",
		"southwest" : __DIR__"grassland",
		"northdown" : __DIR__"tombpath2",
        ]));

	set("cost", 4);
	setup();
        replace_program(ROOM);
}

