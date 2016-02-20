//Cracked by Roath
// biaohuo.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("红镖", ({"hong biao", "biao"}));
	set("long",
		"这是一份红镖，包装地非常仔细，不知装着什么东西。\n");
	set("unit", "份");
	set("weight", 20);
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
}

int do_check()
{
	object ppl = this_player();
	
	if ( ppl->query_temp("biao/li") ) write("这是华山脚下玉泉院李铁嘴的镖货。\n");
	if ( ppl->query_temp("biao/ma") ) write("这是泉州扬威武馆馆主马五德老师托送的镖货。\n");
	if ( ppl->query_temp("biao/zhu") ) write("这是白鹿书院朱熹先生的镖货。\n");
	if ( ppl->query_temp("biao/bayi") ) write("这是北疆小镇巴依托送的重镖，要尽快送到。\n");
	if ( ppl->query_temp("biao/jiang") ) write("这是当今武林盟主所重托的红镖，须交到亲兵队长江百胜手里。\n");

	return 1;
}

void destroy_it(object ppl, object obj) 
{ 
	tell_object( ppl, "时限已到，你的任务失败了！\n" );
	ppl->delete_temp("apply/short");
	ppl->delete_temp("biao");	
	ppl->set_temp("biao/fail", 1);
	destruct(obj); 
}
