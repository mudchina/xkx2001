//Cracked by Kafei
// monster.c

#ifndef __MONSTER__
#define __MONSTER__

// A normal monster is at least 10 kg weight
#define BASE_WEIGHT 10000

#endif

inherit F_DBASE;

void setup_monster(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	my["unit"] = "只";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "雄性";
	if( undefinedp(my["age"]) ) my["age"] = random(80) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(41) + 10;
	if( undefinedp(my["int"]) ) my["int"] = random(41) + 10;
	if( undefinedp(my["per"]) ) my["per"] = random(11) + 10;
	if( undefinedp(my["con"]) ) my["con"] = random(41) + 10;
	if( undefinedp(my["dex"]) ) my["dex"] = random(41) + 10;

	if( undefinedp(my["max_jing"]) ) {
		if( my["age"] <= 3 ) my["max_jing"] = 50;
		else if( my["age"] <= 10 ) my["max_jing"] = 50 + (my["age"] - 3) * 30;
		else if( my["age"] <= 60 ) my["max_jing"] = 260 + (my["age"] - 10) * 5;
		else my["max_jing"] = my["max_jing"] = 510 + (my["age"] - 60);
	}
	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 10 ) my["max_qi"] = 100;
		else if( my["age"] <= 30 ) my["max_qi"] = 100 + (my["age"] - 10) * 30;
		else my["max_qi"] = my["max_qi"] = 700 + (my["age"] - 30) * 10;
	}
	if( undefinedp(my["max_jingli"]) ) {
		if( my["age"] <= 10 ) my["max_jingli"] = 100;
		else if( my["age"] <= 30 ) my["max_jingli"] = 100 + (my["age"] - 10) * 50;
		else my["max_jingli"] = my["max_jingli"] =1000 + (my["age"] - 30) * 10;
	}
	//	NOTE: monster has no initial limbs defined, you must define it yourself.
	//	ob->init_limbs(LIMBS);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);

	set("dead_message",       "\n$N仰天惨嚎了一声，趴在地上不动了。\n\n"      );
	set("unconcious_message", "\n$N咆哮一声，倒在地上昏了过去。\n\n"          );
	set("revive_message",     "\n$N慢慢睁开眼睛，清醒了过来。\n\n"            );
	set("comeout_message",    "往$d离开。\n"                                  );
	set("comein_message",     "缓缓地走了过来。\n"                            );
	set("fleeout_message",    "咆哮一声，往$d落荒而逃了。\n"                  );
	set("fleein_message",     "摇摇摆摆地跑了过来，伸出舌头呼呼地喘着粗气。\n");
}

