//Cracked by Roath
// room: /mingjiao/shanlu1.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
只见此处道路崎岖，地势险峻，一处处关隘均有铁闸石门。再向北就
是明教的光明顶了。四周长草掩映，西风猎猎。一片苍凉的西域风光。
LONG );

        set("exits", ([
                "northup"   : __DIR__"shanlu",
                "southeast" : __DIR__"shanlu2",
                
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
