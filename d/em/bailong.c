//Cracked by Roath
// bailong.c 白龙洞
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "白龙洞");
	set("long", @LONG
白龙洞据说是《白蛇传》中的白娘子修炼成仙之处。这里楠木参天，林荫
夹道，株株秀挺俊拔，枝叶分披上捧，如两手拥佛，传为古时一高僧按《法华
经》口诵一字，植树一株，共植六万九千七百七十七株，时称古德林。这里北
上至万年庵，南下是清音阁。
LONG
	);
	set("exits", ([
		"northup" : __DIR__"wannian",
		"southeast" : __DIR__"qingyin",
		"east"    : __DIR__"meihua"+(3*random(2)+1),
		"west"    : __DIR__"meihua"+(3*random(2)+1),
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 2);
	setup();
	replace_program(ROOM);

}
