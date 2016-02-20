// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "桃花丛");
set("long", @LONG
    这是一片烂漫的桃花丛，满山遍野的桃树枝上，开着桃红的桃
花。桃花上头，飞满了细细嗡嗡的不甘寂寞的蜜蜂。脚下是一条不
宽也不窄的林间小道，道边是密密丛丛的嫩草和争奇斗艳的小花。
LONG
);
        set("exits", ([
		"south" : "/d/taohuacun/taohua6.c",
		]));
	set("objects", ([
       		]) );
	set("owner", "xuanyuan");
	set("class", "海洋银行　");
	set("valid_startroom",1);
	set("no_fight",1);

setup();
}
void init()
{
	add_action("do_invite","invite");
	//add_action("do_setowner","setowner");
}
int valid_enter(object me)
{
	int flag;
// always let owner go in:
	 if((string)me->query("class") != (string)query("class")
	&&(string)query("invite") != (string)me->query("id")
	&&(string)me->query("id") != (string)query("owner"))
	return 1;	

}
int do_invite(string arg)
{
	object me;
	me= this_player();
	if((string)me->query("id") != (string)query("owner"))
	return 0;
	set("invite",arg);
	write("你邀请"+arg+"来你的房间。\n");
	return 1;
}

/*int do_setowner(string arg)
{
	string oldowner;
	oldowner = (string)query("owner");
	set("owner",arg);
	write("你将房间的主人暂时设为"+arg+"。\n");
	call_out("set_back",60, oldowner);
	return 1;
}

int set_back(string oldowner)
{
	set("owner", oldowner);
	return 1;
}
*/