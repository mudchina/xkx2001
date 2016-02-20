//Cracked by Roath
// canpian
// used to improve tjsg and hunyuan-yiqi over 200
// -chu@xkx

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

int do_dun(string arg);
int do_jie(string arg);

void create()
{
    set_name(YEL "九阳神功残篇" NOR, ({"canpian", "book"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "部");
        set("long", "这是武当派祖师张三丰真人笔录的部分九阳神功。\n");
        set("material", "paper");
        set("value", 1000000000);
    }
}

int init()
{
    add_action("do_canwu", "canwu");
    return 1;
}

int do_canwu(string arg)
{
    object player = this_player();
    object target, obj=this_object(), env=environment(player);
    string my_skill, your_skill;
    int my_lvl, your_lvl;

    if (!arg) return notify_fail("你要跟谁一起参悟?\n");
    target = present(arg, env);
    if (!objectp(target))  return notify_fail("你要跟谁一起参悟?\n");
    if (!userp(target))    return notify_fail("你只能跟玩家一起参悟。\n");
    if (player->is_busy()) return notify_fail("你正忙着呢。\n");
    
    my_lvl = player->query_skill("taiji-shengong", 1);
    your_lvl = player->query_skill("hunyuan-yiqi", 1);
    if (my_lvl < 200 && your_lvl < 200) 
	return notify_fail("你的太极神功或者混元一气功不够高，无法参悟。\n");
    if (my_lvl >= 200) {
	my_skill = "taiji-shengong";
	your_skill = "hunyuan-yiqi";
	your_lvl = target->query_skill("hunyuan-yiqi", 1);
    }else {
	my_lvl = your_lvl;
	your_lvl = target->query_skill("taiji-shengong", 1);
	my_skill = "hunyuan-yiqi";
	your_skill = "taiji-shengong";
    }
    if (your_lvl < my_lvl-10)
	return notify_fail(target->name(1)+"的本门内功远逊于你，已不能帮你参悟了。\n");
    if (player->query("jing") < 1000)
	return notify_fail("你精神不济，连话都说不清楚了。\n");
    if (target->query("jing") < 1000)
	return notify_fail("你想向"+target->name(1)+"请教有关"+
		to_chinese(your_skill)+"的问题，可人家没精打采的不理你。\n");
    message_vision("$N拿出九阳神功残篇，跟$n相互参悟，双方似有所悟。\n",
	player, target);
    player->start_busy(2+random(2));
    target->start_busy(1+random(4));
    player->add("jing", -1000);
    target->add("jing", -500);

    if (player->valid_learn(my_skill))    player->improve_skill(my_skill, 200);
    if (target->valid_learn(your_skill))  target->improve_skill(your_skill, 100);
    return 1;
}
