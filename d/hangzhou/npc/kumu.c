//Cracked by Roath
// /d/hangzhou/npc/kumu.c
// by aln  2 / 98

inherit NPC;
inherit F_MASTER;

string day_event() { return NATURE_D->outdoor_room_event(); }

string ask_job();

void create()
{
	set_name("枯木禅师", ({
		"kumu chanshi",
		"kumu",
		"chanshi",
	}));
	set("long",
		"这就是本寺的住持，一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 650);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 80000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("finger", 70);
	set_skill("nianhua-zhi", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");

        set("inquiry", ([
                "讲经" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

	setup();

//        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

string ask_job()
{
        object obj, place, *inv, me = this_player();

        if( is_fighting() || is_busy() )
                return "我正忙着。";

        if( (string)me->query("gender") != "男性" )
                return "阿弥陀佛！善哉！善哉！女施主莫开老纳的玩笑。";

        if( (string)me->query("class") != "bonze" )
                return "阿弥陀佛！善哉！善哉！施主不是佛门弟子，还是请回吧。";

        if( (int)me->query_skill("buddhism", 1) < 120 )
                return "本寺只延请高僧前来讲经说佛。";

        if( day_event() != "event_dawn" )
                return "本寺撞钟诵经时辰已过，" + RANK_D->query_respect(me) + "下次再来吧。";

        if( me->query_condition("lyjob") )
                return RANK_D->query_respect(me) + "已经在讲经说佛了。";

        command("nod");
        me->apply_condition("lyjob", 3 + random(3));

        if( random((int)me->query_temp("lypoint")) > 1
        && !(present("jiasha", me)) ) {
                obj = new("/d/hangzhou/obj/jiasha");
                obj->move(me);
                message_vision("旁边一僧将一件红衣袈裟披在$N身上。\n", me);
        }

        return "太好了，本寺正需一名外寺高僧前来讲经说佛。";
}

