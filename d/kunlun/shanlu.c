//Cracked by Roath
// room: /mingjiao/shanlu.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
只见此处道路崎岖，地势险峻，一处处关隘均有铁闸石门。北面即是
光明顶的山口。左右都有山间的岔道，不知通向何方。
LONG );

        set("exits", ([
                "northup"   : __DIR__"shankou",
                "southdown" : __DIR__"shanlu1",
                "westup"    : __DIR__"shanlu3",
                "eastup"    : __DIR__"shanlu4",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
