//Cracked by Roath
// bian.c 匾后
// qfy July 14, 1996

inherit ROOM;

void create()
{
	set("short", "匾后");
	set("long", @LONG
匾后地方狭小，令人难以旋身。黑漆漆的甚么也看不见。
LONG
	);

	set("exits", ([
		"down" : __DIR__"buwei1",
	]));
	
	set("zixia_count", 1);

	set("cost", 2);
	setup();
}

void init()
{
	add_action("do_use","use");
}

int do_use(string arg)
{
    object ob, me = this_player();
    int seed;	

    if( !arg || arg=="" ) return 0;
	
    if (!present("fire", me))  return 0;

    if ( me->query("family/family_name") == "华山派" ) seed = 1;
    else if ( random(100) == 3 ) seed == 1;
    else seed = 0;

    if( arg=="fire" && seed == 1 ) {
	if ( query("zixia_count") >= 1 && !me->query_temp("marks/紫") ) {
	   ob = new(__DIR__"obj/zixia_book");
	   if (!ob) 
	   return notify_fail("你发现原来这里曾经有人来过，不知其人有何意图。\n"); 
	   ob->move(me);
	   add("zixia_count", -1);
	   CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了紫霞秘籍。", me->query("name")));
           me->set_temp("marks/紫", 1);
	   write("你突然发现一本薄薄的册子，仔细一看原来是华山镇山之宝「紫霞秘笈」！\n");
	   write("你「紫霞秘笈」小心的收好。\n");
	}
	else {
	   write("你发现原来这里曾经有人来过，不知其人有何意图。\n");
	}
    }
    else write("你发现原来这里曾经有人来过，不知其人有何意图。\n");

    return 1;
}
