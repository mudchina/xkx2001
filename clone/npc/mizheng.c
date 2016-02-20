//Cracked by Roath
// mizheng.c 兵部尚书
// 负责京畿武官，皇宫侍卫的赏罚，记录，升迁，降级等	-chu

#include <ansi.h>
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif

#include "/d/beijing/beijing_defs.h"

inherit NPC;
inherit F_SAVE;

string do_toujun();
string do_tuiyi();
string do_shengqian();
string do_members();
string do_news();

void create()
{
    int i, *speed_cur;

    seteuid(getuid());
    set_name("米正", ({"mi zheng", "mi"}));
    set("title", "兵部尚书");
    set("gender", "男性");
    set("age", 30);
    set("long", "他就是当今朝廷的兵部尚书，\n"
    "京畿侍卫，武官的升迁就全看他了。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    setup();
    carry_object("/d/city/obj/cloth")->wear();
    if (! restore() ) {
	speed_cur = allocate(7);

	for (i=0; i<7; i++) {
	    speed_cur[i] = HELPER->speed_base(i);
	}
	set("speed_cur", speed_cur);
	save();		// for the first time
    }
    remove_call_out("refresh_members");
    call_out("refresh_members", 1200);  // do it every 20 min
}

int init()
{
	set("inquiry", ([
	"随从" : "这个你去问军营的多总管吧。",
	"suicong" : "这个你去问军营的多总管吧。",
	"任务" : "这个你去问军营的多总管吧。",
	"job" : "这个你去问军营的多总管吧。",
	"here" : "这里就是堂堂兵部衙门。",
	"兵部" : "兵部统领骁骑营，近日皇上开恩，让下官代领侍卫营。",
	"投军" : (: do_toujun :),
	"join" : (: do_toujun :),
	"升迁" : (: do_shengqian :),
	"晋升" : (: do_shengqian :),
	"promote" : (: do_shengqian :),
	"退役" : (: do_tuiyi :),
	"告老" : (: do_tuiyi :),
	"retire"  : (: do_tuiyi :),
	"新闻"      : (: do_news :),
	"通文"      : (: do_news :),
	"news"      : (: do_news :),
	"名册"   : (: do_members :),
	"名单"   : (: do_members :),
	"members"   : (: do_members :),
	]));
}

string query_save_file()
{
    return NPCDATA+"mizheng";
}

/****************** UTILITY METHODS **************************/

void post_message(string msg)
{
    object me = this_object();
    string *news = me->query("bingbu/news");
    int     news_num = me->query("bingbu/news_num");
    int     i, diff;
#define MAX_NEWS 50

    if (news) { // purge old news
	if (news_num >= MAX_NEWS) {
	    diff = news_num - MAX_NEWS + 1;
	    for (i=0; i<news_num-diff; i++){
		news[i] = news[i+diff];
	    }
	}
    }else {
	news = allocate(MAX_NEWS);
	news_num = 0;
    }
    news[news_num++] = msg;
    me->set("bingbu/news", news);
    me->set("bingbu/news_num", news_num);
    save();
}

int *pos_ratio()
{
    object me = this_object();
    int *ret;
    int i, j;
    string *members;

    ret = ({0, 0, 0, 0, 0, 0, 0});
    for (i=0; i<7; i++){
	members = me->query("members/rank"+i);
        for (j=0; j<sizeof(members); j++){
	    if (members[j] != 0) {
	        ret[i] ++;
 	    }
	}
	if (ret[i] > 0)
	    ret[i] = 100*ret[i]/sizeof(members);
    }
    
    return ret;
}

int player_rank(string id)
{
    object me = this_object();
    int i, j;
    string *members;

    for (i=0; i<7; i++){
	members = me->query("members/rank"+i);
        for (j=0; j<sizeof(members); j++){
	    if (members[j] == id) {
	        return i;
 	    }
	}
    }
    return -1;
}

object get_player(string id)
{
    object usr;
    
    usr = find_player(id);
    if (! usr) {
	usr->set_temp("temp_dummy", 1);
	usr = new("/clone/test/dummy");
	usr->set("id", id);
	if ( !usr->restore() ) {
	    return 0;
	}
    }
    return usr;
}

int add_user_succ(object me, object player, int rank)
{
    int slot, i;
    string *members;

    members = me->query("members/rank"+rank);
    if (!members) {
	members = allocate(HELPER->rank_position_num(rank));
  	for (i=0; i<sizeof(members); i++){
	    members[i] = 0;
	}
	slot = 0;
    }else{
  	for (i=0; i<sizeof(members); i++){
	    if (members[i] == 0) slot = i;
	    break;
	}
        if (i == sizeof(members))
	    return 0;
    }

    player->set("family/generation", rank);
    player->set("bingbu/death_count", player->query("death_count"));
    player->set("bingbu/job_cur", 0);
    player->set("bingbu/job_lazy", 0);
    player->set("bingbu/job_lazy_time", time());
    player->set("bingbu/job_lazy_mud", 0);
    player->set("bingbu/job_lazy_mudtime", player->query("mud_age"));
    player->set("bingbu/last_check", player->query("mud_age"));

    if (rank >= 5) {
	player->set("bingbu/dept", HELPER->dept_name(slot%2));
	player->set("title", player->query("bingbu/dept")+HELPER->rank_name(rank));
    }else{
	player->set("title", HELPER->rank_name(rank));
    }
    player->save();

    members[slot] = player->query("id");
    me->set("members/rank"+rank, members);
    me->save();
    return 1;
}

void normalize(object player)
{
    object *obs, ob;

    obs=filter_array(children("/d/beijing/obj/yaopai.c"), (: clonep :));
    if (sizeof(obs) > 0){
	foreach (ob in obs) {
	    if (environment(ob) == player) {
		destruct(ob);
		if (environment(player) == environment(this_object()))
		    message_vision("$N从$n的身上解下一个侍卫腰牌。\n", 
			this_object(), player);
	    }
	}
    }
    player->delete("family");
    player->set("title","普通百姓");
    player->save();
}

/****************** CALL_BACK METHODS **************************/

string do_news()
{
    object me = this_object();
    object player = this_player();
    string *news = me->query("bingbu/news");
    int     news_num = me->query("bingbu/news_num");
    int     i;

    if (! IS_SHIWEI(player)) {
	return "你不是御林军侍卫，如何敢来此罗唣!";
    }
    message_vision("$N给$n看了一眼兵部的通文。\n", me, player);
    tell_object(player, "----------------兵部通文-------------\n");
    for (i=0; i<news_num; i++){
	tell_object(player, news[i]);
    }
    return "看完就赶紧走吧。";
}

string do_members()
{
    object me = this_object();
    object player = this_player();
    object usr;
    int    rank, i, num;
    string *members, *ret, *name;
    
    if (! IS_SHIWEI(player)) {
	return "你不是御林军侍卫，如何敢来此罗唣!";
    }

    if (time() - player->query("bingbu/ask_member") < 3600) {
	return "不是刚给你看过吗？";
    }

    player->set("bingbu/ask_member", time());

    message_vision("$N给$n看了一眼侍卫名册。\n", me, player);

    tell_object(player, "御林军名册\n");
    for (rank = 0; rank < 7; rank ++) {
	tell_object(player, "--------------- " + HELPER->rank_name(rank)+" --------------\n");
 	members = me->query("members/rank"+rank);
	num = 0;
	for (i=0; i<sizeof(members); i++) {
 	    if (members[i] != 0) {
		usr = get_player(members[i]);
		if (usr) {
		    if (rank > 4) {
			name = HELPER->player_title(player)+player->name();
		    } else {
			name = player->name();
		    }
		    tell_object(player, name);
		    num ++;
		    if (num % 5 == 0) {
			tell_object(player, "\n");
		    }else {
			tell_object(player, "\t");
		    }
	  	    if (usr->query_temp("temp_dummy"))
			destruct(usr);
		}
	    }
 	}
	if (num % 5 > 0) {
	    tell_object(player, "\n");
	}
    }
    return "看完就赶紧走吧。";
}

string do_shengqian()
{
    object me = this_object();
    object player = this_player();
    int    rank, i;
    string *members;

    if (player->query("possessed")) return "你被附身了。";
    if (! IS_SHIWEI(player)) {
	return "你开什么玩笑？当心我把你抓起来。";
    }
    rank = SHIWEI_LEVEL(player);
    if ( player->query("bingbu/job_cur") < HELPER->job_upgrade_num(rank)) {
	return "你的军功不够，怎么升啊？";
    }
    if (rank >= 6) 
	return "大人您已经是"+HELPER->player_title(player)+
	       "了，再升就。。。";

    if (! add_user_succ(me, player, rank+1)) {
	return "大人军功卓著，可现下兵部人满为患，没有实缺啊.";
    }

    // remove user from his current rank
    members = me->query("members/rank"+rank);
    for (i=0; i<sizeof(members); i++){
	if (members[i] == player->query("id")) {
	    members[i] = 0;
	}
    }
    me->set("members/rank"+rank, members);
    post_message(player->name()+"荣升"+HELPER->player_title(player)+"\n");
    me->save();

    return "好，大人军功卓著，我就升您为"+HELPER->player_title(player)+"吧。";
}


string do_tuiyi()
{
    object me = this_object();
    object player = this_player();
    object yaopai;
    string *members, name=player->name(), id = player->query("id");
    int    i, slot, rank;

    if (player->query("possessed")) return "你被附身了。";
    if (! IS_SHIWEI(player)) {
	return "你开什么玩笑？当心我把你抓起来。";
    }

    for (rank=0; rank<7; rank++){
	members = me->query("members/rank"+rank);
	if (!members) {
	    members = allocate(HELPER->rank_position_num(0));
	    for (i=0; i<sizeof(members); i++){
		members[i] = 0;
	    }
	    slot = -1;
	}else{
	    for (i=0; i<sizeof(members); i++){
		if (members[i] == id) slot = i;
		break;
	    }
	    if (i == sizeof(members)) slot=-1;
	    else {
		// we agree on which rank you are
		if (rank == player->query("family/generation")) {
		    break;
		}
	    }
	}
    }

    post_message(HELPER->player_title(player)+player->name()+"退役了。\n");
    if (slot == -1) {
 	normalize(player);
	return "我的名册上没有你啊？不过我还是把你给注销了吧。";
    }else {
	player->set("bingbu/leave_time", time());
	player->set("bingbu/leave_age", player->query("mud_age"));
        normalize(player);
 	members[slot] = 0;
	me->set("members/rank"+rank, members);
	me->save();
	return "好吧，就准你告老还乡吧。";
    }
}


string do_toujun()
{
    object me = this_object();
    object player = this_player();
    object yaopai;
    int    leave_age;

    if (player->query("possessed")) return "你被附身了，我可不能收你。";
    if (IS_SHIWEI(player)) {
	return "你开什么玩笑？当心我把你革职查办。";
    }

    if ((player->query("family/family_name") == "丐帮") &&
	(player->query("rank") > 1)) {
	return "你乃丐帮高手，如何要来公门？";
    }

    if (player->query("gender") == "无性") 
	return "公公还是回宫去吧。";

    if (player->query("gender") == "女性") 
	return "象你这般不守妇道的女子，也有脸面来见本官？";
    
    if (player->query("combat_exp") < 20000) 
	return "阁下武功低微，如何能为皇上出力？";
    
    if (leave_age = player->query("bingbu/leave_age")) {
 	if (player->query("mud_age")-leave_age < HELPER->pending_time()) {
	    return "你刚告老还乡就想重新投军？";
	}
    }

    // we allow this player to join, check positions available
    if (! add_user_succ(me, player, 0)) {
	return "现在御林军没有空缺，你过一阵子再来吧。";
    }

    post_message(player->name()+"投军，实授"+HELPER->player_title(player)+"。\n");
    player->set("family", ([
	"family_name"    : "御林军",
	"enter_time"     : time(),
    ]));
    player->set("bingbu/job_total", 0);
    player->set("bingbu/job_rank0", 0);
    player->set("bingbu/job_rank1", 0);
    player->set("bingbu/job_rank2", 0);
    player->set("bingbu/job_rank3", 0);
    player->set("bingbu/job_rank4", 0);
    player->set("bingbu/job_rank5", 0);
    player->set("bingbu/job_rank6", 0);

    yaopai = new("/d/beijing/obj/yaopai.c");
    yaopai->move(player);
    player->set("suicong_num", 0);
    player->save();

    message_vision("$N决定背叛师门，加入御林军！！\n", player);
    message_vision("$N给$n一个侍卫腰牌。拍着$n的肩膀说道：恭喜你成为"
	+HELPER->rank_name(0)+"。\n", me, player);

    return "去多总管那儿领任务去吧。";
}

/*
 * Demote a player if one of the following stands:
 * 1. if he died more than allowed times in his current position when rank<5
 * 2. if he died more than twice within two years mudtime when rank>=5
 * 3. if his job_lazy<4 and lazy_time over 1 week
 * 4. if his job_lazy<4 and lazy_mudtime over 12 hours
 *
 * return 0: nothing should be done.
 *        1: this player should be demoted.
 *        2: this player should be removed from the system.
 *
 * WIZ: IF YOU RECOVER A PLAYER, MAKE SURE ALL DATA ARE MANUALLY
 * RECOVERED FOR ALL LEVELS OF SHIWEI.  SOMETIMES IT IS NOT 
 * POSSIBLE. -chu
 */
string should_demote(object usr)
{
    int    *death_allowed = ({10, 5, 5, 3, 3, 2, 2});
    int    ret, rank, death, last_check;
    string msg;

    rank = SHIWEI_LEVEL(usr);
    death = usr->query("death_count");
    last_check = usr->query("bingbu/last_check");

    ret = 0;
    if (death - usr->query("bingbu/death_count") > death_allowed[rank]) {
	msg="在职期间死亡次数过多";
	ret = 1;
    }

    // if 2 years have been past, reset
    if (rank >= 5) {
	if (usr->query("mud_age") - last_check > 518400) {
	    usr->set("bingbu/last_check", usr->query("mud_age"));
	    usr->set("bingbu/death_count", death);
	    usr->save();
	}
    }

    // check if he is doing jobs
    if (time() - usr->query("bingbu/job_lazy_time") >= 604800) {
	if (usr->query("bingbu/job_lazy") < 4) {
	    msg="长期不到兵部点名";
	    ret = 1;
 	}
	usr->set("bingbu/job_lazy", 0);
	usr->set("bingbu/job_lazy_time", time());
    }
    if (usr->query("mud_age") - usr->query("bingbu/job_lazy_mudtime") >= 
	    43200) {
	if (usr->query("bingbu/job_lazy_mud") < 4) {
	    msg="长期不到兵部值班";
	    ret = 1;
 	}
	usr->set("bingbu/job_lazy_mud", 0);
	usr->set("bingbu/job_lazy_mudtime", usr->query("mud_age"));
    }

    return 0;
}

void demote(object me, object usr, int old_rank)
{
    int i, j, position_found;
    string *members;

    for (i=old_rank-1; i>=0; i--){
	if (add_user_succ(me, usr, i)) {
	    tell_object(usr, "你被降成"+HELPER->rank_name(i)+"\n");
	    post_message(usr->query("name")+"被降成"+
			HELPER->rank_name(i)+"\n");
 	    // remove suicong
	    if (usr->query("suicong_num") > HELPER->suicong_max(i)) {
		usr->set("suicong_num", HELPER->suicong_max(i));
	    }
	    return;
	}
    }
    normalize(usr);
    tell_object(usr, "你被勒令退役。\n");
    post_message(usr->query("name")+"你被勒令退役。\n");
}

void refresh_members()
{
    object me = this_object();
    int i, j, cloned_user;
    string *members, msg;
    object usr;

    for (i=0; i<7; i++){
	members = me->query("members/rank"+i);
        for (j=0; j<sizeof(members); j++){
	    if (! members[j]) continue;
	    usr = get_player(members[j]);

	    if (! usr) {
		members[j] = 0;	// expell
	    }else{
	 	if (! IS_SHIWEI(usr)) {
		    members[j] = 0;	// maybe he went to xx
		}else if ( msg=should_demote(usr)) {
		    members[j] = 0;
		    tell_object(usr, "由于你"+msg+"，你被兵部降职了。\n");
		    post_message(usr->name()+"由于"+msg+"被兵部降职了。\n");
		    demote(me, usr, i);
		    usr->save();
		}
 	    }
	    if (usr->query_temp("temp_dummy")) destruct(usr);
	}
	me->set("members/rank"+i, members);
    }
    me->save();
}
