//Cracked by Roath
// qianfo.c 千佛庵(洪椿坪)
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "千佛庵");
	set("long", @LONG
此处是洪椿坪千佛庵。山间小坪坝，四面层峦叠障，峰环岭护；两侧深谷
幽岚，溪涧玲叮。坪上古木扶疏，亭亭如盖，山阴沁透，白雾飘游，极为幽静
清凉。此处常见雨雾霏霏，林中迷迷蒙蒙，乃山中雾气所为。正所谓「山行本
无雨，空翠湿人衣」。这就是誉为奇观的「洪椿晓雨」。此处殿美景幽，气象
新异，令人心醉。沿途南上是「九十九道拐」，北下经黑龙江栈道至清音阁。
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"dao99",
		"north" : __DIR__"zhandao2",
		"enter" : __DIR__"qianfo1",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "southwest" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(5));
                write("你沿九十九道拐向上爬了一阵，觉得好累。\n");
        }

        else if (dir == "southwest" && current_jingli <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}
