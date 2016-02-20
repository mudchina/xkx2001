//Cracked by Roath
// Summer 9/26/1996.

inherit NPC;
int ask_tea();
void create()
{
	set_name("小喇嘛", ({ "xiao lama", "xiao", "lama" }));
	set("long", 
"这是烧茶的小喇嘛，他身穿黄色袈裟，左手拿着个大茶勺， \n"
"正汗流满面地跟茶锅前忙乎。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("class","bonze");
	set("shen_type", 1);
	set("str", 22);
	set("int", 20);
	set("con", 22);
	set("dex", 21);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 10);
	set("combat_exp", 1000);

	set_skill("force", 20);
	set_skill("dodge", 25);
	set_skill("parry", 20);
	set_skill("strike", 20);
	set("inquiry", ([
                "酥油茶" : (: ask_tea :),
	]));

	setup();
	carry_object(__DIR__"obj/lamajiasha")->wear();
}
int ask_tea()
{
	say("小喇嘛一脸不耐烦：酥油那麽贵，想喝茶那能说有就有，等着！ \n");
	this_player()->set_temp("marks/茶", 1);
	return 1;
}
int accept_object(object who, object ob)
{
	object tea; 
	if (ob->name()!="酥油") {
	write("小喇嘛笑得合不拢嘴：佛主保佑" + RANK_D->query_respect(who)+ "。\n");
        return 1;
        }
                        write(
"小喇嘛点头哈腰：佛主保佑" + RANK_D->query_respect(who)+" ，请用茶。\n");
        who->delete_temp("marks/茶");
        tea=new("/d/qilian/obj/buttertea");
	tea->move("/d/qilian/chufang");
	tea=new("/d/qilian/obj/buttertea");
	tea->move("/d/qilian/chufang");
	tea=new("/d/qilian/obj/buttertea");
        tea->move("/d/qilian/chufang");
        return 1;

}
void destroy (object ob)
{
        destruct(ob);
}
