//Cracked by Roath
inherit NPC;
#include "/d/beijing/npc/bjnpc.h"

void set_random_name();
void set_random_role();
void set_random_status();
void set_carried_items();
void set_inquiry();

mapping inq;

void create()
{

    // set_random_name();	// set_name
    set("gender", "男性");
    set("age", 20+random(40));
    set("attitude", "friendly");
    set_random_status(); // gifts, skills
    set_random_role();	// long, chat_msg
    set("chat_chance", 10);
    setup();
    inq = ([ "here" : "这儿就是京城啊，您瞧这城墙，别地儿有吗？" ]);
    set_carried_items();	// cloth etc
    set_inquiry();
    set("inquiry", inq);
}

// the talk messages
void set_inquiry()
{
    switch (query("role")) {
    case "bird":
	inq["鸟笼"] = "咱这鸟笼可是宫里梁公公给的。";
	inq["鸟"] = "咱这只金丝雀已经有两岁啦。";
	break;
    case "chess":
	inq["棋盘"] = "这有什么好问的？楚河汉界将士相车马炮兵。";
	inq["棋谱"] = "嘿嘿，象梅花谱什么的？咱可不管那一套。";
	break;
    case "arob":
	inq["枪法"]= "客官，咱这可是正宗的岳家枪法啊。";
	break;
    }
}

// cloth to wear etc, default is 布衣
void set_carried_items()
{
    switch (query("role")) {
    case "bird":
	carry_object("/clone/armor/changpao")->wear();
	break;
    default:
	carry_object("/clone/armor/cloth")->wear();
	break;
    }
}

// The definition of a role.
// make sure you have "role" set, so that other functions can know
// what kind of randomnpc we are dealing with.
// Fill in the long desc and random chat messages is enough.
void set_random_role()
{
    switch (random(8)) {
    case 0:
    case 1:
    case 2:
	set("role", "chess");
	set_name("下棋的", ({"xiaqi"}));
        set("long", "他是一个在街头找人下棋的闲人。\n");
	set("chat_msg", ({
	    name()+"叹了口气道：这年头，想找个人下棋都找不到。\n",
	    name()+"得意地笑道：您瞧我这手棋下得还不赖吧？来一盘？\n",
	    (: random_walk :),
 	}));
	break;
    case 3:
    case 4:
	set_name("溜鸟的", ({"liuniao"}));
	set("role", "bird");
        set("long", "他是一个在街头遛鸟的闲人。\n");
	set("chat_msg", ({
	    name()+"吹了个口哨，对着笼子里的小鸟眨了眨眼。\n",
	    name()+"晃了晃鸟笼道：该回家喽。\n",
	    (: random_walk :),
 	}));
	break;
    case 5:
	set_name("杂耍的", ({"zashua"}));
	set("role", "arob");
        set("long", "他是一个在街头耍枪卖艺的。\n");
	set("chat_msg", ({
	    name()+"大声叫道：小的给大爷们请安了，有钱的捧个钱场，有人的捧个人场！\n",
	    name()+"大声道：快来看啊，正总岳家枪传人哪。\n",
	    (: random_walk :),
 	}));
	break;
    case 6:
    case 7:
    default:
	set_name("八旗子弟", ({"baqi zidi", "baqi"}));
	set("role", "baqi");
        set("long", "这是一个八旗子弟，衣着华丽，整天游手好闲。\n");
	set("chat_msg", ({
	    name()+"嘟囔道：这天怎么还不下雨啊。\n",
	    name()+"眉飞色舞地说道：嘿，昨天晚秋楼那个热闹啊。\n",
	    (: random_walk :),
 	}));
	break;
    }
}

// Randomly sets some skill levels and combat_exp
void set_random_status()
{
    int lvl = random(40)+30;
    set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);

    set("max_qi",lvl*20);
    set("eff_qi",lvl*20);
    set("qi",lvl*20);

    set("max_jing",lvl*15);
    set("eff_jing",lvl*15);
    set("jing",lvl*15);

    set("jingli", lvl*20);
    set("max_jingli",lvl*20);
    set("neili", lvl*20);
    set("max_neili",lvl*20);

    set("shen_type",1);
    set("combat_exp", lvl*lvl/5*lvl);

    set_skill("force", lvl);
    set_skill("dodge", lvl);
    set_skill("parry", lvl);
}

// set a random name 
void set_random_name()
{
    mixed lastnamelist=({
    ({"赵", "zhao"}), ({"钱", "qian"}),  ({"孙", "sun"}),   ({"李", "li"}),    
    ({"周", "zhou"}), ({"吴", "wu"}),    ({"郑", "zheng"}), ({"王", "wang"}), 
    ({"冯", "feng"}), ({"陈", "chen"}),  ({"卫", "wei"}),   ({"高", "gao"}),   
    ({"云", "yun"}),  ({"张", "zhang"}), ({"刘", "liu"}),   ({"马", "ma"}),
    });

    mixed middlenamelist=({
    ({"青", "qing"}), ({"宝", "bao"}),  ({"忠", "zhong"}), ({"诚", "cheng"}),
    ({"继", "ji"}),   ({"碧", "bi"}),   ({"金", "jin"}),   ({"仁", "ren"}),
    ({"伯", "bo"}),   ({"如", "ru"}),   ({"银", "yin"}),   ({"汉", "han"}),
    });

    mixed firstnamelist=({
    ({"年", "nian"}), ({"山", "shan"}),  ({"水", "shui"}), ({"天", "tian"}),
    ({"田", "tian"}), ({"光", "guang"}), ({"谷", "gu"}),   ({"海", "hai"}),
    ({"文", "wen"}),  ({"武", "wu"}),    ({"之", "zhi"}),  ({"迪", "di"}),
    });

    string l_c, l_e, f_c, f_e, m_c, m_e;
    int i;

    i = random(sizeof(lastnamelist));
    l_c = lastnamelist[i][0];
    l_e = lastnamelist[i][1];

    i = random(sizeof(middlenamelist));
    m_c = middlenamelist[i][0];
    m_e = middlenamelist[i][1];

    i = random(sizeof(firstnamelist));
    f_c = firstnamelist[i][0];
    f_e = firstnamelist[i][1];

    set_name(l_c+m_c+f_c, ({l_e+" "+m_e+f_e, l_e}));
}
