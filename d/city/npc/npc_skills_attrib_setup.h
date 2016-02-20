//Cracked by Roath
//npc_setup.h
//wzfeng 2000 7
void Set_Npcattrib(int Basic_Attrib,int Random_var,
				   int Maxqi,int Random_Maxqi,
				   int Maxjing,int Random_Maxjing,
				   int Maxjingli,int Random_Maxjingli,
				   int Maxneili,int Random_Maxneili,
				   int Exp,int Random_Exp)
				  				  
{
	int Mneili=Maxneili+random(Random_Maxneili),max;
	set("str", Basic_Attrib+random(Random_var));
	set("int", Basic_Attrib+random(Random_var));
	set("con", Basic_Attrib+random(Random_var));
	set("dex", Basic_Attrib+random(Random_var));

	set("max_qi", Maxqi+random(Random_Maxqi));
	set("max_jing", Maxjing+random(Random_Maxjing));
	set("max_jingli", Maxjingli+random(Random_Maxjingli));
	set("max_neili", Mneili);
	set("combat_exp", Exp+random(Random_Exp));
	
	  max =query("max_jing");
	  set("eff_jing",max);
	  set("jing",max);
	  max = query("max_qi");
	  set("eff_qi",max);
	  set("qi",max);
	  max =query("max_neili");
	  set("eff_neili",max);
	  set("neili",max);
	  max = query("max_jingli");
	  set("eff_jingli",max);
	  set("jingli",max);
	return;
}

void Set_Npcskills(int Basic_skill,int Random_skill,mapping S_skills)
{
	int i,jiali ;
	mixed S_name;
	
	if(i=sizeof(S_skills))
	{
		S_name=keys(S_skills);
		for(i=0;i<sizeof(S_name);i++)
		{
			set_skill(S_name[i], Basic_skill+random(Random_skill) );
			set_skill(S_skills[S_name[i]], Basic_skill+random(Random_skill) );
			map_skill(S_name[i],S_skills[S_name[i]]);
		}
	}
	set_skill("literate", Basic_skill+random(Random_skill));
	jiali=(Basic_skill+Basic_skill/2)/2;
	set("jiali",jiali);
	return;
}
//kind choose weapon or no weapon (=1 menas weapon.skill is skills lvl. r_s is random add skills rate
//family is which family skills that npc would use it.
void skills_setup_none(int skill,int r_s,string family)
{
	//object weapon;
	mapping S_skills= ([ ]);
	switch(family)
	{
		case "武当派":
		{
			S_skills["dodge"]="tiyunzong";
			S_skills["parry"]="taiji-quan";
			S_skills["force"]="taiji-shengong";
			S_skills["cuff"]="taiji-quan";
			S_skills["sword"]="taiji-jian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("cuff","taiji-quan");
			set("chat_msg_combat", ({
						(: perform_action, "cuff.luanhuan" :),
						(: perform_action, "cuff.nian" :)

						}));
			carry_object("/d/wudang/obj/greyrobe")->wear();
			break;
		}
		case "星宿派":
		{
			S_skills["dodge"]="feixing-shu";
			S_skills["parry"]="chousui-zhang";
			S_skills["force"]="huagong-dafa";
			S_skills["claw"]="sanyin-zhua";
			S_skills["strike"]="chousui-zhang";
			S_skills["staff"]="tianshan-zhang";
			set_skill("poison",skill+random(r_s));
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("claw","sanyin-zhua");
			prepare_skill("strike","chousui-zhang");
			set("chat_msg_combat", ({
				(: perform_action, "claw.sanyin" :)
				}));
			carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
			break;
			}
		case "华山派":
		{
			S_skills["dodge"]="huashan-shenfa";
			S_skills["parry"]="pishi-poyu";
			S_skills["force"]="zixia-gong";
			S_skills["strike"]="hunyuan-zhang";
			S_skills["cuff"]="pishi-poyu";
			S_skills["sword"]="huashan-jianfa";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("cuff","pishi-poyu");
		prepare_skill("strike","hunyuan-zhang");
		set("chat_msg_combat", ({
					(: perform_action, "strike.leidong" :)

						
			}));
		carry_object("/d/city/obj/cloth")->wear();
		break;

			}
		case "桃花岛":
		{
		S_skills["dodge"]="luoying-shenfa";
			S_skills["parry"]="luoying-shenjian";
			S_skills["force"]="bitao-xuangong";
			S_skills["strike"]="luoying-shenjian";
			S_skills["kick"]="xuanfeng-saoye";
			S_skills["sword"]="yuxiao-jian";
			
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("strike","luoying-shenjian");
		prepare_skill("kick","xuanfeng-saoye");
		 set("chat_msg_combat", ({
					(: perform_action, "strike.kuangfeng" :)
			}));
		carry_object("/d/city/obj/cloth")->wear();
		break;

			}
		case "丐帮":
		{
		S_skills["dodge"]="xiaoyaoyou";
		S_skills["parry"]="xianglong-zhang";
		S_skills["force"]="huntian-qigong";
		S_skills["strike"]="xianglong-zhang";
		S_skills["stick"]="dagou-bang";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("strike","xianglong-zhang");
		set("chat_msg_combat", ({
				(: perform_action, "strike.leiting" :)
		}));
		carry_object("/d/gaibang/obj/budai")->set_amount(9);
		carry_object("/d/gaibang/obj/budai")->wear();
		break;
			}
		case "峨嵋派":
		{
			S_skills["dodge"]="zhutian-bu";
			S_skills["parry"]="tiangang-zhi";
			S_skills["force"]="linji-zhuang";
			S_skills["strike"]="jinding-zhang";
			S_skills["finger"]="tiangang-zhi";
			S_skills["sword"]="emei-jian";
			
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("finger","tiangang-zhi");
		prepare_skill("strike","jinding-zhang");
			set("chat_msg_combat", ({
					(: perform_action, "strike.puzhao" :)

			}));
		carry_object("/d/city/obj/cloth")->wear();
		break;

			}
		case "白驼山":
		{
		S_skills["dodge"]="chanchubu";
		S_skills["parry"]="hamagong";
		S_skills["force"]="hamagong";
		S_skills["strike"]="hamagong";
		S_skills["cuff"]="lingshe-quan";
		S_skills["staff"]="lingshe-zhang";
		set_skill("poison",skill+random(r_s));
		
	Set_Npcskills(skill,r_s,S_skills);
	prepare_skill("strike","hamagong");
	set("chat_msg_combat", ({
				(: perform_action, "strike.puji" :)

		}));
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}

		case "全真教":
		{
			S_skills["dodge"]="jinyangong";
			S_skills["parry"]="sanhua-juding";
			S_skills["force"]="xiantian-gong";
			S_skills["strike"]="sanhua-juding";
			S_skills["cuff"]="chunyang-quan";
			S_skills["sword"]="quanzhen-jian";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("cuff","chunyang-quan");
		prepare_skill("strike","sanhua-juding");

			set("chat_msg_combat", ({
					(: perform_action, "cuff.lianhuan" :),
						(: perform_action, "strike.sanhua" :)
						


			}));
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}
		case "雪山派":
		{
			S_skills["dodge"]="shenkongxing";
		S_skills["parry"]="huoyan-dao";
		S_skills["force"]="longxiang-banruo";
		S_skills["strike"]="huoyan-dao";
		S_skills["hammer"]="riyue-lun";


		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("strike","huoyan-dao");
		set("chat_msg_combat", ({
				(: perform_action, "strike.fen" :),

		}));

		carry_object("/d/qilian/obj/lamajiasha")->wear();
		break;

			}
		case "大理段家":
		{
			S_skills["dodge"]="duanshi-shenfa";
			S_skills["parry"]="yiyang-zhi";
			S_skills["force"]="kurong-changong";
			S_skills["strike"]="qingyan-zhang";
			S_skills["finger"]="yiyang-zhi";
			S_skills["sword"]="duanjia-jian";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("finger","yiyang-zhi");

			set("chat_msg_combat", ({
					(: perform_action, "finger.qiankun" :),
						(: perform_action, "finger.yiyang" :)

			}));
			carry_object("/d/wudang/obj/greyrobe")->wear();
			break;
			}
			case "少林派":
		{
			S_skills["dodge"]="shaolin-shenfa";
			S_skills["parry"]="yizhi-chan";
			S_skills["force"]="hunyuan-yiqi";
			S_skills["strike"]="banruo-zhang";
			S_skills["finger"]="yizhi-chan";
			S_skills["whip"]="riyue-bian";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("finger","yizhi-chan");
		prepare_skill("strike","banruo-zhang");

			set("chat_msg_combat", ({
					(: perform_action, "finger.jingmo" :),

						(: perform_action, "strike.san" :)

			}));
			carry_object("/d/wudang/obj/greyrobe")->wear();
			break;
			}

	}

	
}

void skills_setup_weapon(int skill,int r_s,string family)
{
	//object weapon;
	mapping S_skills= ([ ]);

	switch(family)
	{
		case "武当派":
		{
			S_skills["dodge"]="tiyunzong";
			S_skills["parry"]="taiji-quan";
			S_skills["force"]="taiji-shengong";
			S_skills["cuff"]="taiji-quan";
			S_skills["sword"]="taiji-jian";
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("cuff","taiji-quan");
			set("chat_msg_combat", ({
						(: perform_action, "sword.chan" :)
						}));
			carry_object("/clone/weapon/gangjian")->wield();
			carry_object("/d/wudang/obj/greyrobe")->wear();
			break;
		}
		case "星宿派":
		{
			S_skills["dodge"]="feixing-shu";
			S_skills["parry"]="chousui-zhang";
			S_skills["force"]="huagong-dafa";
			S_skills["claw"]="sanyin-zhua";
			S_skills["strike"]="chousui-zhang";
			S_skills["staff"]="tianshan-zhang";
			set_skill("poison",skill+random(r_s));
			Set_Npcskills(skill,r_s,S_skills);
			prepare_skill("claw","sanyin-zhua");
			prepare_skill("strike","chousui-zhang");
			set("chat_msg_combat", ({
					(: perform_action, "staff.jinxian" :)
				}));
			carry_object("/clone/weapon/gangzhang")->wield();
			carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
			break;
			}
		case "华山派":
		{
			S_skills["dodge"]="huashan-shenfa";
			S_skills["parry"]="pishi-poyu";
			S_skills["force"]="zixia-gong";
			S_skills["strike"]="hunyuan-zhang";
			S_skills["cuff"]="pishi-poyu";
			S_skills["sword"]="huashan-jianfa";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("cuff","pishi-poyu");
		prepare_skill("strike","hunyuan-zhang");
		set("chat_msg_combat", ({
						(: perform_action, "sword.jianzhang" :)
						
			}));
		carry_object("/clone/weapon/gangjian")->wield();
		carry_object("/d/city/obj/cloth")->wear();
		break;

			}
		case "桃花岛":
		{
		S_skills["dodge"]="luoying-shenfa";
			S_skills["parry"]="luoying-shenjian";
			S_skills["force"]="bitao-xuangong";
			S_skills["strike"]="luoying-shenjian";
			S_skills["kick"]="xuanfeng-saoye";
			S_skills["sword"]="yuxiao-jian";
			
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("strike","luoying-shenjian");
		prepare_skill("kick","xuanfeng-saoye");
		 set("chat_msg_combat", ({
						(: perform_action, "sword.jianmang" :),
						(: perform_action, "sword.jianzhi" :),
						(: perform_action, "sword.jinglei" :),
						(: perform_action, "sword.jm" :)
			}));
		carry_object("/clone/weapon/tiexiao")->wield();
		carry_object("/d/city/obj/cloth")->wear();
		break;

			}
		case "丐帮":
		{
		S_skills["dodge"]="xiaoyaoyou";
		S_skills["parry"]="xianglong-zhang";
		S_skills["force"]="huntian-qigong";
		S_skills["strike"]="xianglong-zhang";
		S_skills["stick"]="dagou-bang";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("strike","xianglong-zhang");
		set("chat_msg_combat", ({
					(: perform_action, "strike.sanhui" :),
					(: perform_action, "stick.chan" :),
					(: perform_action, "stick.feng" :),
					(: perform_action, "stick.sansha" :),
					(: perform_action, "stick.ban" :),
					(: perform_action, "stick.zhuan" :)
		}));
		carry_object("/clone/weapon/zhubang")->wield();
		carry_object("/d/gaibang/obj/budai")->set_amount(9);
		carry_object("/d/gaibang/obj/budai")->wear();
		break;
			}
		case "峨嵋派":
		{
			S_skills["dodge"]="zhutian-bu";
			S_skills["parry"]="tiangang-zhi";
			S_skills["force"]="linji-zhuang";
			S_skills["strike"]="jinding-zhang";
			S_skills["finger"]="tiangang-zhi";
			S_skills["sword"]="emei-jian";
			
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("finger","tiangang-zhi");
		prepare_skill("strike","jinding-zhang");
			set("chat_msg_combat", ({
						(: perform_action, "sword.mie" :),
						(: perform_action, "sword.jue" :)

			}));
		carry_object("/clone/weapon/gangjian")->wield();
		carry_object("/d/city/obj/cloth")->wear();
		break;

			}
		case "白驼山":
		{
		S_skills["dodge"]="chanchubu";
		S_skills["parry"]="hamagong";
		S_skills["force"]="hamagong";
		S_skills["strike"]="hamagong";
		S_skills["cuff"]="lingshe-quan";
		S_skills["staff"]="lingshe-zhang";
		set_skill("poison",skill+random(r_s));
		
	Set_Npcskills(skill,r_s,S_skills);
	prepare_skill("strike","hamagong");
	set("chat_msg_combat", ({
					(: perform_action, "staff.bite" :),
					(: perform_action, "staff.shoot" :)

		}));
			carry_object("/clone/weapon/gangzhang")->wield();
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}

		case "全真教":
		{
			S_skills["dodge"]="jinyangong";
			S_skills["parry"]="sanhua-juding";
			S_skills["force"]="xiantian-gong";
			S_skills["strike"]="sanhua-juding";
			S_skills["cuff"]="chunyang-quan";
			S_skills["sword"]="quanzhen-jian";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("cuff","chunyang-quan");
		prepare_skill("strike","sanhua-juding");

			set("chat_msg_combat", ({
						(: perform_action, "sword.sanqing" :)
						


			}));
			carry_object("/clone/weapon/gangjian")->wield();
			carry_object("/d/city/obj/cloth")->wear();
			break;

			}
		case "雪山派":
		{
			S_skills["dodge"]="shenkongxing";
		S_skills["parry"]="huoyan-dao";
		S_skills["force"]="longxiang-banruo";
		S_skills["strike"]="huoyan-dao";
		S_skills["hammer"]="riyue-lun";


		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("strike","huoyan-dao");
		set("chat_msg_combat", ({
					(: perform_action, "hammer.riyue" :),
		}));

		carry_object("/d/qilian/obj/lamajiasha")->wear();
		carry_object("/clone/weapon/falun")->set_amount(4);
		carry_object("/clone/weapon/falun")->wield();

		break;

			}
		case "大理段家":
		{
			S_skills["dodge"]="duanshi-shenfa";
			S_skills["parry"]="yiyang-zhi";
			S_skills["force"]="kurong-changong";
			S_skills["strike"]="qingyan-zhang";
			S_skills["finger"]="yiyang-zhi";
			S_skills["sword"]="duanjia-jian";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("finger","yiyang-zhi");

			set("chat_msg_combat", ({
						(: perform_action, "sword.ailao" :)

			}));
			carry_object("/clone/weapon/gangjian")->wield();
			carry_object("/d/wudang/obj/greyrobe")->wear();
			break;
			}
			case "少林派":
		{
			S_skills["dodge"]="shaolin-shenfa";
			S_skills["parry"]="yizhi-chan";
			S_skills["force"]="hunyuan-yiqi";
			S_skills["strike"]="banruo-zhang";
			S_skills["finger"]="yizhi-chan";
			S_skills["whip"]="riyue-bian";
		Set_Npcskills(skill,r_s,S_skills);
		prepare_skill("finger","yizhi-chan");
		prepare_skill("strike","banruo-zhang");

			set("chat_msg_combat", ({
						(: perform_action, "whip.chanrao" :),

			}));
			carry_object("/clone/weapon/changbian")->wield();
			carry_object("/d/wudang/obj/greyrobe")->wear();
			break;
			}

	}

	
}

