//Cracked by Roath
// Ssy

inherit ROOM;
#include <ansi.h>

int valid_leave(object who, string dir);
#include "battlefield.h"

void create()
{
        set("short", HIY"试剑山庄"NOR);
        set("long", @LONG
谁也没有想到，在这天山雪岭中竟然还有如此诺大的一个庄院。
院外几株雪松傲然而立，阳光照映之下，麟麟银光映射到大门上面
的牌匾上。牌匾上四个大字“试剑山庄”凛然生威。大门(gate)是
汉白玉所制，极为厚重。门边贴了一个告示 (gaoshi)
LONG
        );
        set("item_desc", ([
                "gate" : "一扇汉白玉制成的大门，极为厚重。\n",
                "gaoshi" : @LONG
这里是玩家们集体比武的地方．进去后过群英堂，试剑亭，就是比武场了．
进门之前您的东西会被这里的主人保管，比武完毕再还给您．只不过听说
他信用不太好，所以有什么闪失就不要抱怨了．

比武场的北面是一个大院，也可以用来打斗．比武场外面 (out) 是休息室，
被打败的玩家们从那儿可以拿回自己的东西．从休息室就不能再进比武场了，
所以除非你想认输，一般说来不去那里．

在比武场和大院内，大家的生命是受保护的，尽管用 kill 命令也不会有问
题．当你的对手昏倒或者被你杀死后，用 finish 命令把他踢到休息室，否
则他还可以继续战斗．
LONG
		,
        ]));

        set("exits", ([
                "west" : __DIR__"snow3",
        ]));
        set("cost", 1);
        set("outdoors", "tianshan");
        setup();
	set_temp("opened", 0);
}
void init()
{
        add_action("do_open",  "open");
        add_action("do_close",  "close");
        add_action("do_knock",  "knock");
    disableCmds();
}

int do_open(string arg)
{
        object me = this_player();
        if ((!arg) || (arg!="gate"))
	  return 0;
	if ((int)query_temp("opened") != 0)
	  return notify_fail("门已经开开了！\n");
        if(!wizardp(me))
	  {
	    message_vision("$N使劲想推开门，结果什么反应都没有。\n", me);
	    return 1;
	  }
	message_vision("$N伸出一根手指点在门环上，“吱呀”一声，门开了。\n", me);
	set("exits/enter",  __DIR__"entrance1");
	set_temp("opened", 1);
	remove_call_out("closegate");
        call_out("closegate", 60);
	return 1;
}

int do_close(string arg)
{
        object me = this_player();
        if ((!arg) || (arg!="gate"))
	  return 0;
	if ((int)query_temp("opened") != 1)
	  return notify_fail("门还没有打开呐！\n");
        if(!wizardp(me))
	  {
	    message_vision("$N使劲想把门合上，结果什么反应都没有。\n", me);
	    return 1;
	  }
	message_vision("$N“砰”地一声把门撞上了。\n", me);
	delete("exits/enter");
	set_temp("opened", 0);

	return 1;
}

int do_knock(string arg)
{
        object me = this_player();
        if ((!arg) || (arg!="gate"))
	  return 0;
	if ((int)query_temp("opened") != 0)
	  return notify_fail("门已经开开了！\n");
        if(!wizardp(me))
	  {
	    message_vision("$N使劲敲了半天门，什么反应都没有。\n", me);
	    return 1;
	  }
	message_vision("$N敲了敲门，“吱呀”一声，门开了。\n", me);
	set("exits/enter",  __DIR__"entrance1");
	set_temp("opened", 1);
	remove_call_out("closegate");
        call_out("closegate", 60);
	return 1;
}

void closegate()
{
	message("info", "门“吱呀”一声自动合上了。\n", this_object(), 0);
	delete("exits/enter");
	set_temp("opened", 0);

}

int valid_leave(object who, string dir)
{
    if (wizardp(who) || dir!="enter") return ::valid_leave(who, dir);
    if (who->query_all_condition()) {
	return notify_fail("你身上带着伤毒，怎么好意思去比武？\n");
    }
    return ::valid_leave(who, dir);
}
