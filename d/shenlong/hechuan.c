//Cracked by Roath
// Room: /d/shenlong/hechuan.c
// by aln 10 / 97

inherit ROOM;

void create()
{
        set("short", "河船");
        set("long", @LONG
这是一艘装饰华丽的河船，舱中布置得尤如名门闺房。你走了其中
便是到了苗家一般，不油得暗暗惊讶不已。四周迷漫着奇异药气，你感  
觉四肢发软双眼浑浊。
LONG
        );
        set("exits", ([
                "out" : "/d/forest/bank2",
        ]));

        set("objects", ([
                "/d/shenlong/npc/langu" : 1,
        ]));

        set("invalid_startroom", 1);
        set("outdoors", "forest");
        set("cost", 2);
        setup();
}

void init()
{
        object me = this_player();
        int lose, period, lvl;

        if( interactive(me = this_player()) ) {
                if( lvl =  me->query_skill("force", 1) > 149 ) return;

                write("糟糕！你中毒了！你一提气便觉艰难。\n");
                lose = 140 - lvl;
                if( lose < 0 ) lose = 0;
                lose += 10;

                me->add_temp("apply/damage", -lose);
                me->add_temp("apply/attack", -lose);
                me->add_temp("apply/dodge", -lose);

                period = 1000 / (5 + me->query_skill("force", 1));
                if( period < 1 ) period = 1;
                period += random(period);

                call_out("recover", period, me, lose); }
}
        
void recover(object me, int lose)
{
         me->add_temp("apply/damage", lose);
         me->add_temp("apply/attack", lose);
         me->add_temp("apply/dodge", lose);
         write("你运功片刻，终于将余毒逼出感到全身舒坦。\n");
}
