//Cracked by Kafei
// road: /zhongnan/dating.c
// Xuanyuan

inherit ROOM;

void create()
{
		  set("short","大厅");

		  set("long",@LONG
这大厅布置的极为简单，几张木椅和椅张桌子放在正当中，靠墙的椅
个小柜子上点了一个小香炉，飘出来的袅袅香烟带着一股香味。你只觉得
这味道浓而不腻，反令你有一股飘飘然的感觉。厅中的柱上插了几枝巨烛，
把这ㄦ照的明晃晃的。除了往南有一个小门可通到後堂，其余方向都是幽
暗的走道。
LONG);

	set("exits",([ "west" : __DIR__"zoudao4",
		"south" : __DIR__"houtang",
		"east" : __DIR__"zoudao3",
		"north" : __DIR__"zoudao2",
	]));
	set("objects",([
                "/kungfu/class/gumu/longnu" : 1
	]));
	set("cost",1);
        "/clone/board/gumu_b"->foo();
	 setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        object obj;

        myfam = (mapping)me->query("family");

        if ( objectp(obj=present("xiao longnu", environment(me))) && living(obj) && !wizardp(me) ) {
           if ( (!myfam || myfam["family_name"] != "古墓派") && (dir == "east" || dir == "west") )
                return notify_fail("小龙女说道：本门重地，"+RANK_D->query_respect(me)+"止步！\n");

           if ( myfam && myfam["family_name"] != "古墓派" && (dir == "south" || dir == "east" || dir == "west"))
                return notify_fail("小龙女说道：本门重地，"+RANK_D->query_respect(me)+"止步！\n");
        
	   if ( myfam && myfam["master_name"] == "李莫愁" && dir == "east" )
                return notify_fail("小龙女说道：你还是让师姐本人来取玉女心经吧。\n");
        }

        return ::valid_leave(me, dir);

}
