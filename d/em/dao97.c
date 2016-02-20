//Cracked by Roath
// dao97.c 九十九道拐
// Shan: 96/06/22

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "九十九道拐");
	set("long", @LONG
这是著名的「九十九道拐」，道路纡曲陡竖，千折百回。据说过去曾有个
百余岁的疯僧至此，见一巨蟒挡路，便念咒驱蟒。但人们得知此处有巨蟒出没
后，便再也无人敢碰这里的草木，并以「龙居」名之。由此东可至千佛庵，西
达九老洞。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"dao98",
		"westup" : __DIR__"dao96",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 4);
	setup();
//	replace_program(ROOM);

}

private void move_to_tree(object me)
{
	if(!me) return;
        message_vision( HIR"忽然一阵腥风袭来，一条巨蟒从身旁大树上悬下，把$N卷走了。\n"NOR,
                                me);
        me->move("/d/emei/treeup");
	me->start_busy(1);
}

void init()
{
        object me = this_player();
        if ( !find_object("/d/emei/treeup") )
		call_other("/d/emei/treeup", "???");
	if ( objectp(present("ju mang", find_object("/d/emei/treeup"))) 
           && random((int)me->query_kar() + (int)me->query_per()) < 5 ) {
		me->start_busy(1);
		call_out("move_to_tree", 1, me);
        }
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

	if ( me->query_skill("dodge", 1) > 100 )
		return ::valid_leave(me, dir);

        current_jingli = me->query("jingli");
        if (dir == "westup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(10));
                me->improve_skill("dodge", random(10));
                write("你沿九十九道拐又向上爬了一阵，觉得好累。\n");
        }

        else if (dir == "westup" && current_jingli <= 5)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

