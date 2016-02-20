//Cracked by Roath
// room: changlang2.c

inherit ROOM;

void create()
{
        set("short", "长廊");
        set("long", @LONG
你正走在一条长廊之上, 长廊蜿蜒曲折, 两旁是如画景象. 不时
看见教众忙忙碌碌地走过。长廊北边通往天鹰教三堂，南边是五坛。
LONG );

        set("exits", ([
                "north" : __DIR__"zoulang7",
                "south" : __DIR__"zoulang3",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
