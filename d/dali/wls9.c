//Cracked by Kafei
// Room: /dali/wls9.c
// AceP
// The path from ChaDao to Wu Liang Shan :
// se; w; s; n; ne; w; sw; n; 9: #9, ne; sw; nw; e; s; w; sw; n; w;

inherit ROOM;

int do_say(string);
int do_drop(object);

void create()
{
	set("short", "无量山区");
	set("long", @LONG
这里是云南大理境内的无量山区。地形崎岖，荆棘丛生。根本没有道路，只有
一些猎人和采药人走出来的小径。雾气大，林子黑，容易迷路。而且经常有瘴气发
生，毒性很大，一中毒就没救了。不少人走进来就再也没出去，你还是小心为好。
可是，你刚进来就发现不大认得清方向了！
LONG
	);

	set("exits", ([
		"southeast" : __FILE__,
		"northeast" : __DIR__"wls1",
		"southwest" : __FILE__,
		"northwest" : __FILE__,
		"south"     : __DIR__"wls8",
		"north"     : __DIR__"wls1",
		"west"      : __FILE__,
		"east"      : __DIR__"wls1",
	]));

	set("cost", 3);
	set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_say", "say");
	add_action("do_drop", "drop");
}

int do_say(string arg)
{
	object me;
	me=this_player();

	if (arg=="青衫磊落险峰行")
	{
		if (me->query("got_beiming")
			&& !me->query("ate_hama")
			&& !me->query_temp("tried")) {
			if (random(me->query("kar"))>20) {
				tell_object(me, "你开口想吟句诗，不料一不留神，脚下一绊，扎进了树丛里。\n");
				me->move(__DIR__"shucong");
				me->set_temp("tried",1);
				return 1;
			}
			me->set_temp("tried",1);
			return 0;
		}
		if (!query("opened")) {
			set("exits/northeast", __DIR__"wls10");
			set("opened",1);
			remove_call_out("closing");
			call_out("closing", 10);
		}
	}
	return 0;
}

void closing()
{
	set("exits/northeast", __DIR__"wls1");
}

int do_drop(object ob)
{
	write("你不能把它丢掉，它会掉进草丛里找不到的。\n");
	return 1;
}
