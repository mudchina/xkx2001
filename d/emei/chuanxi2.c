//Cracked by Roath
//Jay 10/18/96

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条山路蜿蜒在山间。向西望去，可以见到大雪山的银色的雪
顶在熠熠生辉。
LONG
        );
        set("exits", ([
		"eastdown" : __DIR__"chuanxi1",
                "westup" : "/d/xueshan/shanlu7",
        ]));

	set("outdoors", "emei");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

