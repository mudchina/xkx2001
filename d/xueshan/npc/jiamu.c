//Cracked by Roath
// Summer 9/26/1996.

inherit NPC;
string ask_me();

void create()
{
	set_name("嘉木活佛", ({ "jiamu huofo", "jiamu", "huofo" }));
	set("long", 
"他是本寺的最资深的活佛，须发皆白。他从小就在寺中长大，一直潜心佛法，从未踏\n"
"山门一步。\n");
//	set("title","大轮寺主持");
	set("gender", "男性");
	set("age", 80);
	set("attitude", "friendly");
	set("class","bonze");
	set("shen_type", 1);
	set("str", 33);
	set("int", 35);
	set("con", 29);
	set("dex", 29);
	
	set("max_qi", 1000);
	set("max_jing", 850);
	set("jiali", 40);
	set("combat_exp", 80000);
	set("score", 5000);

	set("inquiry", ([
                "供奉" : (: ask_me :),
		"藏经" : "找拉章活佛要去。",
        ]));

        set("book_count", 1);
        setup();
        carry_object(__DIR__"obj/lamajiasha")->wear();
}
string ask_me()
{
        mapping fam;
	object wage;
        object me = this_player();

        if (!(fam = me->query("family")) || fam["family_name"] !="雪山派"
	&& fam["family_name"] !="血刀门" && me->query("class") !="lama")
                return RANK_D->query_respect(this_player()) +
                "与本寺素无来往，不知此话从何谈起？";
	if (me->query_skill("lamaism", 1) < 60)
		return "你不能要供奉。";
	if (me->query("age") < 25 && me->query("lama_wage") > me->query("mud_age") - 86400)
		return RANK_D->query_respect(this_player()) +
                "，年关没过，怎麽又来要供奉？";
	if (me->query("age") > 24 && me->query("lama_wage") > me->query("mud_age") - 259200)
		return RANK_D->query_respect(this_player()) +
                "，年关没过，怎麽又来要供奉？";
	if (me->query_skill("lamaism", 1) >= 60
	&& me->query_skill("lamaism", 1) < 90){
	wage = new("/clone/money/gold"); 	
	wage->set_amount(10);
	wage->move(me);
	me->set("lama_wage",me->query("mud_age"));
	message_vision("嘉木活佛转身拿出一个红包递给$N。\n", me);
                return "这是上人今年的贡奉，请收好。";
	}
	if (me->query_skill("lamaism", 1) >= 90
        && me->query_skill("lamaism", 1) < 120){
	wage = new("/clone/money/gold");
        wage->set_amount(40);
	wage->move(me);
        me->set("lama_wage",me->query("mud_age"));
	message_vision("嘉木活佛转身拿出一个红包递给$N。\n", me);
                return "这是上人今年的贡奉，请收好。";
        }
	if (me->query_skill("lamaism", 1) >= 120
        && me->query_skill("lamaism", 1) < 150){
        wage = new("/clone/money/gold");
        wage->set_amount(80);
	wage->move(me);
        me->set("lama_wage",me->query("mud_age"));
        message_vision("嘉木活佛转身拿出一个红包递给$N。\n", me);
                return "这是佛爷今年的贡奉，请收好。";
        }
	if (me->query_skill("lamaism", 1) >= 150){ 
        wage = new("/clone/money/gold");
	wage->move(me);
        wage->set_amount(120);
        me->set("lama_wage",me->query("mud_age"));
	message_vision("嘉木活佛转身拿出一个红包递给$N。\n", me);
                return "这是法王今年的贡奉，请收好。";
        }	
}
