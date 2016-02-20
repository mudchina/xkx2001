//Cracked by Roath
// room: /d/xingxiu/xlroom.c
// Jay 3/18/96
// Ryu 5/10/97

inherit ROOM;

void create()
{
        set("short", "блжч");
        set("objects", ([
                __DIR__"obj/xianglu-dao" : 1,
        ]));
        set("resource/grass", 1);
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 3);
        setup();
        replace_program(ROOM);
}
