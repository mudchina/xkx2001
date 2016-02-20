//Cracked by Roath
// xiakedao/shatan.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "小路");
        set("long", @LONG
这是一条用青石铺成的小路。路两旁长着些矮矮的小树(bush)，
一阵海风吹过，树丛里好象有什麽东西在闪闪发光。
LONG );

      set("exits", ([
      	"south" : __DIR__"shatan",
		"north" : __DIR__"guangchang",
      ]));

	set("item_desc",([
	    "bush" : "这是些不知名的小树。因为长在海边，所以都很矮。如果你想要看树\n"
			 "丛下有什麽，你需要拨开树丛(push bush)。\n",
	]));

	set("outdoors", "xiakedao");
	set("cost", 0);

	setup();
}

void init()
{
        ::init();

	add_action("do_push", "push");
}

int do_push(string arg)
{
	object jian;

	if ( !arg )
		return notify_fail( "你要推什么？\n");
	if ( arg != "bush" )
		return notify_fail( "要你 push bush，你 push " + arg + " 干嘛？\n");
		
	message_vision("$N在树丛中发现了一把短剑。\n", this_player());
	jian = new("/clone/weapon/duanjian.c");
	jian->move(this_object());

	return 1;
}
