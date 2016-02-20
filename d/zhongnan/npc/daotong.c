//Cracked by Roath
// /kungfu/class/quanzhen/daotong.c
//   道童
// sdong 08/01/98

inherit NPC;

void create()
{
	set_name("道童", ({ "daotong", "daotong" }));
	set("long",
		  "他是一小道士，满脸笑容，很可爱的样子。\n"
		);
	set("gender", "男性");
	set("age", 12);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 20);

	set("max_qi", 200);
	set("max_jing", 100);
	set("max_jingli", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 1000);

	set_skill("force", 10);
	set_skill("xiantian-gong", 10);
	set_skill("dodge", 10);
	set_skill("cuff", 10);
	set_skill("strike", 10);
	set_skill("parry", 10);
	set_skill("sword", 10);
	set_skill("literate", 10);
	set_skill("taoism", 10);

	create_family("全真教", 5, "弟子");

	set("class", "taoist");

	setup();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void serve_tea(object who)
{
        object ob;
        object room;

        if( !who || environment(who) != environment() ) return;

		  if( !objectp(room = environment()) ) return;

		  message_vision("小道士拿出一碟新鲜的水蜜桃，又沏了杯香茶给$N。\n", who);
		  ob = new("d/wudang/obj/xiangcha");
		  ob->move(this_player());
		  ob = new("d/wudang/obj/mitao");
		  ob->move(this_player());
		  message_vision("小道士向$N一笑，又忙着招呼其他客人去了。\n", who);

		  return;
}
