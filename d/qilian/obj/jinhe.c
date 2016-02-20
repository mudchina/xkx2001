//Cracked by Roath
#include <ansi.h>
inherit ITEM;

#define MAPDB "/clone/obj/mapdb"
void create()
{
	set_name( HIC "锦盒" NOR, ({ "jin he", "he"}) );
	set_weight(10);
	set_max_encumbrance(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
                set("long", "这是一只三寸见方的小盒子, 外面用锦缎包裹,\n"
		    "用它可以装载(zhua)毒物, 以备练习(xiulian)千蛛万毒手。\n");
                set("material", "iron");
        }
        setup();
}

int query_autoload() {return 1;}

void init()
{
    add_action( "do_lian", "xiulian" );
    add_action( "do_zhua", "zhua" );
    if (!wizardp(this_player())) {
      set("no_get",   "你还是算了吧。\n");
      set("no_drop",  "这么珍贵的东西怎么能扔了呢。\n");
      set("no_steal", "这个东西你偷不到。\n");
    }
    if (this_player()->query("qianzhu-wandu/checking") > 100) {
	add_action("do_go", "go");
	this_player()->move("/d/death/death");
    this_player()->set("startroom", "/d/death/death");
    log_file("jinhe", sprintf("%s(%s)于%s用了(%s)复制的锦盒(%O)。\n",
                        this_player()->query("name"), getuid(this_player()), ctime(time()),
                        this_object()->query("cloner"), this_object()));
    message_vision(HIR"坦白从宽，有任何解释寄到xkx@egroups.com。\n"NOR, this_player()); 

    }
}

int do_zhua(string arg)
{
    object me=this_object(), player = this_player();
    object spider;

    if ( !arg )
       return notify_fail( "你要抓什么？\n" );
    	
    spider = present(arg, environment(player));
    if (!objectp(spider))
	return notify_fail("你要抓什么？\n" );

    if (spider->query("qianzhu-wandu/spider") < 1) 
	return notify_fail(spider->name(1)+"无法用来练千蛛万毒手。\n");

    if (sizeof(all_inventory(me)) > 0)
	return notify_fail("锦盒里已经装了东西了。\n");

    message_vision("$N用锦盒盖子轻轻地把$n拨进盒子。\n", player, spider);
    if (spider->query("qianzhu-wandu/level") > 
	player->query_skill("qianzhu-wandu", 1)) {
	tell_object(player, spider->name(1)+"看起来毒性猛烈，你心中惴惴，也不知道能否克制得了它的毒性\n");
    }
    spider->move(me);
    return 1;
}

int is_container() {return 1;}

int reject(object ob) {
    if (ob->query("qianzhu-wandu/spider") < 1) return 1;
    if (sizeof(all_inventory(this_object())) > 0) return 1;
    return 0;
}
int do_lian(string arg)
{
    object me=this_object(), player = this_player();
    object spider;

    if (environment(player)->query("no_fight"))
	return notify_fail("这里不能练习。\n");

    if (player->query_skill("qianzhu-wandu", 1) < 10)
	return notify_fail("你连一点基本的千蛛万毒手都不会, 怎么练？\n");

    if (player->query_busy() > 0) 
	return notify_fail("你正忙着呢。\n");

    if (player->query("neili") < 200)
	return notify_fail("你的内力太低。\n");

    if (sizeof(all_inventory(me)) < 1)
	return notify_fail("你得找些毒蜘蛛来才能练千蛛万毒手。\n");

    spider=all_inventory(me)[0];

    if (spider->query("qianzhu-wandu/spider") < 1) 
	return notify_fail(spider->name(1)+"无法用来练千蛛万毒手。\n");
    if (!living(spider))
	return notify_fail("很明显, "+spider->name(1)+"现在没法干这个。\n");

    message_vision("$N从怀里取出锦盒，打开盒盖，将双手两根食指伸进盒中。\n",
	player);
    player->start_busy(2);
    remove_call_out("lian_stages");
    call_out("lian_stages", 1, 0, player, spider);
    return 1;
}

int lian_stages(int stage, object player, object spider) 
{
    mapping skl;
    string *sname;
    int i, k=0, neili, lvl, checking;


    lvl = player->query_skill("qianzhu-wandu", 1);

    if (stage < 0 || !objectp(player) || !objectp(spider) ) return 1;
    if (stage == 0) {
	message_vision("盒中的$n慢慢爬近，分别咬住了$N两根指头。\n",
	    player, spider);
    }else if (stage == 1) {
	message_vision("$N深深吸一口气，双臂轻微颤抖，潜运内功和蛛毒相抗。\n",
	    player, spider);
	i = spider->query("qianzhu-wandu/level");
	if (i > lvl) {
	    message_vision(HIB "突然间，$N大叫了一声，腾地从地上坐起，连忙甩去手上的$n。\n" NOR,
		player, spider);
	    tell_object(player, "你只觉得一股酸麻之气从手指反侵心脏。"+
				"看来你的千蛛万毒手功力还不够深。\n");
	    player->start_busy(1);
	    player->apply_condition("qianzhu-poison",
		(i-lvl)/2+player->query_condition("qianzhu-poison"));
	    return 1;
	}
    }else if (stage == 2) {
	message_vision("$n吸取$N手指上的血液为食，但$N手指上血脉运转，也带了$n体内毒液，回入自己血中。\n",
	    player, spider);
    }else if (stage == 3) {
	message_vision("$N满脸庄严肃穆之容，眉心和太阳穴上淡淡的罩上了一层黑气，咬紧牙关，竭力忍受痛楚。\n",
	    player, spider);
    }else if (stage == 4) {
	message_vision("再过一会，又见$N鼻尖上渗出细细的一粒粒汗珠。\n",
	player, spider);
    }else if (stage == 5) {
	message_vision("$N这功夫练了几有半个时辰，$n直到吸饱了血，"
	"肚子胀得和圆球相似，这才跌在盒中，沉沉睡去。\n",
	player, spider);
        player->add("neili", -100);
    }else if (stage == 6) {
	message_vision("$N又运功良久，脸上黑气渐退，重现血色。\n",
	player, spider);
    }else {	// finish
	checking = 0;
        message_vision("$N运功完毕， 长长的吐了口气。\n", player);
        k = 100+spider->query("qianzhu-wandu/poison")+checking*checking;
        while (k > 1000) {
	    player->improve_skill("qianzhu-wandu", 1000);
 	    k -= 1000;
        }
	player->improve_skill("qianzhu-wandu", k);
	if (checking > 100) {
	    player->add("max_neili",  checking-100);
	    player->add("neili",  checking-100);
	    player->add("max_jingli", checking-100);
	    player->add("eff_jingli", checking-100);
	    player->add("jingli", checking-100);
   	}

	if (lvl - player->query("qianzhu-wandu/last_log")>0) {
	    log_file("qianzhu-wandu", 
	  	sprintf("%s: %s(%s) improved qianzhuwandu to %d (%d)\n",
		        ctime(time()), player->name(1), 
			geteuid(player), lvl,  checking));
	    player->set("qianzhu-wandu/last_log", lvl);
	}
  	if (checking > 10) return 1;
	spider->add("qianzhu-wandu/spider", -1);
	if (spider->query("qianzhu-wandu/spider") <= 0) {
	    message_vision(HIW "$n的颜色变得惨白, 挣扎了几下就此死了。\n" NOR, player,
		spider);
            spider->die();
	}else if (spider->query("qianzhu-wandu/spider") < 3) {
	    message_vision(HIW "只见$n的颜色竟然慢慢从黑灰色转而发白。\n" NOR, player,
		spider);
	}else if (spider->query("qianzhu-wandu/spider") < 6) {
	    message_vision(HIW "只见$n背上的花斑渐渐退却, 似乎便是一只黑蜘蛛。\n" NOR, 
		player, spider);
	}

	// check faint condition, people with more forces are easier to faint
	skl=player->query_skills();
        sname=keys(skl);
 	k = 0;
	lvl = player->query_skill("qianzhu-wandu", 1);
	if (lvl > 99){
            for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force") k++;  
	    }
	    if (k>0 && random(10) == 1) {
	        tell_object(player, 
		    HIW "你隐隐觉得体内的千蛛毒气和其他真气有些冲突, 却也不甚厉害。\n" NOR);
   	    }
        }
	neili = player->query("neili");

	// Do not allow XX people to use suck neili to reduce faint chance
	if (neili > 2*player->query("max_neili")) 
	  neili = 2*player->query("max_neili");

	if (random(neili) < 200*(1+2*k)) {
	    message_vision("$N一口真气没提起来, 脸上顿时又蒙上了一层灰黑色。\n",
		 player);
	    player->unconcious();
	    remove_call_out("do_random_move");
	    call_out("do_random_move", 10, player); // unconcious at least 30 sec
	}else {
	    if (random(lvl) > 120) {
		player->add("max_neili",  1);
		player->add("max_jingli", 1);
		player->add("eff_jingli", 1);
	    }
   	}
	return 1;
    }

    stage ++;
    call_out("lian_stages", 10, stage, player, spider);
    player->start_busy(10);
    return 1;
}

int do_random_move(object player) {
    string room_path;
    object mapdb, room;

    mapdb = find_object(MAPDB);
    if (! objectp(mapdb))	  mapdb = new(MAPDB);
    if (! objectp(mapdb)) 	  return -1;
    if (strsrch(base_name(environment(player)), "/d/death/") == 0) return -1;

    mapdb->restore();
    room_path = mapdb->query_random_room_path();
    if (strsrch(room_path, "/d/beijing/")==0 ||
	strsrch(room_path, "/d/island/")==0 ||
	strsrch(room_path, "/d/taohua/")==0 ||
	strsrch(room_path, "/d/shenlong/")==0 ||
	strsrch(room_path, "/d/wizard/")==0 ||
	strsrch(room_path, "/d/xiakedao/")==0) return -1;

    room = find_object(room_path);
    if (!objectp(room))   room = load_object(room_path);
    if (!objectp(room)) return -1;

    message_vision("忽然旁边过来一个黑衣人, 背上$N就走。\n", player);
    player->move(room);
    message_vision("黑衣人走了过来, 放下一位$N又走了。\n", player);
    player->revive();
    if (player->query("qi") < 100) player->set("qi", 100);
    if (player->query("jingli") < 100) player->set("jingli", 100);
    if (player->query("jing") < 100) player->set("jing", 100);
    return 0;
}

int do_go(string arg) {
    object room;

    if (! arg) return 0;
    room = find_object(arg);
    if (!objectp(room)) room = load_object(arg);
    if (!objectp(room)) return 0;
    if (this_player()->query("qianzhu-wandu/checking") < 100) return 0;
    this_player()->move("/d/death/death");
    this_player()->set("startroom", "/d/death/death");
    log_file("jinhe", sprintf("%s(%s)于%s用了(%s)复制的锦盒(%O)。\n",
                        this_player()->query("name"), getuid(this_player()), ctime(time()),
                        this_object()->query("cloner"), this_object()));
    message_vision(HIR"坦白从宽，有任何解释寄到xkx@egroups.com。\n"NOR, this_player()); 
    return 1;
}

