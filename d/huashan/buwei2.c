//Cracked by Roath
// buwei2.c

inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这里是岳不群的寝室，岳不群在江湖上人称「君子剑」，他虽为一大
派掌门，可他的卧室却布置的很简单。除了一张床，几只箱子，墙角有张
化妆台，只有靠墙一张红木书桌还显得略有气派。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "north" : __DIR__"pianting2",
]));
	set ("item_desc", ([
		"desk" : 
"这是一张很结实的红木书桌，桌面上摆着几只狼毫笔，磨了一半的墨，\n"
"还有一叠未用的白纸。\n",
		"bed" :
"床铺简单朴素，摺叠得整整齐齐。\n",
	])  ) ;

	set("no_clean_up", 0);
	set("zixia_count", 1);
	set("cost", 0);

	setup();
}

void init()
{
//	add_action("do_move", "move");
	add_action("do_search", "search");
	add_action("do_search", "find");
}

/*
int do_move(string arg)
{
	object paper;
	paper = new(__DIR__"obj/paper");

	if( !arg || arg=="" ) return 0;

	if( arg=="desk" ) {
		if (!query("hs_trigger")){
		message_vision(
"$N轻轻的推了推书桌，沉重的书桌似乎根本没动...，突然从书桌和\n"
"墙壁之间飘落出一张纸。\n", this_player());
		paper->move(__FILE__);
		set("hs_trigger", 1);
		return 1;
		}
		message_vision(
"$N轻轻的推了推书桌，沉重的书桌纹丝不动。\n", this_player());
		return 1;
	}
	return 0;
}
*/

int do_search(string arg)
{
	object ob, *obs, me = this_player();

	if( !arg || arg=="" ) return 0;
	
	if( arg != "bed" ) return 0;

	if( me->query("family/family_name") != "华山派" )
		return notify_fail("你将枕头掀起，底下却甚麽都没有。\n");

	if ( query("zixia_count") >= 1 && !me->query_temp("marks/紫") ) {
	   obs = filter_array(children(__DIR__"obj/zixia_book.c"), (: clonep :));
           if (sizeof(obs) > 2)
	   	return notify_fail("你将枕头掀起，底下却甚麽都没有。\n"); 

   	   ob = new(__DIR__"obj/zixia_book");	   
	   ob->move(me);
	   add("zixia_count", -1);
	   CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了紫霞秘籍。", me->query("name")));
	   me->set_temp("marks/紫", 1);
	   write("你将枕头掀起，突然发现一本薄薄的册子，仔细一看原来是华山镇山之宝「紫霞秘笈」！\n");
	   write("你把「紫霞秘笈」小心的收好。\n");
	}
	else {
	   write("你将枕头掀起，底下却甚麽都没有。\n");
	}
   
	return 1;
}
