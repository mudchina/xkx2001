//Cracked by Roath
void set_random_name()
{
    string l_c, l_e, f_c, f_e;
    int    i, j;
 
    i = random(sizeof(lastnamelist));
    j = random(sizeof(firstnamelist));
 
    l_c = lastnamelist[i][0];
    l_e = lastnamelist[i][1];
    f_c = firstnamelist[j][0];
    f_e = firstnamelist[j][1];
 
    set_name(l_c+f_c, ({ l_e+ " " + f_e, l_e, }));
    set("id_long", l_e + " " + f_e);
    set("id_short", l_e);
}

void set_hp(int level) {
    set("max_neili", level*12);
    set("neili", level*12);
    set("eff_jingli", level*10);
    set("max_jingli", level*10);
    set("jingli", level*10);
    set("max_qi", level*12);
    set("eff_qi", level*12);
    set("qi", level*12);
    set("max_jing", level*10);
    set("eff_jing", level*10);
    set("jing", level*10);
    set("jiali", level/2);
}

string set_skills(string menpai, int exp, int skill_rate)
{
    int level;

    if (exp < 0 || skill_rate < 0) return;
    level = pow(10*exp, 0.333334);
    level = level*skill_rate/100;
    if (level < 20) level = 20;
    if (!stringp(menpai)) 
	menpai = menpai_list[random(sizeof(menpai_list))];

    set("combat_exp", exp);
    set_skill("force", level);
    set_skill("dodge", level);
    set_skill("parry", level);
    set_skill("sword", level);
    set_skill("blade", level);
    set_skill("strike", level);
    set_skill("cuff", level);
    set_skill("finger", level);
    set_skill("claw", level);
    set_skill("club", level);
    set_skill("kick", level);
    set_skill("staff", level);
    set_skill("whip", level);

    switch (menpai){
    case "huashan":
        set_skill("huashan-jianfa", level);
        set_skill("liangyi-dao", level);
        set_skill("huashan-shenfa", level);
        set_skill("zixia-gong", level);
	set_skill("pishi-poyu", level);
	set_skill("hunyuan-zhang", level);
 
        map_skill("force", "zixia-gong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
	map_skill("cuff", "pishi-poyu");
        map_skill("sword", "huashan-jianfa");
        map_skill("blade", "liangyi-dao");
        
        prepare_skill("cuff", "pishi-poyu");
        prepare_skill("strike", "hunyuan-zhang");
	
	set("default_weapon", "/clone/weapon/gangjian");

	break;
    case "emei":
	set_skill("huifeng-jian", level);
	set_skill("yanxing-dao", level);
	set_skill("jinding-zhang", level);
	set_skill("tiangang-zhi", level);
	set_skill("linji-zhuang", level);
	set_skill("zhutian-bu", level);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("strike", "jinding-zhang");
	map_skill("finger", "tiangang-zhi");
	map_skill("dodge", "zhutian-bu");
	map_skill("parry", "huifeng-jian");

        prepare_skill("finger", "tiangang-zhi");
        prepare_skill("strike", "jinding-zhang");
	set("default_weapon", "/clone/weapon/gangdao");
	break;
    case "wudang":
        set_skill("taiji-shengong", level);
        set_skill("taiji-jian", level);
        set_skill("tiyunzong", level);
	set_skill("taiji-quan", level);
 
        map_skill("force", "taiji-shengong");
        map_skill("parry", "taiji-jian");
	map_skill("cuff", "taiji-quan");
        map_skill("dodge", "tiyunzong");
        map_skill("sword", "taiji-jian");
        
        prepare_skill("cuff", "taiji-quan");
	set("default_weapon", "/clone/weapon/gangjian");
	break;
    case "shaolin":
        set_skill("damo-jian", level);
        set_skill("xiuluo-dao", level);
        set_skill("wuchang-zhang", level);
        set_skill("zui-gun", level);
        set_skill("shaolin-shenfa", level);
        set_skill("hunyuan-yiqi", level);
	set_skill("yizhi-chan", level);
	set_skill("banruo-zhang", level);
 
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "damo-jian");
        map_skill("sword", "damo-jian");
        map_skill("blade", "xiuluo-dao");
        map_skill("club", "zui-gun");
        map_skill("staff", "wuchang-zhang");
        map_skill("finger", "yizhi-chan");
        map_skill("strike", "banruo-zhang");
        
        prepare_skill("finger", "yizhi-chan");
        prepare_skill("strike", "banruo-zhang");
	set("default_weapon", "/clone/weapon/gangjian");
	break;

    case "gaibang":
        set_skill("liuhe-dao", level);
        set_skill("xiaoyaoyou", level);
        set_skill("huntian-qigong", level);
	set_skill("shexing-diaoshou", level);
 
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-dao");
        map_skill("blade", "liuhe-dao");
        map_skill("hand", "shexing-diaoshou");
        
        prepare_skill("hand", "shexing-diaoshou");
	set("default_weapon", "/clone/weapon/gangdao");
	break;
    case "baituo":
        set_skill("hamagong", level);
        set_skill("lingshe-zhang", level);
	set_skill("chanchubu", level);
	set_skill("poison", level);
 
        map_skill("force", "hamagong");
        map_skill("dodge", "chanchubu");
        map_skill("parry", "lingshe-zhang");
        map_skill("strike", "hamagong");
        map_skill("staff", "lingshe-zhang");
        
        prepare_skill("strike", "hamagong");
	set("default_weapon", "/clone/weapon/shezhang");
	break;

    case "taohua":
        set_skill("bitao-xuangong", level);
        set_skill("canglang-bian", level);
        set_skill("luoying-shenfa", level);
	set_skill("luoying-shenjian", level);
	set_skill("xuanfeng-saoye", level);
	set_skill("qimen-dunjia", level);
 
        map_skill("force", "bitao-xuangong");
        map_skill("dodge", "luoying-shenfa");
        map_skill("parry", "canglang-bian");
        map_skill("strike", "luoying-shenjian");
        map_skill("kick", "xuanfeng-saoye");
        map_skill("whip", "canglang-bian");
        
        prepare_skill("strike", "luoying-shenjian");
        prepare_skill("kick", "xuanfeng-saoye");
	set("default_weapon", "/clone/weapon/changbian");
	break;

    case "xueshan":
        set_skill("longxiang-banruo", level);
        set_skill("xue-dao", level);
        set_skill("jingang-chu", level);
	set_skill("huoyan-dao", level);
	set_skill("xueshitiao", level);
	set_skill("mingwang-jian", level);
 
        map_skill("force", "longxiang-banruo");
        map_skill("dodge", "xueshitiao");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("strike", "huoyan-dao");
        map_skill("staff", "jingang-chu");
        
        prepare_skill("strike", "huoyan-dao");
	set("default_weapon", "/clone/weapon/gangdao");
	break;

    case "xingxiu":
    default:
        set_skill("huagong-dafa", level);
        set_skill("zhaixinggong", level);
        set_skill("chousui-zhang", level);
        set_skill("sanyin-zhua", level);
        set_skill("tianshan-zhang", level);
        set_skill("poison", level);

	map_skill("force", "huagong-dafa");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-zhua");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "sanyin-zhua");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-zhua");
	set("default_weapon", "/clone/weapon/gangzhang");
	break;
    }
    return menpai;
}
