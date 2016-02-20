//Cracked by Roath
// Room: /d/taishan/zhengqi.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "正气厅");
	set("long", @LONG
这里是封禅台右边的正气厅，武林盟罚恶使者平时不下山时，
通常都是在这里处置武林公案。上首正中放着把虎皮椅，罚恶使者
就坐在上面开堂审理。左右各侍立着几位红衣武士，看上去杀气腾
腾，令人凛然而生惧意。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"fengchannw",
		"southeast" : __DIR__"fengchansw",
	]));

	set("objects",([
		"/clone/npc/fa-e" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));

        set("no_clean_up", 1);

	set("cost", 2);
	setup();
}

void init()
{
	object ob;	

	if( objectp( ob = present("fae 2", this_object()) ) )
	destruct(ob);
}

