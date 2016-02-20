//Cracked by Roath
// room: /d/xingxiu/btshan
// Jay 3/27/96

inherit ROOM;

void create()
{
        set("short", "白驼山庄");
        set("long", @LONG
这里是「西毒」欧阳锋练功的地方，屋内什么摆设也没有。
LONG
        );
        set("exits", ([ 
            "eastdown" : __DIR__"btshan",
        ]));
        set("objects", ([ 
            __DIR__"npc/feng" : 1,
            __DIR__"npc/snake" : 5,
         ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 2);
        setup();
        replace_program(ROOM);
}
