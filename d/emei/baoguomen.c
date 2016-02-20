//Cracked by Roath
// baoguomen.c 保国寺山门
// Shan: 96/09/29

inherit ROOM;

void create()
{
        set("short", "报国寺山门");
        set("long", @LONG
报国寺为峨嵋出入之门户。山门(gate)上有一块大匾。寺外苍楠环卫，翠
柏掩映。由此一路向西上开始登峨嵋山，北面下山是一条弯弯的石阶路。
LONG
        );
        set("exits", ([
                "west" : __DIR__"baoguo",
                "northdown" : __DIR__"shijie1",
        ]));

        set("objects", ([
                __DIR__"npc/xiang-ke.c": 1,
        ]) );

	set("outdoors", "emei");
        set("item_desc",([
            "gate"       :
"	\n"
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌　　　报　　国　　寺　　　≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"
        ]));

        set("valid_startroom", 1);

	set("cost", 0);
        setup();
//      "/clone/board/emei1_b"->foo();

}

// To check and record emei dizi's shen every time she/he leaves emei.

int valid_leave(object me, string dir)
{
//        int current_shen;

//        current_shen = me->query("shen");
        if (dir == "northdown" && me->query("family/family_name") == "峨嵋派")
        {
//                me->set("emei_shen",current_shen);
		if (me->query("gender") == "女性")
		{
                	write("守寺弟子向你挥了挥手道：师姐早回，在外边行事要小心，不要回来被师父责骂。\n");
		}
		else
		{
			write("守寺弟子向你挥了挥手道：师兄早回，在外边行事要小心，不要回来被师父责骂。\n");
                }
        }

        return ::valid_leave(me, dir);
}

