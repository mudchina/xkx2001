//Cracked by Roath
// /d/huanghe/tctuwu.c

inherit ROOM;

void create()
{
        set("short", "土屋");
        set("long", @LONG
这是一间小土屋，看样子是一户渔民的房子。屋里简单地摆着些家具
，墙角零零落落放着一些积满灰尘的家具和渔网，看样子已经很久没人在
此居住了。
LONG );

        set("exits", ([
		"west" : __DIR__"tcxiaolu",
        ]));

    	set("cost", 1);

        setup();
        // replace_program(ROOM);
}
