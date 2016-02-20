//Cracked by Kafei
// Room: /d/dali/wls1.c
// AceP
// The path from ChaDao to Wu Liang Shan :
// 1: se; w; s; n; ne; w; sw; n; #9, ne; sw; nw; e; s; w; sw; n; w;

inherit ROOM;

int do_drop(object);
int do_find(string);

void create()
{
	set("short", "无量山区");
	set("long", @LONG
这里是云南大理境内的无量山区。地形崎岖，荆棘丛生。根本没有道路，只有
一些猎人和采药人走出来的小径。雾气大，林子黑，容易迷路。而且经常有瘴气发
生，毒性很大，一中毒就没救了。不少人走进来就再也没出去，你还是小心为好。
可是，你刚进来就发现不大认得清方向了！
LONG );

	set("exits", ([
		"southeast" : __DIR__"wls2",
		"northeast" : __FILE__,
		"southwest" : __FILE__,
		"northwest" : __FILE__,
		"south"     : __FILE__,
		"north"     : __FILE__,
		"west"      : __FILE__,
		"east"      : __DIR__"chadao",
	]));

	set("cost", 3);
	set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_drop", "drop");
	add_action("do_find", "find");
}

int do_drop(object ob)
{
	write("你不能把它丢掉，它会掉进草丛里找不到的。\n");
	return 1;
}

int do_find(string arg)
{
	object *inv;
	object me, ob;
	int i;
	me=this_player();

	if (arg=="miji" && me->query("got_beiming") && !me->query_temp("got_miji")) {
		tell_object(me,"你在树丛里乱翻了一阵，找回了自己以前藏在这儿的《北冥秘籍》。\n");
		ob=new(__DIR__"obj/beiming-miji");
		ob->move(me);
		me->set_temp("got_miji",1);
		return 1;
	}
	if (arg=="way" && me->query("got_beiming")) {
		inv=all_inventory(me);
		for(i=0; i<sizeof(inv); i++) 
			if (inv[i]->is_character())
			return notify_fail("此人昏迷不醒，你还是赶快找地方医救他吧。\n"); 
		tell_object(me,"你拨开树丛找了一阵，发现了一条小路。\n");
		me->move(__DIR__"jb2");
		return 1;
	}
	return 0;
}
