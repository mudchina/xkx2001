//Cracked by Roath
// Room: /d/taishan/xiayi.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "侠义厅");
	set("long", @LONG
这里是封禅台左边的侠义厅，武林盟赏善使者平时不下山时，
通常都是在这里办理武林公案。上首正中放着把太师椅，赏善使者
就坐在上面开堂审理。左右各侍立着几位红衣武士，看上去威风凛
凛，自有一股庄严气象。
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"fengchanne",
		"southwest" : __DIR__"fengchanse",
	]));

	set("objects",([
		"/clone/npc/shang-shan" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));

        set("no_clean_up", 1);

	set("cost", 2);
	setup();
}

void init()
{
	object ob;	

	if( objectp( ob = present("shangshan 2", this_object()) ) )
	destruct(ob);
}

