//Cracked by Roath
// room: damen.c

inherit ROOM;

void create()
{
        set("short", "天鹰教大门");
        set("long", @LONG
这里是天鹰教大门。一扇红漆大门敞开着，上面有一块大匾，写
着几个大字“天鹰教”。这天鹰教乃白眉鹰王殷天正一手所创，在江
南一带极具威名。几名教众站在两旁，守卫着大门。
LONG );

        set("exits", ([
                "north" : __DIR__"road1",
                "south" : __DIR__"unknown",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
