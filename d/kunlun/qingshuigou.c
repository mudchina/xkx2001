//Cracked by Roath
// room: /mingjiao/qingshuigou.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "清水沟");
        set("long", @LONG
这里是群山间的一道深沟，正中是一条水道，干枯已久。仰头一望，
只能见到窄窄的天空。四周悄无声息，行走时脚步声清晰可辨。偶尔一群
燕雀飞过，翅膀煽动、呼朋引伴之声不绝于耳，却更增添了寂静。
LONG );

        set("exits", ([
                "northeast" : __DIR__"daqing",
                "southwest" : __DIR__"longquangu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/water", 1);
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}