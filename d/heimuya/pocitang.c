//Cracked by Roath
// Room: /d/heimuya/pocitang.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "破祠堂");
        set("long", @LONG
这是一个很破旧的祠堂，到处都布满了蜘蛛网，案
台上也积了一层极厚的灰尘，看来这祠堂已经荒废很久
了。祠堂里面的屋顶破了一个大洞，屋瓦摇摇欲坠。南
面是平定州的东长街。
LONG
        );

        set("exits", ([
                "south" : __DIR__"eaststreet2",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

