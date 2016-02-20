//Cracked by Kafei
// Room: /d/dali/wls4.c
// AceP
// The path from ChaDao to Wu Liang Shan :
// se; w; s; 4: n; ne; w; sw; n; #9, ne; sw; nw; e; s; w; sw; n; w;

inherit ROOM;

int do_drop(object);

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
		"southeast" : __DIR__"wls4",
		"northeast" : __DIR__"wls4",
		"southwest" : __DIR__"wls4",
		"northwest" : __DIR__"wls4",
		"south"     : __DIR__"wls3",
		"north"     : __DIR__"wls5",
		"west"      : __DIR__"wls1",
		"east"      : __DIR__"wls1",
	]));

	set("cost", 3);
        set("outdoors", "dali");
	setup();
}

void init()
{
	object me;
	me=this_player();

	if (random(15)==0) {
		tell_object(me, "你突然感到吸进了些怪异气味，喉头一紧，脚步一个踉跄。\n不好！中瘴气了！\n");
		me->unconcious();
		me->move(__DIR__"wls2");
	}
	add_action("do_drop", "drop");
}

int do_drop(object ob)
{
	write("你不能把它丢掉，它会掉进草丛里找不到的。\n");
	return 1;
}
