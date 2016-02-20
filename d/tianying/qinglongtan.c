//Cracked by Roath
// room: qinglongtan.c

inherit ROOM;

void create()
{
        set("short", "青龙坛");
        set("long", @LONG
这里是天鹰教五坛之一的青龙坛。大厅正面高悬一块牌匾，上书
两个烫金大字“青龙”，由教主亲提。厅里摆着一面屏风，屏风上画
着一副青龙图，甚是威风。
LONG );

        set("exits", ([
                "south" : __DIR__"zoulang2",
        ]));

        setup();
        replace_program(ROOM);
}
