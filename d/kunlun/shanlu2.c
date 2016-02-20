//Cracked by Roath
// room: /mingjiao/shanlu2.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
只见此处道路崎岖，地势险峻，一处处关隘均有铁闸石门。西北方就
是明教的光明顶了。明教在此虽无甚多埋伏，但来攻者却也不易迅速奄至。
加之明教名头甚响，来袭敌人心存忌惮，未敢贸然深入。
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"shanlu1",
                "southeast" : __DIR__"badake",
                
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
