//Cracked by Roath
// room: /mingjiao/jiuquan.c

inherit ROOM;

void create()
{
        set("short", "酒泉山");
        set("long", @LONG
此山虽十分偏僻，却甚是有名。只见山色青翠，一道清泉从石缝中涌
出，终年不枯。那泉水清冽甘美，为酿制美酒的上上之选，故名酒泉。本
地山民甚至不辞辛苦，将泉水挑到山外装桶出售，据说价格不菲。
LONG );
        set("exits", ([
                "southdown" : __DIR__"luobuyi",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("resource/water", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}