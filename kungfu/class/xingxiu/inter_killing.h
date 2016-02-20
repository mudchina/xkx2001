//Cracked by Roath
// interfere killing function (dispatched by chat_msg)

int inter_killing()
{
	object ob, ob1, me; 
	me = this_object();
	ob = this_player();

	if( interactive(ob = this_player()) 
	&& environment(ob) == environment()){
	if ( ob1->query("family/family_name") == "星宿派" 
	&& ob->query("family/family_name") != "星宿派"  
	&& ob->is_killing(ob1)){
	
	message_vision("$N一声冷笑：大胆狂徒！竟敢当着我的面行凶杀人，当我星宿派好欺负么？\n", me);
	command("follow " + ob->query("id"));
	me->kill_ob(ob);
	return;
	}
	}
}
