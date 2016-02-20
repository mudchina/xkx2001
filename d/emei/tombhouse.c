//Cracked by Roath
// d/emei/tombhouse.c 郭襄墓后小茅屋
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "小茅屋");
	set("long", @LONG
这是一间小茅屋，屋内摆设简单，一张木床，一张石几，一只木书架，架
上摆着几本旧书。墙上挂着一幅峨眉山的山水画，墙角放着一个小包袱，上面
盖了顶大斗笠，门外堆放了些锄头，扫帚等工具。一个年轻小师太正坐在几前
专心读书。
LONG
	);

        set("exits", ([
                "west" : __DIR__"grassland",
        ]));

        set("objects",([
                __DIR__"npc/guard" : 1,
		__DIR__"obj/yugajing0" :1,
        ]));

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob, *inv;
	object guard = present("guard", environment(me));
//	object guard = objectp(present("guard", environment(me)));
	int i;

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) 
		if (inv[i]->query_max_encumbrance() && ob = present("jiuyin-zhenjing", inv[i]) ) break;

	if ( !ob ) ob = present("jiuyin-zhenjing", me);

	if ( (dir == "west") && objectp(ob) ) {
        	message_vision("$N把书还给文菲，走出门去。\n", me);
        	ob->move(environment(me));
        	destruct(ob);
		guard->add("jing_count", 1);
		me->delete_temp("visited");
        }

        return ::valid_leave(me, dir);
}

