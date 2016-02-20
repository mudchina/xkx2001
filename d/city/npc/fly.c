//Cracked by Roath
//fly.c 苍蝇

inherit NPC;

void create()
{
	set_name("苍蝇", ({"fly"}) );
	set("race", "昆虫");
	set("subrace", "飞虫");
	set("age", 2);
	set("long", "这是一只讨厌的大头苍蝇，嗡嗡嗡地飞来飞去。\n");
	
	set("str", 10);
	set("dex", 40);

	set_temp("apply/attack", 5);
	set_temp("apply/armor",  5);
	
	set("chat_chance", 8);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"苍蝇嗡嗡嗡飞过来，绕着你转了几圈。\n",
		"苍蝇在你前後左右转悠着，似乎被你身上带的食物香味吸引住了。\n",
		"苍蝇嗡地飞到地上，叮在一堆狗屎上贪婪地吸吮着。\n"
	 }) );

	setup();
}

void init()
{
	this_object()->set_leader(this_player());
}