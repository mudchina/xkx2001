//Cracked by Roath
// chanfang.c 禅房

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "禅房");
	set("long", @LONG
这里是一间安静宽敞的禅房，乃是庵中弟子打坐修行之所。地下整整
齐齐地放着许多蒲团。几位年轻师太和俗家女弟子正肃容入定。
LONG
	);
	set("exits", ([
		"west" : __DIR__"wannian1",
	]));

	set("jingzuo_room", 1);

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_jingzuo", "jingzuo");
}

int do_jingzuo(string arg)
{
	object me = this_player();
        if ( me->query("family/family_name") != "峨嵋派" || me->is_busy() )
                return command("jingzuo "+arg);
	if(random(9) == 3) {
		tell_object(me, "忽然外面传来一阵噪杂声，你只觉心烦意乱，不能静心修练，\n只好改去别庵禅房继续修行。\n");
		tell_room(environment(me),(string)me->query("name")+"走啦，去别庵禅房继续修行了。\n", me);
		switch (random(3)) {
			case 0: me->move("/d/emei/hz_chanfang");
				break;
			case 1: me->move("/d/emei/chanfang_fs");
				break;
			case 2: me->move("/d/emei/chanfang_qf");
				break;
		}
		tell_room(environment(me),(string)me->query("name")+"从别庵禅房来这里继续修行啦。\n", me);
		return 1;
	}
	return command("jingzuo "+arg);
}
