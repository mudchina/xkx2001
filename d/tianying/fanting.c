//Cracked by Roath
// room: fanting.c

inherit ROOM;

void create()
{
        set("short", "饭厅");
        set("long", @LONG
这里是天鹰教的饭厅，一排排的桌子凳子整齐的摆在厅里。香气
一阵阵的传来，使你不禁想坐下吃点什么。几名教众喝着酒，大声吆
喝着，像是在猜拳。
LONG );

        set("exits", ([
                "south" : __DIR__"lianwuchang",
        ]));

        setup();
        replace_program(ROOM);
}
