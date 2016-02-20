//Cracked by Roath
// chu, 3/8/99
#include <ansi.h>

inherit NPC;

string ask_qianzhu();
string ask_he();
string ask_lian();

string *qianzhu_message = ({
    "千蛛万毒手虽是一门毒功, 其实它包括指法, 内功, 轻功, 招架在内, 一通百通。\n",
    "练千蛛万毒手极为费时费力, 非穷毕生之力不可。\n",
    "千蛛万毒手练起来极为枯燥, 要不是为了报仇, 我才不练呢。\n",
    "千蛛万毒手入门容易, 可越到后来越难练, 我也不过练了百来只花蛛而已。\n",
    "修练千蛛万毒手时凶险万分, 非有一定的内力为基础不可。\n",
    "江湖人物只知道打打杀杀, 实战经验虽丰富, 可又怎么奈何得了我的千蛛万毒手?\n",
    "咱们练千蛛万毒手的, 只求毒功深湛, 跟实战经验倒没什么关系。\n",
    "千蛛万毒手一旦施展, 无药可救, 只有中毒者自己靠深厚的内力化解。\n",
    "千蛛万毒手乃是我的家传武功, 虽说没什么名气, 可等我练成了, 连张无忌怕也挡不住我一指。\n",
    "练了千蛛万毒手以后容貌尽毁, 那是不必说了。\n",
    "要说功夫深哪, 练个几千只花蛛也不算多。\n",
    "等练到几百只毒蜘蛛以后，突袭(tuxi)敌人的效果可就利害了。\n",
});

void create()
{
        set_name("殷离", ({ "yin li", "yin", "li" }) );
        set("age", 18);
        set("gender", "女性");
  
        set("long", "这是个十七八岁的少女，荆钗布裙，面容黝黑，脸上肌肤浮肿，\n"
	"凹凹凸凸，生得极是丑陋，只是一对眸子颇有神采，身材也是苗条纤秀。\n");
        set("attitude", "peaceful");

        set("combat_exp", 1800000);
        set("shen", -1000000);
	set_skill("qianzhu-wandu", 250);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("finger", 100);
  	map_skill("force", "qianzhu-wandu");
  	map_skill("dodge", "qianzhu-wandu");
  	map_skill("parry", "qianzhu-wandu");
  	map_skill("finger", "qianzhu-wandu");
  	prepare_skill("finger", "qianzhu-wandu");

	set("max_neili", 2000);
	set("neili", 2000);
	set("eff_qi", 1000);
	set("max_qi", 1000);
	set("qi", 1000);
	set("max_jing", 1000);
	set("eff_jing", 1000);
	set("jing", 1000);
	set("max_jingli", 1000);
	set("eff_jingli", 1000);
	set("jingli", 1000);

	set("inquiry", ([
	    "千蛛万毒手" : (: ask_qianzhu :),
	    "报仇" : "哼, 我要叫天下负心薄辛的男子个个不得好死。\n",
	    "殷野王" : "他是我爹。\n",
	    "殷天正" : "他是我爷爷。\n",
	    "殷素素" : "他是我姑姑。\n",
	    "金花婆婆" : "唉, 婆婆去波斯啦。\n",
	    "银叶先生" : "银叶先生我也没见过。\n",
	    "胡青牛" : "哼, 这个臭医生, 要不是他, 银叶先生也不会死。\n",
	    "王难姑" : "嗯, 难姑的毒技是极高的, 可我的千蛛万毒手却也另有一功。\n",
	    "周芷若" : "小姑娘人长的漂亮, 可心眼不怎么好。\n",
	    "赵敏" : "赵姑娘心机敏捷, 令人佩服。\n",
	    "张无忌" : "这没良心的、狠心短命的死鬼, 我到处都找不到他。\n",
	    "锦盒" : (: ask_he :),
	    "怎么练，才。。快？！" : (: ask_lian :)
	]));
        setup();
}

string ask_qianzhu() {
    object he, player = this_player(), me=this_object();
    int flags, level, idx;

    if (player->is_busy()) {
	if (player->query_busy() < 5) player->start_busy(5);
	return "刚问完又来，你有没有听懂我说的啊？\n";
    }

    flags = player->query_temp("qianzhu-wandu/flags");
    level = player->query_skill("qianzhu-wandu", 1);

    if (flags >= 1023 && level < 10) {
	command("say 好吧, 看你这么诚心, 我就教你这门功夫吧。\n");
        player->set_skill("qianzhu-wandu", 10);
	message_vision("$N指点了$n一些基本的千蛛万毒手。\n", me, player);
	he = new ("/d/qilian/obj/jinhe");
        he->move(player);
        message_vision("$N给$n一个锦盒。\n", me, player);
        return "师傅领进门, 修行看各人, 今后就你自己练啦。\n";
    }else {
	player->start_busy(1+random(3));
        idx = random(sizeof(qianzhu_message));
	if (idx < 10) {
	    flags = flags | (1 << idx);
   	}
	player->set_temp("qianzhu-wandu/flags", flags);
	return qianzhu_message[idx];
    }
}

string ask_lian() {
    object player=this_player();
    int    checking, times;

    log_file("qianzhu-wandu", sprintf("%s: %s(%s) asked for bug\n",
				      ctime(time()), player->name(1),
					geteuid(player)));
    return 0;
    checking = player->query("qianzhu-wandu/checking");
    times = player->query_temp("qianzhu-wandu/ask_times");

    if (times < 100-checking) {
	times++;
	player->set_temp("qianzhu-wandu/ask_times", times);
	return 0;
    }
    checking ++;
    player->set("qianzhu-wandu/checking", checking);
    player->set_temp("qianzhu-wandu/ask_times", 0);
    return "世上无难事，只怕有心人。\n";
}

string ask_he() {
    object player=this_player();
    object he;

    if (player->query_skill("qianzhu-wandu", 1) < 10) {
	return "你我素不相识, 问来也不冒昧么？\n";
    }

    if (objectp(present("jin he", player))) {
	return "你找个偏僻的所在, 抓一只毒蜘蛛, 自己就可以修练啦。\n";
    }
    he = new ("/d/qilian/obj/jinhe");
    he->move(player);
    message_vision("$N给$n一个锦盒。\n", this_object(), player);
    return "怎么这么不小心, 好吧, 我再给你一个。\n";
}

