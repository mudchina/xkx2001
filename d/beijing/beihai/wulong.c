//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "五龙亭");
	set("long", @LONG
这里是阐福寺前之五龙亭，亭子伸入水中，五亭俱为方形，前后错落布置。
中亭名龙泽，重檐下方上恩赐，左面澄祥亭为重檐，滋香亭为单檐；右面涌瑞
亭，浮翠亭与左面相同。五亭皆绿琉璃瓦顶，黄瓦剪边，檐下梁枋施小点金旋
子彩画，绚丽多彩。
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "west" : __DIR__"xiaolu2",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
