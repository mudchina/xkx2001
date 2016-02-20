//Cracked by Roath
// Room: 泉州土地庙
// qfy August 17, 1996.

inherit ROOM;

void create()
{
	set("short", "土地庙");
	set("long", @LONG
这是一间十分破旧的土地庙，也不知荒废了多久，梁上地下布满了灰尘。
土地神像後面的墙上有个洞口，老鼠爬进爬出，恶心极了。
LONG
	);

	set("exits", ([
		"west" : __DIR__"lyqiao",
	]));

	set("objects", ([
		__DIR__"npc/laoshu" : 1,
		__DIR__"npc/dipi" : 1,
		__DIR__"npc/punk" : 1,
	]));

	set("cost", 1);
	setup();
	//replace_program(ROOM);
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me = this_player();
        mapping myfam;

	myfam = (mapping)me->query("family");

        if( !arg || arg=="" ) return 0;

        if( arg=="hole" || arg=="dong" )
        {
           if( myfam["family_name"] == "丐帮" ) {
                message("vision", me->name()+"运起丐帮缩骨功，一弯腰往洞里钻了进去。\n", environment(me), ({me}) );
		me->move("/d/gaibang/underqz");
		message("vision", me->name() + "从洞口钻了进来。\n", environment(me), ({me}) );
		return 1;
                }
           else return notify_fail("这么小的洞，你钻得进去吗？\n");
	}

}


