//Cracked by Roath
// /d/mingjiao/damen.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIR"明教山门"NOR);
    set("long",@LONG    
此处乃明教山门，地势虽略显平坦但更增诡异。山门两旁耸立数棵参
天古松，显出明教气势非凡。在左边一块凸起的大山岩上刻有着龙飞凤舞
的两个红色大字：『明教』。
LONG
	);
		set("objects",([
		__DIR__"npc/mingjiao_shouwei" : 4,
]));


 	set("exits",([
		      "northup" : __DIR__"shanmentongdao",	

			"south" : __DIR__"shankou",	
		      	]));
	set("outdoors", "mingjiao");
	set("cost", 1);
	setup();

}
int valid_leave(object me, string dir)
{
	object ob;
//	mapping fam = this_player()->query("family");
        if (dir == "northup" 
			&& objectp(ob=present("mingjiao shouwei", environment(me)))
			&&living(ob))
//			if (fam["family_name"] != "明教")
			if (this_player()->query("family/family_name") != "明教")
                return notify_fail(
				"明教守卫喝道：里面是明教圣地，这位" + 	RANK_D->query_respect(me)+"并非我教信徒，请止步!\n");
        return ::valid_leave(me, dir);
}

