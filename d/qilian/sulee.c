//Cracked by Roath
// /d/qilian/sulee
// Ryu, 10/28/96.
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "疏勒河东岸");
  set ("long", @LONG
河水沿着大泉的冰河河床下到甘肃，水势渐缓，在鸣沙山和三危
山间冲刷出一道山崖断层。莫高窟就座落在西面鸣沙山的断层上。边
上有一丛小树林，树枝(shuzhi)枝叶不是很茂密。
LONG);

	set("exits", ([
                "northeast" : __DIR__"loulan",
        ]));
	set("item_desc", ([
                "shuzhi" : "一些不是很粗壮的树枝，可以把它们砍(chop)下来做成一个木筏。\n"
        ]));
	set("mufa_count", 3);
	set("outdoors", "/d/qilian");
	set("cost", 2);
	setup();
}
void init()
{
   add_action("do_chop","chop");
   add_action("do_make","make");
}
int do_chop(string arg)
{
	object weapon, me = this_player();
	
	if( !arg || arg!="shuzhi" )
        return notify_fail("你要砍甚么？\n");
	
	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword"
	&& (string)weapon->query("skill_type") != "blade" )

	return notify_fail("空手砍树恐怕不行吧？\n"); 
	
	if (query("mufa_count") < 1)
                return notify_fail("这儿的树枝都被砍光了，等它们长出来时再砍吧。\n");

	me->receive_damage("jingli", 5);
	message_vision("$N操上手中的家伙，从树上砍下一些树枝。\n", me);
	if ( random(10) >= 7) {
        write("你砍下的树枝似乎足够做(make)一个木筏(raft)了。\n");
        me->set_temp("marks/砍", 1);
        }
        me->start_busy(10);
	return 1;
}
int do_make(string arg)
{
	object ob, me = this_player();

        if( !arg || arg!="raft" )
        return notify_fail("你要做甚么？\n");

	if( !me->query_temp("marks/砍") )	
	return notify_fail("你要做甚么？\n");

	ob = new("/d/qilian/obj/raft");
        ob->move("/d/qilian/sulee");	
	write("你用砍下的树枝做了一个木筏。\n");
	me->delete_temp("marks/砍");
	add("mufa_count", -1);
	return 1;
}
