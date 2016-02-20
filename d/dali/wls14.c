//Cracked by Kafei
// Room: /dali/wls14.c
// AceP
// The path from ChaDao to Wu Liang Shan :
// se; w; s; n; ne; w; sw; n; #9, ne; sw; nw; e; s; 14: w; sw; n; w;

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
		"southeast" : __DIR__"wls1",
		"northeast" : __DIR__"wls1",
		"southwest" : __DIR__"wls1",
		"northwest" : __DIR__"wls1",
		"south"     : __DIR__"wls1",
		"north"     : __DIR__"wls13",
		"west"      : __DIR__"wls15",
		"east"      : __DIR__"wls1",
	]));

	set("cost", 3);
        set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_drop", "drop");
}

int do_drop(object ob)
{
	write("你不能把它丢掉，它会掉进草丛里找不到的。\n");
	return 1;
}
