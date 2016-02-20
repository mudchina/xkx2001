//Cracked by Roath
// Room: zoulang1.c 走廊
// qfy July 7, 1996.

inherit ROOM;

void reset();

void create()
{
    set("short", "走廊");
    set("long", @LONG
铺着木板的走廊贯穿东西两方面，南边是另一间偏厅。四周非常宁静，
可闻吱吱鸟语和唧唧虫鸣，一片祥和。
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang2",
	"west" : __DIR__"zoulang4",
	"south" : __DIR__"pianting2",
	"north" : __DIR__"houyuan",
    ]));

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
    replace_program(ROOM);
}