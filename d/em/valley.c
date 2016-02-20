//Cracked by Roath
// d/emei/valley.c 山谷
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "山谷");
	set("long", @LONG
眼前豁然开朗，你来到一个小山谷。谷中花草丛生，鸟语间关。一条小径
曲曲折折地通向草木幽深之处。
LONG
	);
        set("outdoors", "emei" );

        set("exits", ([
                "east" : __DIR__"valleypath",
        ]));

	set("cost", 3);
	setup();
        replace_program(ROOM);
}

