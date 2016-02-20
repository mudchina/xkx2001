//Cracked by Roath

inherit NPC;
string ask_job();
string ask_suicong();
string ask_yaopai();
int do_ling(string);

#include "/d/beijing/beijing_defs.h"
#include "/d/beijing/job_info.h"
void set_shiwei_status(int);

void create()
{
    set_name("多隆", ({
	    "duolong", "duo",
    }));
    set("title", "侍卫总管");
    set("long",
	"作为侍卫总管，多隆深受皇上器重。\n"
	"御林军的任务都从他这里分派。\n"
    );


    set("gender", "男性");
    set("age", 35);
    setup();

    set_shiwei_status(180);

    set("inquiry", ([
	"job" : (: ask_job :),
	"任务" : (: ask_job :),
	"晋升" : "这个你到兵部去问米尚书吧。",
	"promote" : "这个你到兵部去问米尚书吧。",
	"升官" : "这个你到兵部去问米尚书吧。",
	"随从" : (: ask_suicong :),
	"suicong" : (: ask_suicong :),
	"here" : "这里是侍卫营。不得喧哗。",
	"腰牌" : (: ask_yaopai :),
	"yaopai" : (: ask_yaopai :),
    ]));
}

void init()
{
    add_action("do_ling", "ling");
}

int sync_mizheng(object player)
{
    object mizheng;

    // fix test players
    mizheng = HELPER->find_mizheng();
    if (mizheng->player_rank(player->query("id")) == -1) {
	message_vision("$N疑惑的看了$n一眼，你怎么会有侍卫头衔的？\n",
	    this_object(), player);
	mizheng->normalize(player);
        return 1;
    }
    return 0;
}

string ask_yaopai ()
{
    object player = this_player(), me = this_object();
    object *inv, yaopai;
    int i;

    if (! IS_SHIWEI(player)) 
	return "你又不是侍卫，要什么腰牌？";

    if (sync_mizheng(player)) return "你重新到米尚书那儿去登记吧。";

    inv = all_inventory(player);
    for (i=0; i<sizeof(inv)-1; i++){
	if (base_name(inv[i]) == "/d/beijing/obj/yaopai") 
	    return "你不是有腰牌了吗？";
    }
    yaopai = new ("/d/beijing/obj/yaopai");
    yaopai->move(player);
    message_vision("$N给$n一面侍卫腰牌。\n", me, player);
    return "小心点，别老搞丢了。";
}

string ask_job()
{
    object player = this_player(), me = this_object();
    int i, shichen=HELPER->shichen();

    if (!IS_SHIWEI(player)) 
        return "你先到兵部投军吧。";
    if (sync_mizheng(player)) return "你重新到米尚书那儿去登记吧。";

    if (player->query_temp("current_job")) {
	if (SHIWEI_LEVEL(player)<4) {
	    return "我不是告诉你了吗？去"+
		    player->query_temp("current_job")+"守门吧。";
	}
  	return "我不是告诉你了吗?";
    }

    switch (SHIWEI_LEVEL(player)) {
    case 0:	// first level
	if (HELPER->is_sunrise() < 0) 
	    return "现在还没到你当班的时间呢。";
	if (HELPER->is_sunrise() > 0) 
	    return "点名过卯的时间已经过了，你明天再来吧。";
	i = random(sizeof(outer_gate_name));
	player->set_temp("current_job", outer_gate_name[i]);
	return "你快去"+outer_gate_name[i]+"守门 (guard) 吧。";
    case 1:	// second level
	if (HELPER->is_sunset() < 0) 
	    return "天还亮着呢，等会儿就有你的戏啦。";
	if (HELPER->is_sunset() > 0) 
	    return "天都黑了你才来，明天再说吧。";
	i = random(sizeof(outer_gate_name));
	player->set_temp("current_job", outer_gate_name[i]);
	return "你快去"+outer_gate_name[i]+"守门 (guard) 吧。";
    case 2:	// third level
	if (HELPER->is_sunrise() < 0) 
	return "现在还没到你当班的时间呢。";
	if (HELPER->is_sunrise() > 0) 
	    return "点名过卯的时间已经过了，你明天再来吧。";
	i = random(sizeof(inner_gate_name));
	player->set_temp("current_job", inner_gate_name[i]);
	return "你快去"+inner_gate_name[i]+"守门 (guard) 吧。";
    case 3:	// fourth level
	if (HELPER->is_sunset() < 0) 
	    return "天还亮着呢，等会儿就有你的戏啦。";
	if (HELPER->is_sunset() > 0) 
	    return "天都黑了你才来，明天再说吧。";
	i = random(sizeof(inner_gate_name));
	player->set_temp("current_job", inner_gate_name[i]);
	return "你快去"+inner_gate_name[i]+"守门 (guard) 吧。";
    default:
	return "现在没有你的任务。";
    }
}

string ask_suicong()
{
    return "随从只有"+HELPER->rank_name(3)+"以上的侍卫才有。\n"+
	"要想领(ling)随从呢，就在我这里。各个门派的都有，你自己挑吧。\n";
}

int do_ling(string menpai)
{
    object player = this_player();
    object me = this_object(), suicong;
    int rank = SHIWEI_LEVEL(player);
    int suicong_num = player->query("suicong_num");
    string cmenpai;

    if (! IS_SHIWEI(player))
	return notify_fail("你先去兵部投军吧。\n");
    if (sync_mizheng(player)) 
	return notify_fail("你重新到米尚书那儿去登记吧。\n");
    if (HELPER->suicong_max(rank) == 0) 
	return notify_fail("你的级别不够领随从的。\n");
    if (suicong_num >= HELPER->suicong_max(rank)) 
	return notify_fail("你已经有"+CHINESE_D->chinese_number(suicong_num)+
		"名随从了。\n");

    if (! menpai || menpai == "")
	return notify_fail("你要领什么门派的随从？\n");

    switch (menpai) {
        case "华山派":
	case "华山":
	    menpai = "huashan";
        case "huashan":
	    cmenpai =  "华山派";
	    break;

        case "峨嵋":
	case "峨嵋派":
	    menpai = "emei";
        case "emei":
	    cmenpai =  "峨嵋派";
	    break;

 	case "武当":
	case "武当派":
	    menpai = "wudang";
        case "wudang":
	    cmenpai =  "武当派";
	    break;

	case "少林":
	case "少林派":
	    menpai = "shaolin";
        case "shaolin":
	    cmenpai =  "少林派";
	    break;

	case "丐帮":
	    menpai = "gaibang";
        case "gaibang":
	    cmenpai =  "丐帮";
	    break;

	case "星宿":
	case "星宿派":
	    menpai = "xingxiu";
        case "xingxiu":
	    cmenpai =  "星宿";
	    break;

	case "雪山":
	case "雪山派":
	case "血刀":
	case "血刀门":
	    menpai = "xueshan";
        case "xueshan":
	    cmenpai =  "雪山派";
	    break;

  	case "桃花":
	case "桃花岛":
	    menpai = "taohua";
        case "taohua":
	    cmenpai =  "桃花岛";
	    break;

	case "白驼":
	case "白驼山庄":
	    menpai = "baituo";
        case "baituo":
	    cmenpai =  "白驼山庄";
	    break;

        case "大理":
	case "大理段氏":
	case "dali":
	    return notify_fail("大理段氏的家臣怎么会来京城当随从呢？\n");

  	case "神龙":
	case "神龙教":
	case "shenlong":
	    return notify_fail("神龙教众官府见了就捉拿。你没搞错吧？\n");

        default:
                return notify_fail("你要领什么门派的随从侍卫？\n");
                break;
        }
    suicong_num ++;
    player->set("suicong_num", suicong_num);
    suicong = new("/clone/npc/suicong.c");
    suicong->new_master(player, suicong_num, menpai);
    suicong->move(environment(player));
    suicong->set_leader(player);
    player->save();
    message_vision("$N对$n说道，下官想要一名"+cmenpai+"的随从。\n",
		player, me);
    message_vision("$N拍了拍$n的肩膀，笑道，好好，没问题，来人啊。\n", 
		me, player);
    message_vision("$N快步走了过来，向$n行礼道：老爷金安。\n",
		suicong, player);
    return 1;
}

#include "/d/beijing/autok.h"
