//Cracked by Roath
// room: shenshetan.c

inherit ROOM;

void create()
{
        set("short", "神蛇坛");
        set("long", @LONG
这里是天鹰教五坛之一的神蛇坛。大厅正面高悬一块牌匾，上书
两个烫金大字“神蛇”，由教主亲提。厅里摆着一面屏风，屏风上画
着一副蟒蛇图，甚是威风。
LONG );

        set("exits", ([
                "south" : __DIR__"zoulang5",
        ]));

        setup();
        replace_program(ROOM);
}
