//Cracked by Roath
// biaohuo.c

#include <ansi.h>
inherit ITEM;

void create()
{
	seteuid(getuid());
	set_name(RED"红镖"NOR, ({"hong biao", "biao"}));
	set("long",
		"这是一份红镖，包装地非常仔细，不知装着什么东西。\n");
	set("unit", "份");
	set("weight", 20);
	set("value", 30);
}

void init()
{
	object obj = this_object();
	object ppl = this_player();
	int t;

	t = 100 + random(20);
	remove_call_out("destroy_it");
	call_out("destroy_it", t, ppl, obj);

	add_action("do_check", "check");
	add_action("do_open", "open"); 
}

int do_check()
{
	object ppl = this_player();
	object obj = this_object();
	
	if ( obj->query_temp("dest") == "li" ) write("这是华山脚下玉泉院李铁嘴的镖货。\n");
	if ( obj->query_temp("dest") == "ma" ) write("这是泉州扬威武馆馆主马五德老师托送的镖货。\n");
	if ( obj->query_temp("dest") == "zhu" ) write("这是白鹿书院朱熹先生的镖货。\n");
	if ( obj->query_temp("dest") == "bayi" ) write("这是北疆小镇巴依托送的重镖，要尽快送到。\n");
	if ( obj->query_temp("dest") == "jiang" ) write("这是当今武林盟主所重托的红镖，须交到亲兵队长江百胜手里。\n");

	return 1;
}

void destroy_it(object ppl, object obj) 
{ 
	tell_object( ppl, "时限已到，你的任务失败了！\n" );
	ppl->delete_temp("apply/short");
	ppl->delete_temp("biao");	
	ppl->set_temp("biao/fail", 1);
	ppl->add("balance", -100);
	destruct(obj); 
}

int do_open()
{
	object *all, sender, ppl = this_player();
        object obn, obj = this_object();
	int i;

	remove_call_out("destroy_it");
	all = users();
	for(i=0; i<sizeof(all); i++) {
		if( all[i]->query("id") == obj->query_temp("guard") ) sender = all[i];
	}

        if ( obj->query_temp("prop") == 1 ) {
		switch( random(3) ) {
			case 0:
				obn = new("/clone/money/silver");
				obn->set_amount(20);
				break;
			case 1:
				obn = new("/clone/money/silver");
				break;
                        case 2:
				obn = new("/clone/money/silver");
                                break;
		}
		ppl->add("shen", -1 );
	}
	else if ( obj->query_temp("prop") == 2 ) {
                switch( random(3) ) {
                        case 0:
                                obn = new("/clone/money/silver");
                                obn->set_amount(20);
                                break;
                        case 1:
                                obn = new("/clone/money/silver");
                                break;
                        case 2:
                                obn = new("/clone/money/silver");
                                break;
                }
		ppl->add("shen", -1 );
	}
	else if ( obj->query_temp("prop") == 3 ) {
                switch( random(3) ) {
                        case 0:
                                obn = new("/clone/money/silver");
                                obn->set_amount(20);
                                break;
                        case 1:
                                obn = new("/clone/money/silver");
                                break;
                        case 2:
                                obn = new("/clone/money/silver");
                                break;
                }
		ppl->add("shen", -1 );
        }
        else if ( obj->query_temp("prop") == 4 ) {
                switch( random(3) ) {
                        case 0:
                                obn = new("/clone/money/silver");
                                obn->set_amount(20);
                                break;
                        case 1:
                                obn = new("/clone/money/silver");
                                break;
                        case 2:
                                obn = new("/clone/money/silver");
                                break;
                }
		ppl->add("shen", -1 );
        }
	else if ( obj->query_temp("prop") == 5 ) {
                switch( random(3) ) {
                        case 0:
                                obn = new("/clone/money/silver");
                                obn->set_amount(20);
                                break;
                        case 1:
                                obn = new("/clone/money/silver");
                                break;
                        case 2:
                                obn = new("/clone/money/silver");
                                break;
                }
		ppl->add("shen", -1 );
        }
	else if ( obj->query_temp("prop") == 6 ) {
                switch( random(3) ) {
                        case 0:
                                obn = new("/clone/money/silver");
                                obn->set_amount(20);
                                break;
                        case 1:
                                obn = new("/clone/money/silver");
                                break;
                        case 2:
                                obn = new("/clone/money/silver");
                                break;
                }
		ppl->add("shen", -1 );
        }
	else {
                switch( random(3) ) {
                        case 0:
                                obn = new("/clone/money/silver");
                                obn->set_amount(20);
                                break;
                        case 1:
                                obn = new("/clone/money/silver");
                                break;
                        case 2:
                                obn = new("/clone/money/silver");
                                break;
                }
		ppl->add("shen", -1 );
        }

	obn->move(ppl);
        tell_object(ppl, "你打开红镖，发现里头装的原来是"+obn->name()+"。\n");

 	if ( ppl->query("id") == obj->query_temp("guard") ) {
                ppl->add("biao_stealer", 1);
                ppl->delete("biao");
                CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s监守自盗了红镖！据闻红镖是%s！", ppl->name(), obn->name()));
	}
	else {
		if ( userp(sender) ) {
                        sender->delete_temp("apply/short");
                        sender->delete_temp("biao");
                        sender->set_temp("biao/fail", 1);
                }
                CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s洗劫了红镖！据闻红镖是%s！", ppl->name(), obn->name()));
	}

	destruct(obj);

	return 1;
}
