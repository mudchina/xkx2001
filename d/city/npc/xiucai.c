//Cracked by Roath
// xiucai.c 老秀才
// ryu, 11/1/96
// modified by aln 2 / 98

inherit NPC;

void create()
{
	set_name("老秀才", ({ "lao xiucai", "xiucai" }));
	set("long", "一个穷困潦倒的落第秀才，在这里开堂授课为生。\n");
	set("gender", "男性");
	set("age", 65);

	set_skill("literate", 30);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	set("combat_exp", 2000);
	set("shen_type", 1);
	setup();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/朱"))
		return 0; 
	ob->add_temp("mark/朱", -1);
	return 1;
}

int accept_object(object who, object ob)
{ 
        object wage;

        if( base_name(ob) == "/d/hangzhou/obj/mh_book" ) {
                if( !ob->query("checked") ) {
                       command("say 这本明史未经顾先生修撰，里面谬误一定很多吧。");
                       return 0;
                }

                if( time() < (int)query("mh_time") + 300 ) {
                       command("say 我刚拿到了一本，你还是给别人吧。");
                       return 0;
                }

                command("joythank " + who->query("id"));
                set("mh_time", time());
                wage = new("/clone/money/silver");
                wage->set_amount(3 + random(5));
                wage->move(who);
                message_vision("$N封了一包银子给$n。\n", this_object(), who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }
                       
	if (who->query_skill("literate", 1) > 30){
                message_vision("老秀才叹了口气对$N说道：阁下另请名师吧，我肚子里这点儿墨水已经教不了你了。\n", who);
                return 0;
        }
	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (ob->query("money_id") && ob->value() >= 200) {
		message_vision("老秀才同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 50);
		return 1;
	}
	return 0;
}
void destroy_it(object obj)
{
        destruct(obj);
}

