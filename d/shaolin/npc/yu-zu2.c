//Cracked by Roath
// yu-zu.c

#include <ansi.h>

inherit NPC;

string *death_msg = ({
	HIB "狱卒说道：喂！新来的，你叫什么名字？\n\n" NOR,
	HIB "狱卒用奇异的眼光盯著你，好像要看穿你的一切似的。\n\n" NOR,
	HIB "狱卒「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,
	HIB "狱卒合上册子，说道：你！收舍收舍，快刑满了啊。\n\n" NOR,
	HIB "狱卒说道：你还在这里干什么，快滚，给我滚出少林！\n\n"
		"一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});

void create()
{
	set_name("狱卒", ({ "yu zu", "zu" }) );
	set("long",
		"狱卒伸著长长的舌头瞪著你，黝黑的脸上看不出任何喜怒哀乐。\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
//		(: random_move :),
		"狱卒发出一阵像呻吟的声音，当他发现你正注视著他的时候，瞪了你一眼。\n",
		"狱卒把长长的舌头伸出来，缓缓地舔了舔自己又黑又长的手指。\n"
	}) );
	set("age", 50);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_qi", 900);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);
	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 10, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	if( !ob || !present(ob) ) return;

//	if( !ob->is_ghost() ) {
//		command("say 喂！阳人来阴间做什么？");
//		kill_ob(ob);
//		ob->fight_ob(this_object());
//		return;
//	}

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 60, ob, stage );
		return;
	}
//	else
//		ob->reincarnate();

	ob->move("/d/shaolin/woshi1");
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
		"很久了，只是你一直没发觉。\n", environment(ob), ob);
}
