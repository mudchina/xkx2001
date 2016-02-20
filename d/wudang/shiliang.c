//Cracked by Roath
// shiliang.c 武当石梁
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "石梁");
	set("long", @LONG
	你走入山坞中，有一道石梁跨溪而建，这里是九渡涧的下流，各岭之水均
在此交汇，景色极佳。附近设有许多小吃店，游人至此，大多小住歇歇脚力。再往
上就是陡峭的十八盘了。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southup" : __DIR__"shibapan",
		"northup" : __DIR__"taizipo",
	]));

	set("cost", 2);
	setup();
	replace_program(ROOM);
}

