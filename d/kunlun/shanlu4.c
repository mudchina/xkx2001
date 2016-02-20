//Cracked by Roath
// room: /mingjiao/shanlu4.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
只见此处道路崎岖，地势险峻，一处处关隘均有铁闸石门。东北边云
雾缭绕，不知是什么去处。
LONG );

        set("exits", ([
                "northeast"   : __DIR__"shanya",
                "westdown"    : __DIR__"shanlu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);


        setup();
        replace_program(ROOM);
}
