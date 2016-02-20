//Cracked by Roath
// /d/emei/qianfo1.c 千佛庵大殿
// Shan: 96/07/10

inherit ROOM;

void create()
{
        set("short", "千佛庵大殿");
	set("long", @LONG
千佛庵殿宇高广宏阔，清洁庄严。庵内有一具七万千佛莲灯，有纹龙七条
环于灯体，并有佛像数百周匝排列，雕缕精致无比。
LONG
	);
	set("exits", ([
		"out" : __DIR__"qianfo",
		"east": __DIR__"chanfang_qf",
	]));

        set("objects",([
                __DIR__"npc/wenyin" : 1,
                CLASS_D("emei") + "/jinghui" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

