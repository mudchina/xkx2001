//Cracked by Roath
// xiakedao/shanding.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "山顶");
        set("long", @LONG
从这里俯瞰，整个海岛一览无遗。沙滩上隐约可见几个小黑点，
几只信天翁在头顶优雅地滑翔。四面望去，只见海天一色，长空如洗，
令人心怀大畅。山顶上长了一棵大树(tree)，高耸入云。
LONG );

        set("exits", ([
		"eastdown" : __DIR__"shanlu4",
		"westdown"  : __DIR__"shanlu3",
		"southdown" :  __DIR__"yelin",
        ]));
        set("item_desc",([
			  "tree" : "大树上长了一些野果，不知怎样才能摘下来。\n",
        ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("objects", ([ 
	    __DIR__ + "npc/wudang" : 1,
	    __DIR__ + "npc/master1" : 1,
      ]));

	setup();

}

void init()
{
  ::init();

        add_action("do_pa", "pa");
	add_action("do_pa", "climb");
}

int do_pa(string arg)
{
        object me = this_player();

        if ( !arg )
                return notify_fail("你要往哪儿爬？\n");
        if (( arg != "tree" )&&(arg!="up"))
                return notify_fail("什麽？\n");
        message_vision("$N笨手笨脚地往大树上爬了上去。\n",me);
        me->move(__DIR__"tree1");  
        message_vision("$N从下面爬了上来。\n",me);
        return 1;
}

