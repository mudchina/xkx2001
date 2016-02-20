//Cracked by Kafei
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIW"工作室"NOR);
        set("long", @LONG

	baituo	白驼山 		yuelao	月老亭 		dali	大理国
	emei	峨嵋山 		gaibang	丐帮 		gbr	丐帮报告 	
	huashan	华山 		kedian	扬州客店 	xueshan	雪山 		
	leitai	擂台 		prog	进度表 		shaolin	少林寺 		
	shenlong神龙岛 		towiz	会客厅 		wiz	巫师 		
	wudang	武当山 		wuguan	泉州武馆 	wumiao	武庙 		
	xingxiu	星宿海 		xuanjie	玄劫教		taohua  桃花

LONG );
        set("valid_startroom",1);
	set("exits", ([
		"taohua": "/d/taohua/jingshe",
		"baituo": "/d/xingxiu/btyard",
		"yuelao": "/d/city/yuelao",
		"dali": "/d/dali/wangfu1",
		"emei": "/d/emei/hz_guangchang",
		"gaibang": "/d/gaibang/undertre",
		"gbr": "/d/gaibang/gbxiaowu",
		"huashan": "/d/huashan/pianting",
		"kedian": "/d/city/kedian",
		"xueshan": "/d/xueshan/guangchang",
		"leitai": "/u/xuy/bwdh/leitai",
		"prog": "/d/wizard/meeting_room",
		"shaolin": "/d/shaolin/guangchang1",
		"shenlong": "/d/shenlong/tingkou",
		"towiz": "/d/wizard/guest_room",
		"wiz": "/d/wizard/wizard_room",
		"wudang": "/d/wudang/sanqingdian",
		"wuguan": "/d/quanzhou/qianting",
		"wumiao": "/d/city/wumiao",
		"xingxiu": "/d/xingxiu/xxh2",
		"guiyun": "/d/taihu/qianyuan",
		"xuanjie": "/d/qilian/datang",
        ]));

//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if ( !wizardp(me) && (dir == "wiz" || dir == "prog") )
                return notify_fail("不是巫师，不准去！\n");
        return ::valid_leave(me, dir);
}
