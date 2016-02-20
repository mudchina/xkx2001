//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "戚家大院");
        set("long", @LONG
这是一户农家小院，院中桑树把院子罩得很阴凉。院边一条
长凳上坐着个老农，正在指点一个姑娘习剑。
LONG
        );
        set("exits", ([
		"east" : __DIR__"cunkou",
		"west" : __DIR__"bkyard",
	]));

	set("objects", ([
		__DIR__"npc/changfa" : 1,
		__DIR__"npc/qifang" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
