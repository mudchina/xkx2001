//Cracked by Roath
// room: bingqifang.c

inherit ROOM;

void create()
{
        set("short", "兵器房");
        set("long", @LONG
这里是天鹰教的兵器房，四周放这几个兵器架，上面是天鹰教各
弟子平时练武用的兵器。
LONG );

        set("exits", ([
                "north" : __DIR__"lianwuchang",
        ]));

        setup();
        replace_program(ROOM);
}
