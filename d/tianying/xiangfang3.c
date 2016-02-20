//Cracked by Roath
// room: xiangfang3.c

inherit ROOM;

void create()
{
        set("short", "厢房");
        set("long", @LONG
这是教主休息的地方。一张床摆在东首，床上珠罗纱的帐子。西
首一张几上供着一盆兰花，架子上停着一只白鹦鹉。
LONG );

        set("exits", ([
                "east" : __DIR__"dating",
        ]));

        setup();
        replace_program(ROOM);
}
