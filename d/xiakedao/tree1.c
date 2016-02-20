//Cracked by Roath
// xiakedao/tree1.c
// Ssy 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "树上");
        set("long", @LONG
从树顶往下俯瞰，整个海岛一览无遗。沙滩上隐约可见几个小黑
点，几只信天翁在头顶优雅地滑翔。四面望去，只见海天一色，长空
如洗，令人心怀大畅。
    你周围似乎长了一些野果(guo)。
LONG );
        set("item_desc",([
			  "guo" : "红艳艳的野果，不知能不能摘下来。\n",
        ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("guocount",5);
	setup();
}

void init()
{
  ::init();

        add_action("do_zhai", "zhai");
        add_action("do_pa", "pa");
        add_action("do_pa", "climb");

}

int do_zhai(string arg)
{
        object ob;
        object me = this_player();

	if (present("ye guo", me))
	  {
	    message("vision","有了还想要？！\n",me);
	    return 1;
	  }
	
	message_vision("$N从树上摘下了一枚野果。\n",me);
	if (query("guocount")>0)
	  {
	    ob=new(__DIR__"obj/guo1");
	    ob->move(me);
	    add("guocount", -1);
	  }
	else
	  {
            ob=new(__DIR__"obj/guo2");
            ob->move(me);
	  }
       return 1;
}

int do_pa(string arg)
{
        object me = this_player();

        if ( !arg )
                return notify_fail("你要往哪儿爬？\n");
        if ( arg != "down" )
                return notify_fail("什麽？\n");
        message_vision("$N笨手笨脚地爬了下去。\n",me);
        me->move(__DIR__"shanding");  
        message_vision("$N从树上爬了下来。\n",me);
        return 1;
}

