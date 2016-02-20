//Cracked by Kafei
// updated.c
// created by xuy 8/20/97

void create() { seteuid(getuid()); }

// Separate general user data check from logind.
// Can be used to add routine to update user data like skill name
// change, etc. better be called from logind only.
void login_check(object ob)
{
	int i, level;
	float exper;
	string family, clas, *sname;
	object cloth;
	mapping my, skill_status;

	my = ob->query_entire_dbase();
	if( undefinedp(my["balance"]) ) my["balance"] = 0;
	if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = 0;
	if( undefinedp(my["mud_age"]) ) my["mud_age"] = 0;
	if( undefinedp(my["food"]) ) my["food"] = 0;
	if( undefinedp(my["water"]) ) my["water"] = 0;
	if( my["balance"] > 10000000 ) my["balance"] = 10000000;
	if( my["balance"] > 100000 && my["combat_exp"] < 1000 )
		my["balance"] = 100000;
	if( my["mud_age"] < 3600 && my["food"] == 0 && my["water"] == 0) {
		my["food"] = ob->max_food_capacity();
		my["water"] = ob->max_water_capacity();
	}

	// Adjusts skill levels according to combat_exp.
	// Added exp check to prevent - exp
	// Qfy, May 8, 2000
	if ( my["combat_exp"] < 0 ) 
		my["combat_exp"] = 0;
	exper = to_float(my["combat_exp"]);

	if ( (skill_status = ob->query_skills()) ) {
           sname  = keys(skill_status);

	   for(i=0; i<sizeof(skill_status); i++) 
           {
                level = skill_status[sname[i]];
                if( pow(to_float(level), 3.0) / 10.0 > exper 
                && exper > 100.0
                && SKILL_D(sname[i])->type() != "knowledge" ) 
                {
                        level = ceil( pow( exper*10.0, 0.333333) );
                        ob->set_skill(sname[i], level);
                }
           }
	}

	ob->delete("rided");

	// General user data check

	if( undefinedp(my["shen"]) ) my["shen"] = 0;
	if( undefinedp(my["age"]) ) my["age"] = 14;
	if( undefinedp(my["behavior_exp"]) ) my["behavior_exp"] = my["shen"];
	if( undefinedp(my["quest_exp"]) ) my["quest_exp"] = my["age"]*10;
	if( undefinedp(my["potential"]) ) my["potential"] = 100;
	if( undefinedp(my["max_potential"]) ) my["max_potential"] = 100;
	if( my["potential"] > my["max_potential"] )
		my["potential"] = my["max_potential"];

	if( my["shen"] < 0 && -my["shen"] > my["combat_exp"] )
		my["shen"] = - my["combat_exp"];
	if( my["shen"] > 0 && my["shen"] > my["combat_exp"] )
		my["shen"] = my["combat_exp"];

	if( undefinedp(my["death_count"]) ) my["death_count"] = 0;
	if( undefinedp(my["death_times"]) ) my["death_times"] = 0;
	if( my["death_times"] > my["death_count"] ) 
		my["death_count"] = my["death_times"];
	if( undefinedp(my["jiajin"]) ) my["jiajin"] = 1;

	// Apply different clothes to different families

	family = ob->query("family/family_name");
	clas  = ob->query("class");

	if( family == "少林派" && clas == "bonze" ) {
		cloth = new("/d/shaolin/obj/seng-cloth");
		cloth->move(ob);
		cloth->wear();
	} else if( family == "峨嵋派" ) {
		if( ob->query("gender") == "女性" ) {
			cloth = new("/d/emei/obj/emei-shoes");
			cloth->move(ob);
			cloth->wear();
		}
		if(clas == "bonze" && ob->query("gender") == "女性" ) 
			cloth = new("/d/emei/obj/nun-cloth");
		else 	cloth = new("/d/emei/obj/hui-cloth");
		cloth->move(ob);
		cloth->wear();
	} else if( family == "武当派" && clas == "taoist" ) {
		cloth = new("/d/wudang/obj/greyrobe");
		cloth->move(ob);
		cloth->wear();
	} else if( family == "丐帮" ) {
		cloth = new("/d/gaibang/obj/budai");
		cloth->set_amount((int)ob->query("rank"));
		cloth->move(ob);
		cloth->wear();
	} else if( family == "星宿派" ) {
                cloth = new("/d/xingxiu/obj/yellow-cloth");
                cloth->move(ob);
                cloth->wear();
	} else if( family == "桃花岛" ) {
                cloth = new("/d/taohua/obj/robe");
                cloth->move(ob);
                cloth->wear();
	} else if( family == "白驼山" ) {
		cloth = new("/d/xingxiu/obj/wcloth");
                cloth->move(ob);
                cloth->wear();
	} else if( family == "雪山派" || family == "血刀门" && clas == "lama" ) {
                cloth = new("/d/qilian/obj/lamajiasha");
                cloth->move(ob);
                cloth->wear();
	} else {
		cloth = new("/clone/misc/cloth");
		cloth->move(ob);
		cloth->wear();
	}

	this_object()->inventory_check(ob);

}

// inventory_check called by natured for now.
int inventory_check(object ob)
{
	int i, amt;
	object *inv;
	
	if( objectp(ob) && interactive(ob) ) {
		inv = all_inventory(ob);
		if( ob->query("combat_exp") < 10000 ) {
			for(i=0; i<sizeof(inv); i++) {
				if(base_name(inv[i]) == GOLD_OB
				   && (amt = (int)inv[i]->query_amount()) > 50 ) {
					amt = 1+random(amt/2);
					tell_object(ob, "你突然发现身上少了"+
						chinese_number(amt) + "两黄金！肯定是遇到扒手了：（");
					inv[i]->add_amount(-amt);
					return 1;
				}
				if(inv[i]->is_unique()) {
					call_out("do_rumor", i+random(10), "看到有人鬼鬼祟祟地从"+
						ob->query("name") + "身上偷走了一" + 
						inv[i]->query("unit") + inv[i]->name() + "！");
					destruct(inv[i]);
					return 1;
				}
			}
		} 
		if( sizeof(inv) > 30 ) {
			i = random(sizeof(inv));
			tell_object(ob, "你突然发现身上少了一"+
					inv[i]->query("unit") + inv[i]->name() + "！不知道什么时候搞丢的：（");
			destruct(inv[i]);
			return 1;
		}
	}
	return 0;
}

private int do_rumor(string msg)
{
	object rum_ob;
	if( !objectp(rum_ob = find_object("/d/city/npc/aqingsao")) )
		rum_ob = load_object("/d/city/npc/aqingsao");
	return rum_ob->force_me("rumor* "+msg);
}
