//Cracked by Roath
// hz_front.c 华藏庵正殿
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "华藏庵正殿");
	set("long", @LONG
这里是峨嵋山金顶华藏庵的正殿。华藏庵规模宏大，殿内青砖铺地，中间
有普贤菩萨像，两旁列有万佛。正前方放一红木供桌，陈列香烛，以供叩拜。
自此左右各有一间侧殿，是接待香客的地方。南面是通往一个大广场，只有峨
嵋弟子才能过去。
LONG
	);
	set("exits", ([
		"out" : __DIR__"huazang",
		"east" : __DIR__"hz_east",
		"west" : __DIR__"hz_west",
		"south" : __DIR__"hz_guangchang",
	]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        set("objects",([
                __DIR__"npc/xiang-ke" : 1,
                CLASS_D("emei") + "/jingxin" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
//	replace_program(ROOM);

}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "峨嵋派") && dir == "south"  &&
                objectp(present("jingxin shitai", environment(me))))
           return notify_fail("静心师太走上前说：后边是峨嵋弟子练功休息的地方，请留步。\n");

        return ::valid_leave(me, dir);
}


