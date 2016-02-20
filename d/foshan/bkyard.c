//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

int do_jiaofen(string);

void create()
{
        set("short", "戚家后院");
        set("long", @LONG
这里是个小菜园，院中种了好多蔬菜。在园子的一角有个粪池(chi)，
隐隐飘来些粪便的味道。
LONG
        );
        set("exits", ([
		"east" : __DIR__"yard",
	]));
	set("item_desc", ([
		"chi" : "粪池旁有个粪勺，可以用来浇粪(jiaofen)。\n",
	]));
	set("objects", ([
		__DIR__"obj/kongxin" : 2,
		"/d/wudang/npc/bee" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
}

void init()
{
        add_action("do_jiaofen","jiaofen");
}

int do_jiaofen(string arg)
{
        object me;
        me = this_player();

	me->receive_damage("qi",10, "干农活累死了");
	me->add_temp("qi/work",1);
	message_vision("$N一勺又一勺地浇粪，累得腰酸腿疼。\n", me);
	if (me->query("qi")<40)
		tell_object(me, "你已经累得直不起腰了。\n", me);
	return 1;
}

