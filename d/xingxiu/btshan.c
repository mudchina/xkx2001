//Cracked by Roath
// room: /d/xingxiu/btroad
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里是胡杨林西面的一条小路。西面通往白驼山。
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"huyang4",
            "west" : __DIR__"btgate",
        ]));
        set("outdoors","xingxiuhai");
        replace_program(ROOM);

	set("cost", 1);
        setup();
}

