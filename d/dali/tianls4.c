//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "清都瑶台");
        set("long", @LONG
这里是全寺僧侣居集开法事的场所，四周都是大尊的汉玉佛雕。居中一个
法坛，四下里零零散散摆了总有四，五十个菩团。处身其中总有一种莫可言状
的凄冷之感。场所深宽各有十丈余。前后左右各六十步，方方正正的很。
LONG
        );
        set("exits", ([
		"northup" : __DIR__"tianls5.c",
        "southdown" : __DIR__"tianls3.c",		]));
set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

