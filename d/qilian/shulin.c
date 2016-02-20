//Cracked by Roath
// 小树林
// Ryu, 10/28/96.
#include <room.h>
inherit ROOM;

int do_chop();
int do_make();
void create()
{
  set ("short", "小树林");
  set ("long", @LONG
一片小小树林，这里的树枝(shuzhi)枝叶不是很茂密。

LONG);

	set("exits", ([
                "northth" : __DIR__"sulee",
        ]));
	set("item_desc", ([
                "shuzhi" : "一些不是很粗壮的树枝，可以把它们砍(chop)下来做成一个木筏。\n"
        ]));
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
        return notify_fail("你要砍甚么？！\n");
	
	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword"
	&& (string)weapon->query("skill_type") != "blade" )

	return notify_fail("空手砍树恐怕不行吧？！\n"); 
	
	me->receive_damage("jingli", 5);
	message_vision("$N用手中的家伙，从树上砍下一些树枝。\n", me);
	if ( random(15) == 9) {
        write("你砍下的树枝似乎足够做(make)一个木筏(raft)了。\n");
        me->set_temp("marks/砍", 1);
        }
        me->set_busy(10);
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
        ob->move("/d/qilian/shulin");	
	me->delete_temp("marks/砍");

	return 1;
}
