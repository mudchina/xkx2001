//Cracked by Roath
// Room: /d/shaolin/wuchang3.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。
上千年的踩踏已使得这些石板如同镜子般平整光滑。练武场中间
竖立着不少木人和草靶。西边角上还有两个大沙坑，十来个僧人
正在练习武艺。东西两面各有一长溜僧房。
LONG
	);

	set("exits", ([
		"south" : __DIR__"fzlou",
		"east" : __DIR__"hsyuan1",
		"west" : __DIR__"hsyuan4",
		"north" : __DIR__"guangchang5",
		"northup" : __DIR__"dmyuan",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		CLASS_D("shaolin") + "/dao-cheng" : 1,
                __DIR__"npc/mu-ren" : 1
	]));

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;

	if (dir == "northup")
	{
		if( mapp(fam = me->query("family")) 
		&&  fam["family_name"] == "少林派" 
		&&  fam["generation"] > 37  ) 
			return notify_fail("你虽是本寺弟子， 但级别不够，不能进入达摩院。\n");
		if( !me->query("luohan_winner") )
			return notify_fail("你不是本寺弟子，未能通过十八罗汉阵，不能进入达摩院。\n");
	}

	return ::valid_leave(me, dir);
}


