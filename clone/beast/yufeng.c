//Cracked by Kafei
//yufeng.c

inherit NPC;

void create()
{
	set_name("玉蜂", ({"yu feng", "bee", "feng"}) );
	set("race", "昆虫");
	set("subrace", "飞虫");
	set("age", 5);
        set("long", "这是一只玉色的蜜蜂，个头比普通蜜蜂大得多，\n"
                    "翅膀上被人用尖针刺有字。\n");
	set("str", 40);
	set("dex", 50);

	set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );

	set_temp("apply/attack", 33);
	set_temp("apply/armor", 15);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"玉蜂嗡嗡嗡飞过来，在你头上转了一圈，又飞走了。\n",
		"玉蜂飞到路边的一朵鲜艳的野花上，忙忙碌碌地采着蜜。\n",
	 }) );

	setup();
}

