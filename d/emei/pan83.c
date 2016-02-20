//Cracked by Roath
// pan83.c 八十四盘
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "八十四盘");
	set("long", @LONG
八十四盘，道路艰险陡峭，迂回盘折，令人不能喘息。路左是蔽日遮天的
冷杉林，路右是深不见底的绝壁峡谷。由此往上至接引殿，北下到洗象池。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"pan84",
		"southup" : __DIR__"pan82",
		"east" : __DIR__"lenshan3",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 4);
	setup();
//	replace_program(ROOM);

}
int valid_leave(object me, string dir)
{
                int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "southup" && current_jingli >15)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(10));
                write("你爬上八十四盘，有些累了。\n");
        }

        else if (dir == "southup" && current_jingli <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

