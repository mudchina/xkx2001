//Cracked by Roath
//Jay 10/18/96

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
川西多是崇山峻岭，交通不便。一条山路蜿蜒在山间，连接着
藏边和中原。
LONG
        );
        set("exits", ([
		"eastdown" : __DIR__"emroad1",
                "westup" : __DIR__"chuanxi2",
        ]));

	set("outdoors", "emei");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

