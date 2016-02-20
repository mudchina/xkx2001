//Cracked by Roath
// Room: /d/heimuya/mihang.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "米行");
        set("long", @LONG
店里的空间不大，地上摆着很多米缸，装着各种各
样的米。老板正坐在那里低头打着瞌睡，看来买米的人
不是很多。南面便是平定州热闹的东长街了。
LONG
        );

        set("exits", ([
                "south" : __DIR__"eaststreet1",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

