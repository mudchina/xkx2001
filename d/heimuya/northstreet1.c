//Cracked by Roath
// Room: /d/heimuya/northstreet1.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "北长街");
        set("long", @LONG
这是平定州的北长街，青石路上人来人往，颇是热
闹。附近有各样的店铺。左边可以看见平定酒店的招子，
飘来阵阵酒香。右边有家当铺，往北走去可以通到平定
州的北门。
LONG
        );

        set("exits", ([
                "east" : __DIR__"dangpu",
                "west" : __DIR__"jiudian",
                "north" : __DIR__"northgate",
                "south" : __DIR__"center",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

