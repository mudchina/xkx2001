//Cracked by Roath
// /xiakedao/Dong3.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
	set("short", "山洞");
	set("long", @LONG
侠客岛常年派遣弟子到中原各地打探各门派内情，多年的积累以
及许多不为人知的武林珍闻便记载在这里的书(books)中。只见书架书
桌俱全，桌上油灯长明，真是个读书的好地方。
LONG );

	set("exits", ([
		"south" : __DIR__"",
	]));

	set("item_desc",([
	    "books" : 	"书面上都写着一个武林门派的名字。\n",
	]));
	
        setup();
}
void init()
{
        ::init();

	add_action("do_du", "du");
}
int do_du(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "你想学什麽?\n");
	if ( arg != "book" )
		return notify_fail( "你要读什麽?\n");
	write("翻开这本书的第一页，上面写着\n");
	return 1;
}
