//Cracked by Roath
// Room: /d/xingxiu/xxcave.c

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
黑黝黝的山洞里，有一股腥臭味。等眼睛适应了这里的弱光后，才发现地
上有许多白惨惨的骨骇(skeleton)，令人胆寒。这时你听到山洞深处传来嘶嘶
沙沙的声音，好象有什么东西在向你悄悄移来。
LONG
        );
        set("exits", ([
  "southeast" : __DIR__"xxroad10",
]));

        set("objects", ([
		"/d/xingxiu/npc/jumang" : 1,
        ]) );


        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 1);
        setup();
        //replace_program(ROOM);
}
void init()
{
        add_action("do_move","move");
}
 int do_move(string arg)
{
        object ob, me = this_player();
	if( !arg || arg=="" ) return 0;
	if( arg=="skeleton" ) {
                ob = new("/d/xingxiu/obj/yaobo");
	if (!ob)
		return notify_fail("你挪开骸骨，发现这里似乎有人来过了。\n");

                ob->move("/d/xingxiu/xxcave");
        message("vision","你挪开一具骸骨，发现下面藏着一只蓝玉钵！\n", me);
	return 1;
	}
}
