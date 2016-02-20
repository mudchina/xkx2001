//Cracked by Roath
// Room: /d/gaibang/inhole.c
// Date: Haa 96/03/22
inherit ROOM;

int do_say(string);

void create()
{
	set("short", "树洞内部");
	set("long", @LONG
这是扬州城中央广场的老槐树内部，也是丐帮秘密地下通道的总交汇处。树
洞里丢满了各种垃圾，弭漫着一股臭哄哄的味道。树洞壁上钉着一块非常醒目的
木牌（board）。
LONG 
	);
	set("exits", ([
		"out" : "d/city/guangchang"
	]));

	set("item_desc",([
		"board"	: "富人地狱，穷人天堂。\n"
	]));

	set("objects",([
		CLASS_D("gaibang") + "/zuo-quan" : 1,
	]));

	set("cost", 1);
	setup();
}

void init()
{
/*	object me = this_player();

	if ( me->query("eat_wan") && me->query("mud_age") < me->query("eat_age")+86400)
	{
	tell_object(me, "你已服仙丸，应在一年内再次服用，否则功力大损！！！\n");
	}

	if ( me->query("eat_wan") && me->query("mud_age") > me->query("eat_age")+86400)
	{
	tell_object(me, "你一年内未服仙丸，功力大损！！！\n");
	me->add("max_jingli", -100);
	me->add("max_neili", -100);
	me->set("eat_age", me->query("mud_age"));
	}

*/
	add_action("do_say", "say");
}

int do_say(string arg)
{
	object *inv, me = this_player();
	int i, count = 0;

	if( !arg || arg=="" ) return 0;

	inv = all_inventory(environment(me));

/*	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->is_character() && 
		(string)inv[i]->query("family/family_name") != "丐帮" ) count ++;
	}
*/
	
	if( (arg=="天堂有路你不走呀" || arg=="地狱无门你进来啊" )
	&& this_player()->query("family/family_name") == "丐帮")
	{
		write("只听里面有人说了声：是本帮兄弟吧？快请进来吧。\n");
		message("vision", "树洞边上一堵墙缓缓移了开来，原来是道小木门。\n", this_player());
		set("exits/down", __DIR__"undertre");

		remove_call_out("close");
		call_out("close", 3, this_object());
		return 1;
	}
	else if ( (arg=="天堂有路你不走呀" || arg=="地狱无门你进来啊" ) 
	&& this_player()->query("family/family_name") != "丐帮" ) 
	{
		write("只听里面有人说了声：阁下光临敝帮有何贵干？\n");
		return 1;
	}

	return 0;
}


void close()
{
        object room = load_object("d/gaibang/undertre");

        message("vision", "小木门悄悄的关上了。\n", this_object() );
        delete("exits/down");
        tell_room(room, "小木门悄悄的关上了。\n");
}

