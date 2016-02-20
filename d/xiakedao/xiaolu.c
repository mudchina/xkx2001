//Cracked by Roath
// xiakedao/xiaolu.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "小路");
        set("long", @LONG
这是一条普通的石子路，路面碎石随意地组合着，显出淡淡的图
案。路旁长着些矮矮的小树(bush)，有时小树中响起一阵哗啦啦的声
音，大概是山间的小兽。一阵海风吹过，树丛里好象有什麽东西在闪
闪发光。
LONG );

      set("exits", ([
      	"south" : __DIR__"shatan",
		"north" : __DIR__"ybting",
      ]));

	set("item_desc",([
	    "bush" : 
"这是些不知名的小树。因为长在海边，所以都很矮。如果你想要看树
丛下有什麽，你需要拨开树丛(push bush)。\n",
	]));

	set("outdoors", "xiakedao" );
	set("cost", 0);
	set("objects", ([ 
          "/d/city/obj/branch1" : 1,
      ]));
	setup();
}
void init()
{
        ::init();

	add_action("do_push", "push");
}

int do_push(string arg)
{	object jian, me = this_player();

	if ( !arg )
		return notify_fail( "你要推什么？\n");
	if ( arg != "bush" )
		return notify_fail( "要你 push bush，你 push " + arg + " 干嘛？\n");
	
	if ((present("duanjian",environment(me)))||
	    (present("duanjian",me)))
	{	message_vision("$N在树丛中翻来复去找了半天，却什麽也没有找到。\n", me);
		return 1;	
	}
	else
	{	message_vision("$N在树丛中发现了一把短剑。\n", me);
		jian = new("/clone/weapon/duanjian.c");
		jian->set("value", 0);
		jian->move(environment(me));
		return 1;
	}
}
