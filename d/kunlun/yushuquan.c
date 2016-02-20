//Cracked by Roath
// room: /mingjiao/yushuquan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "榆树泉");
        set("long", @LONG
大风自西面毫无阻挡地呼啸而来，加上南北都是高山，自然形成个大
风口，吹得人几乎站立不稳。谷底有条干枯水道，两旁生长着一些耐旱的
榆树。两侧的大山看上去象门神一样安然坐落。
LONG );

        set("exits", ([
                "northup" : __DIR__"suibei",
                "east" : __DIR__"xinkaiquan",
                "southup" : __DIR__"yinan",
                "west" : __DIR__"????",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 1);

        setup();
        replace_program(ROOM);
}