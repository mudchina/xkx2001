//Cracked by Roath
inherit ROOM;

void create()
{
        set("short", "钓鱼台岛");
        set("long", @LONG
这里就是钓鱼（台）岛。岛很小，四周都是大海。岛上有一座
灯塔(dengta)，塔下还画着太阳旗。
LONG
        );
        
	set("exits", ([
		"northwest" : __DIR__"sea3",
	]));

	set("item_desc", ([
		"dengta" : "一座歪歪斜斜的灯塔，可以炸(zha)掉。\n"
	]));

        set("objects", ([
          	__DIR__"npc/langren" : 5,
	]));

	set("cost", 4);
        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_dagu", "zha");
}

int do_dagu(string arg)
{
	object me = this_player();

	if ( !arg ) return notify_fail("你要炸什么？\n");
	if (arg != "dengta") 
		return notify_fail("这个不能炸。\n");
	if (objectp(present("lang ren",environment(me))))
                return notify_fail("日本浪人拔刀挡住了你\n");
        CHANNEL_D->do_channel(me,"rumor",
           sprintf("%s把炸药堆在灯塔下，只听「轰」的一声巨响，钓岛的日本灯塔飞上了天。", 
           me->name()));
        set("long", @LONG
这里就是钓鱼（台）岛。岛很小，四周都是大海。岛上的灯塔
被炸烂了。
LONG
        );


	return 1;
}
