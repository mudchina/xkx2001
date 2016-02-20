//Cracked by Roath
string ask_biao()
{
	object ob = this_player();
	object me = this_object();
	object biao;
	mapping skill_status;
        string *sname, value, destin;
        int i, quali = 0;

	if ( ob->query("family/family_name") == "丐帮" )
                return "臭要饭的到这儿胡搅什么，快走快走！";

	if ( ob->query("biao_stealer") >= 1 ) {
		command( "sneer" );
		return "你声名狼籍，监守自道，我怎能信得过你？";
	}

	if ( (int)ob->query_temp("biao/fail") ) 
		return "你这不中用的家伙，亏你还有脸回来见我要求走镖！";

	if ( (int)ob->query_temp("biao/times") >= 5 )
		return "你已干了好多活儿，还是休息一下吧。";

	if ( (int)me->query_temp("biao") >= 20 )
		return "今天所有的镖都已送完了，你明天早点来吧。";

	if ( ob->query_temp("biao/pending") ) {
		command( "angry" );
		return "你还没将东西送到雇主手上，怎么便想讨多桩差事？";
	}

	//Check qualifications to assign proper tasks.
	if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
			quali += skill_status[sname[i]];
		}	  

		quali = quali/sizeof(skill_status);

	}
	else {
		quali = 0;
	}

	if ( quali < 10 ) return "哈哈！就凭你？还是先将功夫练好再说吧。";

	command( "say 好吧，你来得正是时候，我这儿正缺人用。");
	switch( random(5) ) {
		case 0:
			ob->set_temp("biao/zhu", 1);
			command("say 你把这份东西送到白鹿书院朱熹先生那儿，他便会付钱给你。");
			destin = "白鹿书院朱熹";
			break;
		case 1:
			ob->set_temp("biao/bayi", 1);
			command("say 这是北疆小镇的巴依老爷托送的重镖，你得多加小心，丢了可赔不起！");
			destin = "北疆小镇巴依";
			break;
                case 2:
			ob->set_temp("biao/ma", 1);
			command("say 这份重镖是送到泉州扬威武馆的，你得亲自交给馆主马五德老师。");
			destin = "扬威武馆马五德";
			break;
		case 3:
			ob->set_temp("biao/li", 1);
			command("say 这有份要送给华山脚下玉泉院李铁嘴的镖货，你帮我走一趟吧。");
			destin = "玉泉院李铁嘴";
			break;
                case 4:
			ob->set_temp("biao/jiang", 1);
			command("say 这是当今武林盟主所重托的红镖，非同小可。你千万不可大意，务必交到亲兵队长江百胜手里。");
			destin = "泰山江百胜";
			break;
	}
			
	message_vision( "$n交给$N一份镖货。\n", ob, me );

	//player record
	ob->add_temp("biao/times", 1);
	ob->set_temp("biao/pending", 1);
	ob->set_temp("apply/short", ({"镖客 "+ob->name()+"("+ob->query("id")+")"}));

	//goods record
	biao = new("/d/city/obj/biaohuo1");
	biao->move(ob);
	biao->set_temp("guard", ob->query("id"));
	if ( ob->query_temp("biao/li") ) biao->set_temp("dest", "li");
	if ( ob->query_temp("biao/ma") ) biao->set_temp("dest", "ma");
        if ( ob->query_temp("biao/zhu") ) biao->set_temp("dest", "zhu");
        if ( ob->query_temp("biao/bayi") ) biao->set_temp("dest", "bayi");
        if ( ob->query_temp("biao/jiang") ) biao->set_temp("dest", "jiang");
	if ( quali < 30 ) {
		biao->set_temp("prop", 1);
		value = "普通东西";
	}
	else if ( quali < 60 ) {
		biao->set_temp("prop", 2);
		value = "贵重事物";
	}
	else if ( quali < 90 ) {
		biao->set_temp("prop", 3);
		value = "珍贵物品";
	}
	else if ( quali < 120 ) {
		biao->set_temp("prop", 4);
		value = "罕有之物";
	}
	else if ( quali < 150 ) {
		biao->set_temp("prop", 5);
		value = "珍罕宝物";
	}
	else if ( quali < 180 ) {
		biao->set_temp("prop", 6);
		value = "稀世奇珍";
	}
	else {
		biao->set_temp("prop", 7);
		value = "无价之宝";
	}

	//announce by rumor
	CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s将保送一件%s给%s。", ob->name(), value, destin));

	//assigner record
	me->add_temp("biao", 1);

	switch( random(4) ) {
		case 0:
			return "所谓镖在人在，镖亡人亡，你务必在限定的时间内完成任务！";
			break;
		case 1:
			return "一路上你可能会碰上土匪强盗，你一定要多加小心。";
			break;
                case 2:
			return "最近世道混乱，盗匪四起，你千万不能砸了咱们镖局的老字号！";
			break;
                case 4:
			return "你必须尽快将镖货送到雇主手里，迟了镖局可赔不起！\n";
			break;
	}
}
